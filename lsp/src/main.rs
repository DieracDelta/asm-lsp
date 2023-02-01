use std::collections::HashMap;
use std::{env, io, path::PathBuf, sync::Once};

pub mod utils;

use dashmap::DashMap;
use nll::nll_todo::nll_todo;
use ropey::{Error, Rope};
use tokio::sync::RwLock;
pub type JsonResult<T> = tower_lsp::jsonrpc::Result<T>;
use tower_lsp::jsonrpc::ErrorCode;
use tower_lsp::lsp_types::*;
use tower_lsp::{Client, LanguageServer, LspService, Server};

use snafu::{ResultExt, Snafu, Whatever};
use tracing::{error, info};
use tree_sitter::{InputEdit, Point, Tree};
use tree_sitter::{Language, LanguageError, Parser};
use tree_sitter_riscvasm::NODE_TYPES;

type ByteIndex = usize;

type CharIndex = usize;

fn count_newlines(s: &str) -> usize {
    s.as_bytes().iter().filter(|&&c| c == b'\n').count()
}

pub fn position_info(position: Position, rope: &Rope) -> Result<(CharIndex, ByteIndex), Error> {
    let line_char_offset = rope.try_line_to_char(position.line as usize)?;
    let total_char_offset = line_char_offset + position.character as usize;
    rope.try_char_to_byte(total_char_offset)
        .map(|x| (total_char_offset, x))
}

struct Backend {
    client: Client,
    // TODO dunno if this actually needs to be locked
    // should probably be a cell..
    parser: RwLock<Parser>,
    // filename -. (rope of text, parsed text)
    document_map: DashMap<String, (Rope, Tree)>,
    // semantic_token_map: DashMap<String, Vec<>>,
}

impl Backend {
    async fn create_new(&self, uri: String, doc: String) {
        let rope = Rope::from_str(&doc);
        let tree = self.parser.write().await.parse(doc, None);
        if let Some(tree) = tree {
            // tree.edit(edit)
            self.document_map
                .insert(uri.to_string(), (rope.clone(), tree.clone()));
            // TODO now what that we have parsed? Probably want to return error of some sort. Also
            // do semantic check pass (or cached version)
        } else {
            self.client
                .show_message(
                    MessageType::ERROR,
                    format!("INTERNAL ERROR: was unable to determine language or timed out"),
                )
                .await;
        }
    }

    async fn on_change(&self, uri: String, ie @ InputEdit { .. }: InputEdit) {
        if let Some(mut doc) = self.document_map.get_mut(&uri) {
            // by defn this is cheap
            let rope = &mut doc.0.clone();
            let ast = &mut doc.1;
            let mut parser = self.parser.write().await;
            Tree::edit(ast, &ie);
            let tree = parser.parse_with(
                &mut |offset, _position| {
                    // logn time, not bad
                    // allowd to return 0
                    let (chunk, chunk_byte_idx, _, _) = rope.chunk_at_byte(offset);
                    &chunk.as_bytes()[offset - chunk_byte_idx..]
                },
                Some(&doc.1),
            );

            if let Some(tree) = tree {
                doc.1 = tree;
            } else {
                self.client
                    .show_message(
                        MessageType::ERROR,
                        format!("INTERNAL ERROR: FAILED TO PARSE"),
                    )
                    .await;
            }
        } else {
            self.client
                .show_message(
                    MessageType::ERROR,
                    format!("INTERNAL ERROR: COULDNT FIND TREE DESPITE HAVING OPENED"),
                )
                .await;
        }
        // let rope = ropey::Rope::from_str(&params.text);
        // // TODO should probably use the old_tree
        // let tree = self.parser.write().await.parse(params.text, None);
        // if let Some(tree) = tree {
        //     // tree.edit(edit)
        //     self.document_map
        //         .insert(params.uri.to_string(), (rope.clone(), tree.clone()));
        //     // let (ast, errors, semantic_tokens) = parse(&params.text);
        //     todo()
        // } else {
        //     self.client
        //         .show_message(
        //             MessageType::ERROR,
        //             format!("INTERNAL ERROR: was unable to determine language or timed out"),
        //         )
        //         .await;
        // }
    }
}

//

#[derive(Debug, Snafu)]
pub enum LspError {
    IoError { source: io::Error },
    LanguageError { source: LanguageError },
}

#[tower_lsp::async_trait]
impl LanguageServer for Backend {
    async fn initialize(&self, _: InitializeParams) -> JsonResult<InitializeResult> {
        Ok(InitializeResult {
            capabilities: ServerCapabilities {
                text_document_sync: Some(TextDocumentSyncCapability::Options(
                    TextDocumentSyncOptions {
                        open_close: Some(true),
                        change: Some(TextDocumentSyncKind::INCREMENTAL),
                        ..Default::default()
                    },
                )),
                hover_provider: Some(HoverProviderCapability::Simple(true)),
                completion_provider: Some(CompletionOptions {
                    resolve_provider: Some(true),
                    trigger_characters: None,
                    all_commit_characters: None,
                    work_done_progress_options: WorkDoneProgressOptions {
                        work_done_progress: None,
                    },
                }),
                ..ServerCapabilities::default()
            },
            server_info: Some(ServerInfo {
                name: "Asm Language Server".to_string(),
                version: Some("0.1".to_string()),
            }),
        })
    }

    //LSP[efm] OPENED change: DidOpenTextDocumentParams { text_document: TextDocumentItem { uri: Url { scheme: "file", cannot_be_a_base: false, username: "", password: None, host: None, port: No
    // ne, path: "/Users/jrestivo/dev/tree-sitter/tree-sitter-riscv-asm/example_files/example.S", query: None, fragment: None }, language_id: "asm", version: 0, text: "hello\nhello\nhi\nhello\nhi
    // \n" } }
    async fn did_open(&self, params: DidOpenTextDocumentParams) {
        self.client
            .show_message(MessageType::ERROR, "file opened!")
            .await;

        self.create_new(
            params.text_document.uri.to_string(),
            params.text_document.text,
        )
        .await;
    }

    async fn did_change(&self, mut params: DidChangeTextDocumentParams) {
        self.client
            .show_message(MessageType::ERROR, format!("DID change: {:?}", params))
            .await;

        let uri = params.text_document.uri.as_str();

        let Some(mut doc) =  self.document_map.get_mut(uri)
        else {
            self.client
                .show_message(MessageType::ERROR, format!("Couldn't find URI {uri}"))
                .await;
            return;
        };

        let rope = &mut doc.0;

        if let Some(change) = params.content_changes.pop() {
            if let Some(range) = change.range {
                // FIXME bad error handling. Do it better.
                let (start_char, start_byte) = position_info(range.start, &rope).unwrap();
                let (old_end_char, old_end_byte) = position_info(range.end, &rope).unwrap();

                // TODO should this be +1?
                // TODO write tests for this ffs
                rope.try_remove(start_char..old_end_char).unwrap();
                let len_chars = rope.len_chars();
                let len_bytes = rope.len_bytes();
                rope.try_insert(start_char, &change.text).unwrap();
                let added_chars = rope.len_chars() - len_chars;
                let added_bytes = rope.len_bytes() - len_bytes;

                // FIXME possible OBOB
                let new_end_byte = start_byte + added_bytes;
                let new_end_line = rope.try_byte_to_line(new_end_byte).unwrap();
                let new_end_col =
                    start_char + len_chars - rope.try_line_to_char(new_end_line).unwrap();

                let edit = InputEdit {
                    start_byte,
                    old_end_byte,
                    new_end_byte,
                    start_position: Point {
                        // ok this is probably broken on 32 bit machines
                        // That's ok, I don't really mind
                        row: range.start.line as usize,
                        column: range.start.character as usize,
                    },
                    old_end_position: Point {
                        row: range.end.line as usize,
                        column: range.end.character as usize,
                    },
                    new_end_position: {
                        Point {
                            row: new_end_line,
                            column: new_end_col,
                        }
                    },
                };

                let ast = &mut doc.1;
                Tree::edit(ast, &edit);
                let mut parser = self.parser.write().await;

                let rope = &doc.0;

                let tree = parser.parse_with(
                    &mut |offset, _position| {
                        // logn time, not bad
                        // allowd to return 0
                        let (chunk, chunk_byte_idx, _, _) = rope.chunk_at_byte(offset);
                        &chunk.as_bytes()[offset - chunk_byte_idx..]
                    },
                    Some(&doc.1),
                );

                if let Some(tree) = tree {
                    doc.1 = tree;
                } else {
                    self.client
                        .show_message(
                            MessageType::ERROR,
                            format!("INTERNAL ERROR: FAILED TO PARSE"),
                        )
                        .await;
                }
            }
        }
    }

    // async fn did_change(&self, mut params: DidChangeTextDocumentParams) {
    //     self.client
    //         .show_message(MessageType::ERROR, format!("DID change: {:?}", params))
    //         .await;
    //
    //     if let Some(change) = params.content_changes.pop() {
    //          let edit =
    //              if let Some(range) = change.range {
    //                  // TODO this is gonna need to be merged...
    //                  let Some(mut doc) = self.document_map.get_mut(params.text_document.uri.as_str().clone())
    //                  else {
    //                      return;
    //                  };
    //
    //                  let _ = doc.0.try_line_to_byte(range.start.line as usize);
    //                  let _ = doc.0.try_line_to_char(range.start.line as usize);
    //                  /// append chars
    //                  /// construct end position
    //
    //
    //                  InputEdit {
    //                      start_byte: nll_todo(),
    //                      old_end_byte: nll_todo(),
    //                      new_end_byte: nll_todo(),
    //                      start_position:
    //                          Point {
    //                              // ok this is probably broken on 32 bit machines
    //                              // That's ok, I don't really mind
    //                              row: range.start.line as usize,
    //                              column: range.start.character as usize
    //                          },
    //                      old_end_position:
    //                          Point {
    //                              row: range.end.line as usize,
    //                              column: range.end.character as usize
    //                      },
    //                      new_end_position:
    //                      {
    //                          let start = range.start.line as usize;
    //                          let num_additional_lines = count_newlines(&change.text);
    //                          let column =
    //                              if num_additional_lines == 0 {
    //                                  range.start.character as usize + change.text.len()
    //                              } else {
    //                                  change.text.len() - (2 + change.text.rfind("\n").unwrap())
    //                              };
    //                          Point {
    //                              row: start + num_additional_lines,
    //                              column
    //                          }
    //                      }
    //                  }
    //              } else {
    //                  InputEdit {
    //                      start_byte: 0,
    //                      old_end_byte: 0,
    //                      new_end_byte: change.text.bytes().len(),
    //                      start_position: Point {
    //                          row: 0,
    //                          column: 0,
    //                      },
    //                      old_end_position: Point {
    //                          row:0,
    //                          column:0
    //                      },
    //                      new_end_position: Point {
    //                          row: 0,
    //                          column: 0,
    //                      }
    //                  }
    //              };
    //     }
    //
    //     // let edits: Vec<InputEdit> = Vec::new();
    //
    //     // for change in params.content_changes {
    //     //     let change_len = change.text.len();
    //     //     let change_len_bytes = change.text.bytes().len();
    //     // }
    //
    //
    //     // for change in params.content_changes {
    //     //     let change_len = change.text.len();
    //     //     let change_len_bytes = change.text.bytes().len();
    //     //     let edit =
    //     //         if let Some(change) = change.range {
    //     //             let edit = InputEdit {
    //     //                 start_byte: nll_todo(),
    //     //                 old_end_byte: nll_todo(),
    //     //                 new_end_byte: nll_todo(),
    //     //                 start_position: nll_todo(),
    //     //                 old_end_position: nll_todo(),
    //     //                 new_end_position: nll_todo()
    //     //             };
    //     //
    //     //         } else {
    //     //             let edit = InputEdit {
    //     //                 start_byte: 0,
    //     //                 old_end_byte: 0,
    //     //                 new_end_byte: change_len_bytes,
    //     //                 start_position: Point {
    //     //                     row: 0,
    //     //                     column: 0,
    //     //                 },
    //     //                 old_end_position: Point {
    //     //                     row:0,
    //     //                     column:0
    //     //                 },
    //     //                 new_end_position: Point {
    //     //                     row: 0,
    //     //                     column: 0,
    //     //                 }
    //     //             };
    //     //
    //     //         };
    //     //
    //
    //     // self.on_change(TextDocumentItem {
    //     //     language_id: "none".to_string(),
    //     //     uri: params.text_document.uri,
    //     //     text: params.content_changes.pop(),
    //     //     version: params.text_document.version,
    //     // })
    //     // .await
    //
    //     // }
    // }

    async fn completion(&self, params: CompletionParams) -> JsonResult<Option<CompletionResponse>> {
        let uri = params.text_document_position.text_document.uri;
        let position = params.text_document_position.position;
        let completions = || -> Option<Vec<CompletionItem>> {
            // step 1: get the token line
            // step 2: get token itself
            // step 3: is it an operator? Or an operand?
            // step 4: match against lookup table
            // let rope = self.document_map.get(&uri.to_string())?;
            Some(vec![])
        }();
        Ok(completions.map(CompletionResponse::Array))
    }

    async fn hover(&self, params: HoverParams) -> JsonResult<Option<Hover>> {
        let uri = params.text_document_position_params.text_document.uri;
        let position = params.text_document_position_params.position;

        let Some(mut doc) =  self.document_map.get_mut(uri)
        else {
            self.client
                .show_message(MessageType::ERROR, format!("Couldn't find URI {uri}"))
                .await;
            return Err(tower_lsp::jsonrpc::Error::new(ErrorCode::ParseError));
        };



        // TODO drop this. It's filler to show how easy hover is.
        let markdown = MarkupContent {
            kind: MarkupKind::Markdown,
            value: [
                "# Hello header",
                "Hello world",
                "```typescript",
                "someCode();",
                "```",
            ]
            .join("\n"),
        };
        Ok(Some(Hover {
            contents: HoverContents::Markup(markdown),
            range: None,
        }))
    }

    async fn initialized(&self, _: InitializedParams) {
        self.client
            .show_message(MessageType::ERROR, "Server initialized!")
            .await;
    }

    async fn shutdown(&self) -> JsonResult<()> {
        Ok(())
    }
}

#[tokio::main(flavor = "multi_thread", worker_threads = 10)]
async fn main() -> Result<(), LspError> {
    tracing_subscriber::fmt().try_init().unwrap();

    let stdin = tokio::io::stdin();
    let stdout = tokio::io::stdout();

    let language = tree_sitter_riscvasm::language();
    let mut parser = Parser::new();
    parser.set_language(language).context(LanguageSnafu)?;

    let (service, socket) = LspService::build(|client| Backend {
        client,
        parser: RwLock::new(parser),
        document_map: DashMap::new(),
    })
    .finish();
    error!("BEFORE WOO");
    Server::new(stdin, stdout, socket).serve(service).await;
    error!("WOO");

    Ok(())
}

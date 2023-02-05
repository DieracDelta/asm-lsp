use std::collections::HashMap;
use std::{env, io, path::PathBuf, sync::Once};

pub mod doc;
pub mod utils;

use dashmap::DashMap;
use nll::nll_todo::nll_todo;
use ropey::{Error, Rope};
use tokio::sync::RwLock;
pub type JsonResult<T> = tower_lsp::jsonrpc::Result<T>;
use tower_lsp::jsonrpc::ErrorCode;
use tower_lsp::lsp_types::*;
use tower_lsp::{Client, LanguageServer, LspService, Server};

use doc::doc_node;

use snafu::{ResultExt, Snafu, Whatever};
use tracing::{error, info};
use tree_sitter::{InputEdit, Point, Tree, TreeCursor};
use tree_sitter::{Language, LanguageError, Parser};
use tree_sitter_riscvasm::NODE_TYPES;
use utils::{position_info, position_to_point};

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
}

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
        let uri = params.text_document.uri.as_str();

        // TODO this is how to create an error (and other diagnostics)
        // let diags = vec![
        //     Diagnostic::new_simple(Range::new(Position {line: 4, character: 1}, Position { line: 4, character: 5}), "hello world error".to_string()),
        // ];
        // self.client.publish_diagnostics(params.text_document.uri.clone(), diags, None).await;

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
                    start_position: position_to_point(range.start),
                    old_end_position: position_to_point(range.end),
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
        let uri = params
            .text_document_position_params
            .text_document
            .uri
            .to_string();
        let position = params.text_document_position_params.position;

        let Some(doc) =  self.document_map.get_mut(&uri)
        else {
            self.client
                .show_message(MessageType::ERROR, format!("Couldn't find URI {uri}"))
                .await;
            return Err(tower_lsp::jsonrpc::Error::new(ErrorCode::ParseError));
        };

        let mut cursor = doc.1.walk();

        let point = position_to_point(position);

        let _ = cursor.goto_first_child_for_point(point);

        let (docs, _cursor) = doc_node(&mut cursor, &point);

        // let node_kinds = walk_node_kinds(&mut cursor, &position_to_point(position));

        let markdown = MarkupContent {
            kind: MarkupKind::Markdown,
            value: docs,
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

pub fn walk_node_kinds(cursor: &mut TreeCursor, p: &Point) -> Vec<String> {
    let cur_node = cursor.node();
    let mut kinds = Vec::new();
    while let Some(_) = cursor.goto_first_child_for_point(p.clone()) {
        kinds.push(cursor.node().kind().to_string());
    }
    kinds
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
    Server::new(stdin, stdout, socket).serve(service).await;

    Ok(())
}

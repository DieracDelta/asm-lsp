use std::collections::HashMap;
use std::{env, io, path::PathBuf, sync::Once};

mod utils;

use dashmap::DashMap;
use ropey::Rope;
use utils::todo;
pub type JsonResult<T> = tower_lsp::jsonrpc::Result<T>;
use tower_lsp::lsp_types::*;
use tower_lsp::{Client, LanguageServer, LspService, Server};

use snafu::{ResultExt, Snafu, Whatever};
use tracing::{error, info};
use tree_sitter::Tree;
use tree_sitter::{Language, LanguageError, Parser};
use tree_sitter_riscvasm::NODE_TYPES;

struct Backend {
    client: Client,
    parser: Parser,
    // ast_map: DashMap<String, HashMap<String, Func>>,
    // filename to rope
    document_map: DashMap<String, Rope>,
    // semantic_token_map: DashMap<String, Vec<>>,
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

    async fn completion(&self, params: CompletionParams) -> JsonResult<Option<CompletionResponse>> {
        let uri = params.text_document_position.text_document.uri;
        let position = params.text_document_position.position;
        let completions = || -> Option<Vec<CompletionItem>> {
            // let rope = self.document_map.get(&uri.to_string())?;
            Some(vec![])
        }();
        Ok(completions.map(CompletionResponse::Array))
    }

    async fn hover(&self, params: HoverParams) -> JsonResult<Option<Hover>> {
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
            .log_message(MessageType::INFO, "Server initialized!")
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
        parser,
        document_map: DashMap::new(),
    })
    .finish();
    error!("BEFORE WOO");
    Server::new(stdin, stdout, socket).serve(service).await;
    error!("WOO");

    Ok(())
}

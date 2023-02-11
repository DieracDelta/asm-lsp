use nll::nll_todo::nll_todo;
use ropey::Rope;
use tower_lsp::lsp_types::CompletionItem;
use tree_sitter::{TreeCursor, Point};

use crate::doc::{SyntaxNode, };

pub fn complete_node<'a: 'b, 'b>(cursor: &'b mut TreeCursor<'a>, point: &Point, src: &Rope) -> (Vec<CompletionItem>, &'b mut TreeCursor<'a>) {
    let node = cursor.node();
    match SyntaxNode::try_from(node.kind()) {
        Ok(node_kind) => match node_kind {
            SyntaxNode::Constant => {
                (vec![], cursor)
            }
            SyntaxNode::ConstantHex => (vec![], cursor),
            SyntaxNode::ConstantDec => (vec![], cursor),
            SyntaxNode::Directive => (vec![], cursor),
            SyntaxNode::DirectiveArg => (vec![], cursor),
            // TODO combine these brancnes if they're going to
            // continue to have the same logic
            SyntaxNode::Instruction => {
                let result = cursor.goto_first_child_for_point(*point);
                assert!(result.is_some());
                complete_node(cursor, point, src)
            }
            SyntaxNode::Operand => {
                let result = cursor.goto_first_child_for_point(*point);
                assert!(result.is_some());
                complete_node(cursor, point, src)
            }
            SyntaxNode::OperandNoParens => {
                let result = cursor.goto_first_child_for_point(*point);
                assert!(result.is_some());
                complete_node(cursor, point, src)
            }
            SyntaxNode::OperandParens => {
                let result = cursor.goto_first_child_for_point(*point);
                assert!(result.is_some());
                complete_node(cursor, point, src)
            }
            SyntaxNode::RelocSymbol => (vec![], cursor),
            SyntaxNode::Relocation => (vec![], cursor),
            SyntaxNode::SourceFile => (vec![], cursor),
            SyntaxNode::Comment => (vec![], cursor),
            SyntaxNode::DirectiveId => (vec![], cursor),
            SyntaxNode::Identifier => {
                // error!?
                // let range = node.byte_range();
                // let identifier = src.byte_slice(range);
                // let mut result =
                //     format!("# Register\n\tUnknown register {identifier:?} \n ").to_string();
                //
                // if !node.has_error() {
                //     if let Some(register) = get_rv32i_map().get(&identifier.to_string()) {
                //         result = format!("{}", register);
                //     }
                // }
                (vec![], cursor)
            }
            SyntaxNode::InstrId => (vec![], cursor),
            SyntaxNode::Label => (vec![], cursor),
        },
        Err(err) => (vec![], cursor),
    }
    // (vec![
    //     CompletionItem {
    //         insert_text_mode: None,
    //         tags: None,
    //         label: "hello".to_string(),
    //         kind: None,
    //         detail: None,
    //         documentation: None,
    //         deprecated: None,
    //         preselect: None,
    //         sort_text: None,
    //         filter_text: None,
    //         insert_text: Some("Yeet!".to_string()),
    //         insert_text_format: None,
    //         text_edit: None,
    //         additional_text_edits: None,
    //         commit_characters: None,
    //         command: None,
    //         data: None,
    //     },
    // ], cursor)
}


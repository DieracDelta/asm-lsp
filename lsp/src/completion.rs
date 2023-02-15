use nll::nll_todo::nll_todo;
use ropey::Rope;
use tower_lsp::lsp_types::{
    CompletionItem, CompletionItemKind, Documentation, MarkupContent, MarkupKind,
};
use tracing::error;
use tree_sitter::{Point, TreeCursor};

use crate::doc::{SyntaxNode, RV32I_INSTRUCTIONS, RV32I_INSTRUCTION_MAP};

pub fn complete_node<'a: 'b, 'b>(
    cursor: &'b mut TreeCursor<'a>,
    point: &Point,
    src: &Rope,
) -> (Vec<CompletionItem>, &'b mut TreeCursor<'a>) {
    let node = cursor.node();
    match SyntaxNode::try_from(node.kind()) {
        Ok(node_kind) => match node_kind {
            SyntaxNode::Constant => (vec![], cursor),
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
            SyntaxNode::InstrId => {
                let range = node.byte_range();
                let identifier = src.byte_slice(range).to_string();
                error!("identifier: {:?}", identifier);
                let completion_itmes = get_instr_id_completions(identifier);
                (completion_itmes, cursor)
            }
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

fn get_instr_id_completions(partial_identifier: String) -> Vec<CompletionItem> {
    let instructions = RV32I_INSTRUCTIONS
        .iter()
        .filter(|i| i.name.starts_with(&partial_identifier));

    let mut completions = Vec::new();

    for instruction in instructions {
        completions.push(CompletionItem {
            insert_text_mode: None,
            tags: None,
            label: instruction.name.clone(),
            kind: Some(CompletionItemKind::FUNCTION),
            detail: Some(instruction.get_fn_sig()),
            documentation: Some(Documentation::MarkupContent(MarkupContent {
                kind: MarkupKind::Markdown,
                value: instruction.docs.clone(),
            })),
            deprecated: None,
            preselect: None,
            sort_text: None,
            filter_text: None,
            insert_text: Some(instruction.name.clone()),
            insert_text_format: None,
            text_edit: None,
            additional_text_edits: None,
            commit_characters: None,
            command: None,
            data: None,
        });
    }

    completions
}

mod tests {
    use super::*;

    #[test]
    pub fn test_completions() {
        let mut completions = get_instr_id_completions("csr".to_string());
        let instruction = &RV32I_INSTRUCTION_MAP["csrrw"];
        assert_eq!(completions.len(), 1);
        assert_eq!(
            completions.pop().unwrap(),
            CompletionItem {
                insert_text_mode: None,
                tags: None,
                label: "csrrw".to_string(),
                kind: Some(CompletionItemKind::FUNCTION),
                detail: Some(instruction.get_fn_sig()),
                documentation: Some(Documentation::MarkupContent(MarkupContent {
                    kind: MarkupKind::Markdown,
                    value: instruction.docs.clone(),
                })),
                deprecated: None,
                preselect: None,
                sort_text: None,
                filter_text: None,
                insert_text: Some(instruction.name.clone()),
                insert_text_format: None,
                text_edit: None,
                additional_text_edits: None,
                commit_characters: None,
                command: None,
                data: None,
            }
        );
    }
}

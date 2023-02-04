use nll::nll_todo::nll_todo;
use tree_sitter::{Point, TreeCursor};

pub enum SyntaxNode {
    Constant,
    ConstantHex,
    Directive,
    DirectiveArg,
    Instruction,
    Operand,
    OperandNoParens,
    OperandParens,
    RelocSymbol,
    Relocation,
    SourceFile,
    Comment,
    ConstantDec,
    DirectiveId,
    Identifier,
    InstrId,
    Label,
}

impl TryFrom<&str> for SyntaxNode {
    // I'm really being lazy here
    type Error = String;

    fn try_from(value: &str) -> Result<Self, Self::Error> {
        match value {
            "constant" => Ok(SyntaxNode::Constant),
            "constant_hex" => Ok(SyntaxNode::ConstantHex),
            "directive" => Ok(SyntaxNode::Directive),
            "directive_arg" => Ok(SyntaxNode::DirectiveArg),
            "instruction" => Ok(SyntaxNode::Instruction),
            "operand" => Ok(SyntaxNode::Operand),
            "operand_no_parens" => Ok(SyntaxNode::OperandNoParens),
            "operand_parens" => Ok(SyntaxNode::OperandParens),
            "reloc_symbol" => Ok(SyntaxNode::RelocSymbol),
            "relocation" => Ok(SyntaxNode::Relocation),
            "source_file" => Ok(SyntaxNode::SourceFile),
            "comment" => Ok(SyntaxNode::Comment),
            "constant_dec" => Ok(SyntaxNode::ConstantDec),
            "directive_id" => Ok(SyntaxNode::DirectiveId),
            "identifier" => Ok(SyntaxNode::Identifier),
            "instr_id" => Ok(SyntaxNode::InstrId),
            "label" => Ok(SyntaxNode::Label),
            _ => Err(format!("Unknown node type {:?}", value)),
        }
    }
}

/// generate documentation for a node
pub fn doc_node<'a>(cursor: &mut TreeCursor<'a>, point: &Point) -> String {
    let node = cursor.node();
    match SyntaxNode::try_from(node.kind()) {
        Ok(node_kind) => match node_kind {
            SyntaxNode::Constant => nll_todo(),
            SyntaxNode::ConstantHex => nll_todo(),
            SyntaxNode::Directive => nll_todo(),
            SyntaxNode::DirectiveArg => nll_todo(),
            SyntaxNode::Instruction => nll_todo(),
            SyntaxNode::Operand => nll_todo(),
            SyntaxNode::OperandNoParens => nll_todo(),
            SyntaxNode::OperandParens => nll_todo(),
            SyntaxNode::RelocSymbol => nll_todo(),
            SyntaxNode::Relocation => nll_todo(),
            SyntaxNode::SourceFile => nll_todo(),
            SyntaxNode::Comment => nll_todo(),
            SyntaxNode::ConstantDec => nll_todo(),
            SyntaxNode::DirectiveId => nll_todo(),
            SyntaxNode::Identifier => nll_todo(),
            SyntaxNode::InstrId => nll_todo(),
            SyntaxNode::Label => nll_todo(),
        },
        Err(err) => err,
    }
}

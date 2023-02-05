use nll::nll_todo::nll_todo;
use tree_sitter::{Point, TreeCursor, Node};

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
pub fn doc_node<'a: 'b, 'b>(cursor: &'b mut TreeCursor<'a>, point: &Point) -> (String, &'b mut TreeCursor<'a>) {
    match SyntaxNode::try_from(cursor.node().kind()) {
        Ok(node_kind) => match node_kind {
            SyntaxNode::Constant => {
                // for child in cursor.go() {
                // }
                // doc_node(cursor, point)
                nll_todo()
            },
            SyntaxNode::ConstantHex => {
                (r#"
                    Hexadecimal constant
                "#.to_string(), cursor)
            },
            SyntaxNode::ConstantDec => {
                (r#"
                    Decimal constant
                "#.to_string(), cursor)
            },

            SyntaxNode::Directive => nll_todo(),
            SyntaxNode::DirectiveArg => nll_todo(),
            SyntaxNode::Instruction => nll_todo(),
            SyntaxNode::Operand => nll_todo(),
            SyntaxNode::OperandNoParens => nll_todo(),
            SyntaxNode::OperandParens => {
                // for child in node.children(&mut cursor.clone()) {
                //     if child.contains_point(point) {
                //         return doc_node(&mut cursor.clone(), point);
                //     }
                // }
                nll_todo()
            },
            SyntaxNode::RelocSymbol => {
                (r#"
                    # Relocation symbol
                "#.to_string(), cursor)
            },
            SyntaxNode::Relocation => {
                (r#"
                    # Relocation identifier
                "#.to_string(), cursor)
            },
            SyntaxNode::SourceFile => ("nothing to see here".to_string(), cursor),
            SyntaxNode::Comment =>
                (r#"
                    # Comment
                "#.to_string(), cursor)
            ,
            SyntaxNode::DirectiveId => {
                (r#"
                    # Directive identifier
                "#.to_string(), cursor)
            },
            SyntaxNode::Identifier => {
                (r#"
                    # Register identifier
                "#.to_string(), cursor)
            },
            SyntaxNode::InstrId =>
                (r#"
                    # Instruction Id
                "#.to_string(), cursor)
            ,
            SyntaxNode::Label => {
                (r#"
                    # Label
                "#.to_string(), cursor)
            },
        },
        Err(err) => (err, cursor),
    }
}

pub enum RegisterWidth {
    XLEN
}

pub type RegisterName = String;

pub struct Register {
    width: RegisterWidth,
    name: RegisterName
}

pub fn get_rv32i_registers() -> Vec<Register> {
    vec![
        Register {
            name: "x0".to_string(),
            width: RegisterWidth::XLEN
        },
        Register {
            name: "x1".to_string(),
            width: RegisterWidth::XLEN
        },
        Register {
            name: "x2".to_string(),
            width: RegisterWidth::XLEN
        },
        Register {
            name: "x3".to_string(),
            width: RegisterWidth::XLEN
        },
        Register {
            name: "x4".to_string(),
            width: RegisterWidth::XLEN
        },
        Register {
            name: "x5".to_string(),
            width: RegisterWidth::XLEN
        },
        Register {
            name: "x6".to_string(),
            width: RegisterWidth::XLEN
        },
        Register {
            name: "x7".to_string(),
            width: RegisterWidth::XLEN
        },
        Register {
            name: "x8".to_string(),
            width: RegisterWidth::XLEN
        },
        Register {
            name: "x9".to_string(),
            width: RegisterWidth::XLEN
        },
        Register {
            name: "x10".to_string(),
            width: RegisterWidth::XLEN
        },
        Register {
            name: "x11".to_string(),
            width: RegisterWidth::XLEN
        },
        Register {
            name: "x12".to_string(),
            width: RegisterWidth::XLEN
        },
        Register {
            name: "x13".to_string(),
            width: RegisterWidth::XLEN
        },
        Register {
            name: "x14".to_string(),
            width: RegisterWidth::XLEN
        },
        Register {
            name: "x15".to_string(),
            width: RegisterWidth::XLEN
        },
        Register {
            name: "x16".to_string(),
            width: RegisterWidth::XLEN
        },
        Register {
            name: "x17".to_string(),
            width: RegisterWidth::XLEN
        },
        Register {
            name: "x18".to_string(),
            width: RegisterWidth::XLEN
        },
        Register {
            name: "x19".to_string(),
            width: RegisterWidth::XLEN
        },
        Register {
            name: "x20".to_string(),
            width: RegisterWidth::XLEN
        },
        Register {
            name: "x21".to_string(),
            width: RegisterWidth::XLEN
        },
        Register {
            name: "x22".to_string(),
            width: RegisterWidth::XLEN
        },
        Register {
            name: "x23".to_string(),
            width: RegisterWidth::XLEN
        },
        Register {
            name: "x24".to_string(),
            width: RegisterWidth::XLEN
        },
        Register {
            name: "x25".to_string(),
            width: RegisterWidth::XLEN
        },
        Register {
            name: "x26".to_string(),
            width: RegisterWidth::XLEN
        },
        Register {
            name: "x27".to_string(),
            width: RegisterWidth::XLEN
        },
        Register {
            name: "x28".to_string(),
            width: RegisterWidth::XLEN
        },
        Register {
            name: "x29".to_string(),
            width: RegisterWidth::XLEN
        },
        Register {
            name: "x30".to_string(),
            width: RegisterWidth::XLEN
        },
        Register {
            name: "x31".to_string(),
            width: RegisterWidth::XLEN
        },
        Register {
            name: "pc".to_string(),
            width: RegisterWidth::XLEN
        },
    ]
}

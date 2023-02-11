use std::{collections::{HashMap, HashSet}, fmt::Display};

use nll::nll_todo::nll_todo;
use ropey::Rope;
use tree_sitter::{Node, Point, TreeCursor};
#[macro_use]
use lazy_static::lazy_static;


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
pub fn doc_node<'a: 'b, 'b>(
    cursor: &'b mut TreeCursor<'a>,
    point: &Point,
    src: &Rope,
) -> (String, &'b mut TreeCursor<'a>) {
    let node = cursor.node();
    match SyntaxNode::try_from(node.kind()) {
        Ok(node_kind) => match node_kind {
            SyntaxNode::Constant => {
                let mut total_docs = String::default();
                let has_children = cursor.goto_first_child();
                assert!(has_children);
                let (doc, mut cursor) = doc_node(cursor, point, src);
                total_docs.push_str(&doc);
                while cursor.goto_next_sibling() {
                    let (doc, moved_cursor) = doc_node(cursor, point, src);
                    total_docs.push_str(&doc);
                    cursor = moved_cursor;
                }
                (total_docs, cursor)
            }
            SyntaxNode::ConstantHex => ("Hexadecimal constant".to_string(), cursor),
            SyntaxNode::ConstantDec => ("Decimal constant".to_string(), cursor),
            SyntaxNode::Directive => nll_todo(),
            SyntaxNode::DirectiveArg => nll_todo(),
            // TODO combine these brancnes if they're going to
            // continue to have the same logic
            SyntaxNode::Instruction => {
                let result = cursor.goto_first_child_for_point(*point);
                assert!(result.is_some());
                doc_node(cursor, point, src)
            }
            SyntaxNode::Operand => {
                let result = cursor.goto_first_child_for_point(*point);
                assert!(result.is_some());
                doc_node(cursor, point, src)
            }
            SyntaxNode::OperandNoParens => {
                let range = node.byte_range();
                let identifier = src.byte_slice(range);
                let mut result =
                    format!("# high Register\n\tUnknown register {identifier:?} \n ").to_string();

                if !node.has_error() {
                    if let Some(register) = RV32I_REGISTER_MAP.get(&identifier.to_string()) {
                        result = format!("{}", register);
                    }
                }
                (result, cursor)
            }
            SyntaxNode::OperandParens => {
                let result = cursor.goto_first_child_for_point(*point);
                assert!(result.is_some());
                doc_node(cursor, point, src)
            }
            SyntaxNode::RelocSymbol => ("# Relocation symbol".to_string(), cursor),
            SyntaxNode::Relocation => ("# Relocation identifier".to_string(), cursor),
            SyntaxNode::SourceFile => ("nothing to see here".to_string(), cursor),
            SyntaxNode::Comment => ("# Comment".to_string(), cursor),
            SyntaxNode::DirectiveId => ("# Directive identifier\n".to_string(), cursor),
            SyntaxNode::Identifier => {
                ("error?".to_string(), cursor)
            }
            SyntaxNode::InstrId => ("# Instruction Id".to_string(), cursor),
            SyntaxNode::Label => ("# Label".to_string(), cursor),
        },
        Err(err) => (err, cursor),
    }
}

#[derive(Clone, Debug, PartialEq, Eq, Hash)]
pub enum RegisterWidth {
    XLEN,
}

pub type RegisterName = String;

#[derive(Clone, Debug, PartialEq, Eq, Hash)]
pub struct Register {
    width: RegisterWidth,
    name: RegisterName,
    docs: String,
}

impl Display for Register {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(
            f,
            "# Register\n\t- Name: {:?}\n\t- Width: {:?},\n# Usage:\n\t{:?}",
            self.name, self.width, self.docs
        )
    }
}

#[derive(Clone, Debug, PartialEq, Eq, Hash)]
pub struct Instruction {
    name: String,
    num_operands: usize,
    docs: String,
}

impl Display for Instruction {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(
            f,
            "# Instruction\n\t- Name: {:?}\n\t- Num Operands: {:?},\n# Usage:\n\t{:?}",
            self.name, self.num_operands, self.docs
        )
    }
}

// static ref RV32I_INSTRUCTIONS: Vec<Instruction> = get_rv32i_instructions();
lazy_static! {
    pub static ref RV32I_REGISTERS: HashSet<Register> = {
        vec![
            Register {
                name: "x0".to_string(),
                width: RegisterWidth::XLEN,
                docs: "".to_string(),
            },
            Register {
                name: "x1".to_string(),
                width: RegisterWidth::XLEN,
                docs: "".to_string(),
            },
            Register {
                name: "x2".to_string(),
                width: RegisterWidth::XLEN,
                docs: "".to_string(),
            },
            Register {
                name: "x3".to_string(),
                width: RegisterWidth::XLEN,
                docs: "".to_string(),
            },
            Register {
                name: "x4".to_string(),
                width: RegisterWidth::XLEN,
                docs: "".to_string(),
            },
            Register {
                name: "x5".to_string(),
                width: RegisterWidth::XLEN,
                docs: "".to_string(),
            },
            Register {
                name: "x6".to_string(),
                width: RegisterWidth::XLEN,
                docs: "".to_string(),
            },
            Register {
                name: "x7".to_string(),
                width: RegisterWidth::XLEN,
                docs: "".to_string(),
            },
            Register {
                name: "x8".to_string(),
                width: RegisterWidth::XLEN,
                docs: "".to_string(),
            },
            Register {
                name: "x9".to_string(),
                width: RegisterWidth::XLEN,
                docs: "".to_string(),
            },
            Register {
                name: "x10".to_string(),
                width: RegisterWidth::XLEN,
                docs: "".to_string(),
            },
            Register {
                name: "x11".to_string(),
                width: RegisterWidth::XLEN,
                docs: "".to_string(),
            },
            Register {
                name: "x12".to_string(),
                width: RegisterWidth::XLEN,
                docs: "".to_string(),
            },
            Register {
                name: "x13".to_string(),
                width: RegisterWidth::XLEN,
                docs: "".to_string(),
            },
            Register {
                name: "x14".to_string(),
                width: RegisterWidth::XLEN,
                docs: "".to_string(),
            },
            Register {
                name: "x15".to_string(),
                width: RegisterWidth::XLEN,
                docs: "".to_string(),
            },
            Register {
                name: "x16".to_string(),
                width: RegisterWidth::XLEN,
                docs: "".to_string(),
            },
            Register {
                name: "x17".to_string(),
                width: RegisterWidth::XLEN,
                docs: "".to_string(),
            },
            Register {
                name: "x18".to_string(),
                width: RegisterWidth::XLEN,
                docs: "".to_string(),
            },
            Register {
                name: "x19".to_string(),
                width: RegisterWidth::XLEN,
                docs: "".to_string(),
            },
            Register {
                name: "x20".to_string(),
                width: RegisterWidth::XLEN,
                docs: "".to_string(),
            },
            Register {
                name: "x21".to_string(),
                width: RegisterWidth::XLEN,
                docs: "".to_string(),
            },
            Register {
                name: "x22".to_string(),
                width: RegisterWidth::XLEN,
                docs: "".to_string(),
            },
            Register {
                name: "x23".to_string(),
                width: RegisterWidth::XLEN,
                docs: "".to_string(),
            },
            Register {
                name: "x24".to_string(),
                width: RegisterWidth::XLEN,
                docs: "".to_string(),
            },
            Register {
                name: "x25".to_string(),
                width: RegisterWidth::XLEN,
                docs: "".to_string(),
            },
            Register {
                name: "x26".to_string(),
                width: RegisterWidth::XLEN,
                docs: "".to_string(),
            },
            Register {
                name: "x27".to_string(),
                width: RegisterWidth::XLEN,
                docs: "".to_string(),
            },
            Register {
                name: "x28".to_string(),
                width: RegisterWidth::XLEN,
                docs: "".to_string(),
            },
            Register {
                name: "x29".to_string(),
                width: RegisterWidth::XLEN,
                docs: "".to_string(),
            },
            Register {
                name: "x30".to_string(),
                width: RegisterWidth::XLEN,
                docs: "".to_string(),
            },
            Register {
                name: "x31".to_string(),
                width: RegisterWidth::XLEN,
                docs: "".to_string(),
            },
            Register {
                name: "pc".to_string(),
                width: RegisterWidth::XLEN,
                docs: "".to_string(),
            },
            ].into_iter().collect()
    };
    pub static ref RV32I_REGISTER_MAP: HashMap<RegisterName, Register> = {
        let mut map = HashMap::new();
        for register in RV32I_REGISTERS.iter() {
            map.insert(register.name.clone(), register.clone());
        }
        map
    };
    pub static ref RV32I_INSTRUCTIONS: HashSet<Instruction> = {
        vec![
            Instruction {
                name: "add".to_string(),
                num_operands: 3,
                docs: "".to_string(),
            }
        ].into_iter().collect()
    };
    pub static ref RV32I_INSTRUCTION_MAP: HashMap<String, Instruction> = {
        let mut map = HashMap::new();
        for instruction in RV32I_INSTRUCTIONS.iter() {
            map.insert(instruction.name.clone(), instruction.clone());
        }
        map
    };

}



pub fn get_rv32i_registers() -> Vec<Register> {
    nll_todo()
}

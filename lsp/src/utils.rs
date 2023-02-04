use ropey::{Error, Rope};
use tower_lsp::lsp_types::Position;
use tree_sitter::Point;

type ByteIndex = usize;

type CharIndex = usize;

pub fn point_to_position(p: Point) -> Position {
    Position {
        line: p.row as u32,
        character: u32::checked_sub(p.column as u32, 1).unwrap_or_else(|| 0),
    }
}

/// NOTE `Point` is one indexed
/// `Position` is zero indexed
pub fn position_to_point(p: Position) -> Point {
    let col = p.character as usize + 1;
    Point {
        row: p.line as usize,
        column: col,
    }
}

pub fn position_info(position: Position, rope: &Rope) -> Result<(CharIndex, ByteIndex), Error> {
    let line_char_offset = rope.try_line_to_char(position.line as usize)?;
    let total_char_offset = line_char_offset + position.character as usize;
    rope.try_char_to_byte(total_char_offset)
        .map(|x| (total_char_offset, x))
}

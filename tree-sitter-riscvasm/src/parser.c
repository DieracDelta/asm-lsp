#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 49
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 31
#define ALIAS_COUNT 0
#define TOKEN_COUNT 17
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 8
#define PRODUCTION_ID_COUNT 1

enum {
  anon_sym_LF = 1,
  sym_label = 2,
  anon_sym_COMMA = 3,
  sym_directive_id = 4,
  aux_sym_directive_arg_token1 = 5,
  anon_sym_PERCENT = 6,
  anon_sym_LPAREN = 7,
  anon_sym_RPAREN = 8,
  sym_identifier = 9,
  sym_instr_id = 10,
  anon_sym_DASH = 11,
  anon_sym_0x = 12,
  aux_sym_constant_hex_token1 = 13,
  sym_constant_dec = 14,
  sym_comment = 15,
  sym__whitespace = 16,
  sym_source_file = 17,
  sym__root = 18,
  sym_directive = 19,
  sym_directive_arg = 20,
  sym_relocation = 21,
  sym_constant = 22,
  sym_constant_hex = 23,
  sym_reloc_symbol = 24,
  sym_instruction = 25,
  sym_operand = 26,
  sym_operand_parens = 27,
  sym_operand_no_parens = 28,
  aux_sym_source_file_repeat1 = 29,
  aux_sym_directive_repeat1 = 30,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_LF] = "\n",
  [sym_label] = "label",
  [anon_sym_COMMA] = ",",
  [sym_directive_id] = "directive_id",
  [aux_sym_directive_arg_token1] = "directive_arg_token1",
  [anon_sym_PERCENT] = "%",
  [anon_sym_LPAREN] = "(",
  [anon_sym_RPAREN] = ")",
  [sym_identifier] = "identifier",
  [sym_instr_id] = "instr_id",
  [anon_sym_DASH] = "-",
  [anon_sym_0x] = "0x",
  [aux_sym_constant_hex_token1] = "constant_hex_token1",
  [sym_constant_dec] = "constant_dec",
  [sym_comment] = "comment",
  [sym__whitespace] = "_whitespace",
  [sym_source_file] = "source_file",
  [sym__root] = "_root",
  [sym_directive] = "directive",
  [sym_directive_arg] = "directive_arg",
  [sym_relocation] = "relocation",
  [sym_constant] = "constant",
  [sym_constant_hex] = "constant_hex",
  [sym_reloc_symbol] = "reloc_symbol",
  [sym_instruction] = "instruction",
  [sym_operand] = "operand",
  [sym_operand_parens] = "operand_parens",
  [sym_operand_no_parens] = "operand_no_parens",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym_directive_repeat1] = "directive_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_LF] = anon_sym_LF,
  [sym_label] = sym_label,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [sym_directive_id] = sym_directive_id,
  [aux_sym_directive_arg_token1] = aux_sym_directive_arg_token1,
  [anon_sym_PERCENT] = anon_sym_PERCENT,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [sym_identifier] = sym_identifier,
  [sym_instr_id] = sym_instr_id,
  [anon_sym_DASH] = anon_sym_DASH,
  [anon_sym_0x] = anon_sym_0x,
  [aux_sym_constant_hex_token1] = aux_sym_constant_hex_token1,
  [sym_constant_dec] = sym_constant_dec,
  [sym_comment] = sym_comment,
  [sym__whitespace] = sym__whitespace,
  [sym_source_file] = sym_source_file,
  [sym__root] = sym__root,
  [sym_directive] = sym_directive,
  [sym_directive_arg] = sym_directive_arg,
  [sym_relocation] = sym_relocation,
  [sym_constant] = sym_constant,
  [sym_constant_hex] = sym_constant_hex,
  [sym_reloc_symbol] = sym_reloc_symbol,
  [sym_instruction] = sym_instruction,
  [sym_operand] = sym_operand,
  [sym_operand_parens] = sym_operand_parens,
  [sym_operand_no_parens] = sym_operand_no_parens,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
  [aux_sym_directive_repeat1] = aux_sym_directive_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_LF] = {
    .visible = true,
    .named = false,
  },
  [sym_label] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_COMMA] = {
    .visible = true,
    .named = false,
  },
  [sym_directive_id] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_directive_arg_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_PERCENT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RPAREN] = {
    .visible = true,
    .named = false,
  },
  [sym_identifier] = {
    .visible = true,
    .named = true,
  },
  [sym_instr_id] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_DASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_0x] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_constant_hex_token1] = {
    .visible = false,
    .named = false,
  },
  [sym_constant_dec] = {
    .visible = true,
    .named = true,
  },
  [sym_comment] = {
    .visible = true,
    .named = true,
  },
  [sym__whitespace] = {
    .visible = false,
    .named = true,
  },
  [sym_source_file] = {
    .visible = true,
    .named = true,
  },
  [sym__root] = {
    .visible = false,
    .named = true,
  },
  [sym_directive] = {
    .visible = true,
    .named = true,
  },
  [sym_directive_arg] = {
    .visible = true,
    .named = true,
  },
  [sym_relocation] = {
    .visible = true,
    .named = true,
  },
  [sym_constant] = {
    .visible = true,
    .named = true,
  },
  [sym_constant_hex] = {
    .visible = true,
    .named = true,
  },
  [sym_reloc_symbol] = {
    .visible = true,
    .named = true,
  },
  [sym_instruction] = {
    .visible = true,
    .named = true,
  },
  [sym_operand] = {
    .visible = true,
    .named = true,
  },
  [sym_operand_parens] = {
    .visible = true,
    .named = true,
  },
  [sym_operand_no_parens] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_source_file_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_directive_repeat1] = {
    .visible = false,
    .named = false,
  },
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
  [4] = 4,
  [5] = 5,
  [6] = 6,
  [7] = 7,
  [8] = 8,
  [9] = 9,
  [10] = 10,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 14,
  [15] = 12,
  [16] = 16,
  [17] = 17,
  [18] = 18,
  [19] = 19,
  [20] = 20,
  [21] = 21,
  [22] = 22,
  [23] = 23,
  [24] = 24,
  [25] = 25,
  [26] = 26,
  [27] = 27,
  [28] = 28,
  [29] = 29,
  [30] = 30,
  [31] = 31,
  [32] = 32,
  [33] = 33,
  [34] = 34,
  [35] = 35,
  [36] = 36,
  [37] = 37,
  [38] = 38,
  [39] = 39,
  [40] = 40,
  [41] = 41,
  [42] = 42,
  [43] = 13,
  [44] = 31,
  [45] = 20,
  [46] = 21,
  [47] = 47,
  [48] = 38,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(11);
      if (lookahead == '\n') ADVANCE(12);
      if (lookahead == '"') ADVANCE(3);
      if (lookahead == '#') ADVANCE(33);
      if (lookahead == '%') ADVANCE(18);
      if (lookahead == '(') ADVANCE(19);
      if (lookahead == ')') ADVANCE(20);
      if (lookahead == ',') ADVANCE(14);
      if (lookahead == '-') ADVANCE(25);
      if (lookahead == '.') ADVANCE(22);
      if (lookahead == '/') ADVANCE(5);
      if (lookahead == '0') ADVANCE(27);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(34);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(28);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(21);
      if (('G' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('g' <= lookahead && lookahead <= 'z')) ADVANCE(23);
      END_STATE();
    case 1:
      if (lookahead == '\n') ADVANCE(12);
      if (lookahead == '"') ADVANCE(3);
      if (lookahead == '#') ADVANCE(33);
      if (lookahead == '%') ADVANCE(18);
      if (lookahead == '(') ADVANCE(19);
      if (lookahead == '-') ADVANCE(25);
      if (lookahead == '/') ADVANCE(5);
      if (lookahead == '0') ADVANCE(30);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(34);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(31);
      if (lookahead == '.' ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(23);
      END_STATE();
    case 2:
      if (lookahead == '"') ADVANCE(3);
      if (lookahead == '#') ADVANCE(33);
      if (lookahead == '%') ADVANCE(18);
      if (lookahead == '(') ADVANCE(19);
      if (lookahead == '-') ADVANCE(25);
      if (lookahead == '/') ADVANCE(5);
      if (lookahead == '0') ADVANCE(30);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(34);
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(31);
      if (lookahead == '.' ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(23);
      END_STATE();
    case 3:
      if (lookahead == '"') ADVANCE(17);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(3);
      END_STATE();
    case 4:
      if (lookahead == '#') ADVANCE(33);
      if (lookahead == '/') ADVANCE(5);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(34);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(29);
      END_STATE();
    case 5:
      if (lookahead == '*') ADVANCE(7);
      if (lookahead == '/') ADVANCE(33);
      END_STATE();
    case 6:
      if (lookahead == '*') ADVANCE(6);
      if (lookahead == '/') ADVANCE(32);
      if (lookahead != 0) ADVANCE(7);
      END_STATE();
    case 7:
      if (lookahead == '*') ADVANCE(6);
      if (lookahead != 0) ADVANCE(7);
      END_STATE();
    case 8:
      if (lookahead == ':') ADVANCE(13);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(15);
      END_STATE();
    case 9:
      if (lookahead == ':') ADVANCE(13);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(9);
      END_STATE();
    case 10:
      if (eof) ADVANCE(11);
      if (lookahead == '#') ADVANCE(33);
      if (lookahead == '(') ADVANCE(19);
      if (lookahead == ')') ADVANCE(20);
      if (lookahead == '.') ADVANCE(8);
      if (lookahead == '/') ADVANCE(5);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(34);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(9);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(24);
      END_STATE();
    case 11:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 12:
      ACCEPT_TOKEN(anon_sym_LF);
      END_STATE();
    case 13:
      ACCEPT_TOKEN(sym_label);
      END_STATE();
    case 14:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 15:
      ACCEPT_TOKEN(sym_directive_id);
      if (lookahead == ':') ADVANCE(13);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(15);
      END_STATE();
    case 16:
      ACCEPT_TOKEN(sym_directive_id);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(16);
      END_STATE();
    case 17:
      ACCEPT_TOKEN(aux_sym_directive_arg_token1);
      if (lookahead == '"') ADVANCE(17);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(3);
      END_STATE();
    case 18:
      ACCEPT_TOKEN(anon_sym_PERCENT);
      END_STATE();
    case 19:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 20:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(sym_identifier);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(21);
      if (lookahead == '.' ||
          ('G' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('g' <= lookahead && lookahead <= 'z')) ADVANCE(23);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(16);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(23);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(sym_instr_id);
      if (lookahead == ':') ADVANCE(13);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(24);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(anon_sym_DASH);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(anon_sym_0x);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(aux_sym_constant_hex_token1);
      if (lookahead == 'x') ADVANCE(26);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(28);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(29);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(aux_sym_constant_hex_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(28);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(29);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(aux_sym_constant_hex_token1);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(29);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(sym_constant_dec);
      if (lookahead == 'x') ADVANCE(26);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(31);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(sym_constant_dec);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(31);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(sym_comment);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(sym_comment);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(33);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(sym__whitespace);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 10},
  [2] = {.lex_state = 1},
  [3] = {.lex_state = 2},
  [4] = {.lex_state = 2},
  [5] = {.lex_state = 1},
  [6] = {.lex_state = 10},
  [7] = {.lex_state = 2},
  [8] = {.lex_state = 10},
  [9] = {.lex_state = 2},
  [10] = {.lex_state = 2},
  [11] = {.lex_state = 10},
  [12] = {.lex_state = 2},
  [13] = {.lex_state = 0},
  [14] = {.lex_state = 0},
  [15] = {.lex_state = 2},
  [16] = {.lex_state = 0},
  [17] = {.lex_state = 0},
  [18] = {.lex_state = 0},
  [19] = {.lex_state = 0},
  [20] = {.lex_state = 0},
  [21] = {.lex_state = 0},
  [22] = {.lex_state = 0},
  [23] = {.lex_state = 0},
  [24] = {.lex_state = 0},
  [25] = {.lex_state = 0},
  [26] = {.lex_state = 2},
  [27] = {.lex_state = 2},
  [28] = {.lex_state = 2},
  [29] = {.lex_state = 0},
  [30] = {.lex_state = 0},
  [31] = {.lex_state = 0},
  [32] = {.lex_state = 0},
  [33] = {.lex_state = 0},
  [34] = {.lex_state = 10},
  [35] = {.lex_state = 10},
  [36] = {.lex_state = 10},
  [37] = {.lex_state = 0},
  [38] = {.lex_state = 4},
  [39] = {.lex_state = 0},
  [40] = {.lex_state = 10},
  [41] = {.lex_state = 10},
  [42] = {.lex_state = 10},
  [43] = {.lex_state = 10},
  [44] = {.lex_state = 10},
  [45] = {.lex_state = 10},
  [46] = {.lex_state = 10},
  [47] = {.lex_state = 10},
  [48] = {.lex_state = 4},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_LF] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [sym_directive_id] = ACTIONS(1),
    [aux_sym_directive_arg_token1] = ACTIONS(1),
    [anon_sym_PERCENT] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [sym_identifier] = ACTIONS(1),
    [sym_instr_id] = ACTIONS(1),
    [anon_sym_DASH] = ACTIONS(1),
    [anon_sym_0x] = ACTIONS(1),
    [aux_sym_constant_hex_token1] = ACTIONS(1),
    [sym_constant_dec] = ACTIONS(1),
    [sym_comment] = ACTIONS(3),
    [sym__whitespace] = ACTIONS(5),
  },
  [1] = {
    [sym_source_file] = STATE(47),
    [sym__root] = STATE(8),
    [sym_directive] = STATE(37),
    [sym_instruction] = STATE(37),
    [aux_sym_source_file_repeat1] = STATE(8),
    [ts_builtin_sym_end] = ACTIONS(7),
    [sym_label] = ACTIONS(9),
    [sym_directive_id] = ACTIONS(11),
    [sym_instr_id] = ACTIONS(13),
    [sym_comment] = ACTIONS(3),
    [sym__whitespace] = ACTIONS(3),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 13,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(5), 1,
      sym__whitespace,
    ACTIONS(15), 1,
      anon_sym_LF,
    ACTIONS(17), 1,
      anon_sym_PERCENT,
    ACTIONS(19), 1,
      anon_sym_LPAREN,
    ACTIONS(21), 1,
      sym_identifier,
    ACTIONS(23), 1,
      anon_sym_DASH,
    ACTIONS(25), 1,
      anon_sym_0x,
    ACTIONS(27), 1,
      sym_constant_dec,
    STATE(13), 1,
      sym_constant_hex,
    STATE(18), 1,
      sym_constant,
    STATE(23), 1,
      sym_operand,
    STATE(30), 3,
      sym_relocation,
      sym_operand_parens,
      sym_operand_no_parens,
  [42] = 11,
    ACTIONS(17), 1,
      anon_sym_PERCENT,
    ACTIONS(19), 1,
      anon_sym_LPAREN,
    ACTIONS(21), 1,
      sym_identifier,
    ACTIONS(23), 1,
      anon_sym_DASH,
    ACTIONS(25), 1,
      anon_sym_0x,
    ACTIONS(27), 1,
      sym_constant_dec,
    STATE(13), 1,
      sym_constant_hex,
    STATE(18), 1,
      sym_constant,
    STATE(39), 1,
      sym_operand,
    ACTIONS(3), 2,
      sym_comment,
      sym__whitespace,
    STATE(30), 3,
      sym_relocation,
      sym_operand_parens,
      sym_operand_no_parens,
  [79] = 11,
    ACTIONS(17), 1,
      anon_sym_PERCENT,
    ACTIONS(19), 1,
      anon_sym_LPAREN,
    ACTIONS(21), 1,
      sym_identifier,
    ACTIONS(23), 1,
      anon_sym_DASH,
    ACTIONS(25), 1,
      anon_sym_0x,
    ACTIONS(27), 1,
      sym_constant_dec,
    STATE(13), 1,
      sym_constant_hex,
    STATE(18), 1,
      sym_constant,
    STATE(33), 1,
      sym_operand,
    ACTIONS(3), 2,
      sym_comment,
      sym__whitespace,
    STATE(30), 3,
      sym_relocation,
      sym_operand_parens,
      sym_operand_no_parens,
  [116] = 9,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(5), 1,
      sym__whitespace,
    ACTIONS(23), 1,
      anon_sym_DASH,
    ACTIONS(25), 1,
      anon_sym_0x,
    ACTIONS(27), 1,
      sym_constant_dec,
    ACTIONS(29), 1,
      anon_sym_LF,
    STATE(13), 1,
      sym_constant_hex,
    ACTIONS(31), 2,
      aux_sym_directive_arg_token1,
      sym_identifier,
    STATE(14), 2,
      sym_directive_arg,
      sym_constant,
  [146] = 7,
    ACTIONS(33), 1,
      ts_builtin_sym_end,
    ACTIONS(35), 1,
      sym_label,
    ACTIONS(38), 1,
      sym_directive_id,
    ACTIONS(41), 1,
      sym_instr_id,
    ACTIONS(3), 2,
      sym_comment,
      sym__whitespace,
    STATE(6), 2,
      sym__root,
      aux_sym_source_file_repeat1,
    STATE(37), 2,
      sym_directive,
      sym_instruction,
  [171] = 7,
    ACTIONS(23), 1,
      anon_sym_DASH,
    ACTIONS(25), 1,
      anon_sym_0x,
    ACTIONS(27), 1,
      sym_constant_dec,
    STATE(13), 1,
      sym_constant_hex,
    ACTIONS(3), 2,
      sym_comment,
      sym__whitespace,
    ACTIONS(31), 2,
      aux_sym_directive_arg_token1,
      sym_identifier,
    STATE(29), 2,
      sym_directive_arg,
      sym_constant,
  [196] = 7,
    ACTIONS(9), 1,
      sym_label,
    ACTIONS(11), 1,
      sym_directive_id,
    ACTIONS(13), 1,
      sym_instr_id,
    ACTIONS(44), 1,
      ts_builtin_sym_end,
    ACTIONS(3), 2,
      sym_comment,
      sym__whitespace,
    STATE(6), 2,
      sym__root,
      aux_sym_source_file_repeat1,
    STATE(37), 2,
      sym_directive,
      sym_instruction,
  [221] = 7,
    ACTIONS(46), 1,
      sym_identifier,
    ACTIONS(48), 1,
      anon_sym_DASH,
    ACTIONS(50), 1,
      anon_sym_0x,
    ACTIONS(52), 1,
      sym_constant_dec,
    STATE(41), 1,
      sym_constant,
    STATE(43), 1,
      sym_constant_hex,
    ACTIONS(3), 2,
      sym_comment,
      sym__whitespace,
  [244] = 7,
    ACTIONS(48), 1,
      anon_sym_DASH,
    ACTIONS(50), 1,
      anon_sym_0x,
    ACTIONS(52), 1,
      sym_constant_dec,
    ACTIONS(54), 1,
      sym_identifier,
    STATE(34), 1,
      sym_constant,
    STATE(43), 1,
      sym_constant_hex,
    ACTIONS(3), 2,
      sym_comment,
      sym__whitespace,
  [267] = 3,
    ACTIONS(3), 2,
      sym_comment,
      sym__whitespace,
    ACTIONS(56), 2,
      ts_builtin_sym_end,
      sym_label,
    ACTIONS(58), 2,
      sym_directive_id,
      sym_instr_id,
  [280] = 4,
    ACTIONS(25), 1,
      anon_sym_0x,
    ACTIONS(60), 1,
      sym_constant_dec,
    STATE(20), 1,
      sym_constant_hex,
    ACTIONS(3), 2,
      sym_comment,
      sym__whitespace,
  [294] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(5), 1,
      sym__whitespace,
    ACTIONS(62), 3,
      anon_sym_LF,
      anon_sym_COMMA,
      anon_sym_LPAREN,
  [306] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(5), 1,
      sym__whitespace,
    ACTIONS(64), 1,
      anon_sym_LF,
    ACTIONS(66), 1,
      anon_sym_COMMA,
    STATE(19), 1,
      aux_sym_directive_repeat1,
  [322] = 4,
    ACTIONS(50), 1,
      anon_sym_0x,
    ACTIONS(68), 1,
      sym_constant_dec,
    STATE(45), 1,
      sym_constant_hex,
    ACTIONS(3), 2,
      sym_comment,
      sym__whitespace,
  [336] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(5), 1,
      sym__whitespace,
    ACTIONS(70), 1,
      anon_sym_LF,
    ACTIONS(72), 1,
      anon_sym_COMMA,
    STATE(16), 1,
      aux_sym_directive_repeat1,
  [352] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(5), 1,
      sym__whitespace,
    ACTIONS(77), 1,
      anon_sym_LPAREN,
    ACTIONS(75), 2,
      anon_sym_LF,
      anon_sym_COMMA,
  [366] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(5), 1,
      sym__whitespace,
    ACTIONS(81), 1,
      anon_sym_LPAREN,
    ACTIONS(79), 2,
      anon_sym_LF,
      anon_sym_COMMA,
  [380] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(5), 1,
      sym__whitespace,
    ACTIONS(66), 1,
      anon_sym_COMMA,
    ACTIONS(83), 1,
      anon_sym_LF,
    STATE(16), 1,
      aux_sym_directive_repeat1,
  [396] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(5), 1,
      sym__whitespace,
    ACTIONS(85), 3,
      anon_sym_LF,
      anon_sym_COMMA,
      anon_sym_LPAREN,
  [408] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(5), 1,
      sym__whitespace,
    ACTIONS(87), 3,
      anon_sym_LF,
      anon_sym_COMMA,
      anon_sym_LPAREN,
  [420] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(5), 1,
      sym__whitespace,
    ACTIONS(89), 2,
      anon_sym_LF,
      anon_sym_COMMA,
  [431] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(5), 1,
      sym__whitespace,
    ACTIONS(91), 1,
      anon_sym_LF,
    ACTIONS(93), 1,
      anon_sym_COMMA,
  [444] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(5), 1,
      sym__whitespace,
    ACTIONS(95), 2,
      anon_sym_LF,
      anon_sym_COMMA,
  [455] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(5), 1,
      sym__whitespace,
    ACTIONS(97), 2,
      anon_sym_LF,
      anon_sym_COMMA,
  [466] = 3,
    ACTIONS(99), 1,
      sym_identifier,
    STATE(42), 1,
      sym_reloc_symbol,
    ACTIONS(3), 2,
      sym_comment,
      sym__whitespace,
  [477] = 3,
    ACTIONS(101), 1,
      sym_identifier,
    STATE(35), 1,
      sym_operand_no_parens,
    ACTIONS(3), 2,
      sym_comment,
      sym__whitespace,
  [488] = 3,
    ACTIONS(101), 1,
      sym_identifier,
    STATE(40), 1,
      sym_operand_no_parens,
    ACTIONS(3), 2,
      sym_comment,
      sym__whitespace,
  [499] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(5), 1,
      sym__whitespace,
    ACTIONS(70), 2,
      anon_sym_LF,
      anon_sym_COMMA,
  [510] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(5), 1,
      sym__whitespace,
    ACTIONS(79), 2,
      anon_sym_LF,
      anon_sym_COMMA,
  [521] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(5), 1,
      sym__whitespace,
    ACTIONS(103), 2,
      anon_sym_LF,
      anon_sym_COMMA,
  [532] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(5), 1,
      sym__whitespace,
    ACTIONS(105), 2,
      anon_sym_LF,
      anon_sym_COMMA,
  [543] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(5), 1,
      sym__whitespace,
    ACTIONS(107), 1,
      anon_sym_LF,
    ACTIONS(109), 1,
      anon_sym_COMMA,
  [556] = 2,
    ACTIONS(111), 1,
      anon_sym_RPAREN,
    ACTIONS(3), 2,
      sym_comment,
      sym__whitespace,
  [564] = 2,
    ACTIONS(113), 1,
      anon_sym_RPAREN,
    ACTIONS(3), 2,
      sym_comment,
      sym__whitespace,
  [572] = 2,
    ACTIONS(115), 1,
      anon_sym_LPAREN,
    ACTIONS(3), 2,
      sym_comment,
      sym__whitespace,
  [580] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(5), 1,
      sym__whitespace,
    ACTIONS(117), 1,
      anon_sym_LF,
  [590] = 2,
    ACTIONS(119), 1,
      aux_sym_constant_hex_token1,
    ACTIONS(3), 2,
      sym_comment,
      sym__whitespace,
  [598] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(5), 1,
      sym__whitespace,
    ACTIONS(121), 1,
      anon_sym_LF,
  [608] = 2,
    ACTIONS(123), 1,
      anon_sym_RPAREN,
    ACTIONS(3), 2,
      sym_comment,
      sym__whitespace,
  [616] = 2,
    ACTIONS(125), 1,
      anon_sym_RPAREN,
    ACTIONS(3), 2,
      sym_comment,
      sym__whitespace,
  [624] = 2,
    ACTIONS(127), 1,
      anon_sym_LPAREN,
    ACTIONS(3), 2,
      sym_comment,
      sym__whitespace,
  [632] = 2,
    ACTIONS(62), 1,
      anon_sym_RPAREN,
    ACTIONS(3), 2,
      sym_comment,
      sym__whitespace,
  [640] = 2,
    ACTIONS(103), 1,
      anon_sym_RPAREN,
    ACTIONS(3), 2,
      sym_comment,
      sym__whitespace,
  [648] = 2,
    ACTIONS(85), 1,
      anon_sym_RPAREN,
    ACTIONS(3), 2,
      sym_comment,
      sym__whitespace,
  [656] = 2,
    ACTIONS(87), 1,
      anon_sym_RPAREN,
    ACTIONS(3), 2,
      sym_comment,
      sym__whitespace,
  [664] = 2,
    ACTIONS(129), 1,
      ts_builtin_sym_end,
    ACTIONS(3), 2,
      sym_comment,
      sym__whitespace,
  [672] = 2,
    ACTIONS(131), 1,
      aux_sym_constant_hex_token1,
    ACTIONS(3), 2,
      sym_comment,
      sym__whitespace,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 42,
  [SMALL_STATE(4)] = 79,
  [SMALL_STATE(5)] = 116,
  [SMALL_STATE(6)] = 146,
  [SMALL_STATE(7)] = 171,
  [SMALL_STATE(8)] = 196,
  [SMALL_STATE(9)] = 221,
  [SMALL_STATE(10)] = 244,
  [SMALL_STATE(11)] = 267,
  [SMALL_STATE(12)] = 280,
  [SMALL_STATE(13)] = 294,
  [SMALL_STATE(14)] = 306,
  [SMALL_STATE(15)] = 322,
  [SMALL_STATE(16)] = 336,
  [SMALL_STATE(17)] = 352,
  [SMALL_STATE(18)] = 366,
  [SMALL_STATE(19)] = 380,
  [SMALL_STATE(20)] = 396,
  [SMALL_STATE(21)] = 408,
  [SMALL_STATE(22)] = 420,
  [SMALL_STATE(23)] = 431,
  [SMALL_STATE(24)] = 444,
  [SMALL_STATE(25)] = 455,
  [SMALL_STATE(26)] = 466,
  [SMALL_STATE(27)] = 477,
  [SMALL_STATE(28)] = 488,
  [SMALL_STATE(29)] = 499,
  [SMALL_STATE(30)] = 510,
  [SMALL_STATE(31)] = 521,
  [SMALL_STATE(32)] = 532,
  [SMALL_STATE(33)] = 543,
  [SMALL_STATE(34)] = 556,
  [SMALL_STATE(35)] = 564,
  [SMALL_STATE(36)] = 572,
  [SMALL_STATE(37)] = 580,
  [SMALL_STATE(38)] = 590,
  [SMALL_STATE(39)] = 598,
  [SMALL_STATE(40)] = 608,
  [SMALL_STATE(41)] = 616,
  [SMALL_STATE(42)] = 624,
  [SMALL_STATE(43)] = 632,
  [SMALL_STATE(44)] = 640,
  [SMALL_STATE(45)] = 648,
  [SMALL_STATE(46)] = 656,
  [SMALL_STATE(47)] = 664,
  [SMALL_STATE(48)] = 672,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT_EXTRA(),
  [5] = {.entry = {.count = 1, .reusable = false}}, SHIFT_EXTRA(),
  [7] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(5),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(2),
  [15] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_instruction, 1),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [23] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [27] = {.entry = {.count = 1, .reusable = false}}, SHIFT(13),
  [29] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_directive, 1),
  [31] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [33] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2),
  [35] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(37),
  [38] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(5),
  [41] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(2),
  [44] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1),
  [46] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [48] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [50] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [52] = {.entry = {.count = 1, .reusable = false}}, SHIFT(43),
  [54] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [56] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__root, 2),
  [58] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__root, 2),
  [60] = {.entry = {.count = 1, .reusable = false}}, SHIFT(20),
  [62] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_constant, 1),
  [64] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_directive, 2),
  [66] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [68] = {.entry = {.count = 1, .reusable = false}}, SHIFT(45),
  [70] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_directive_repeat1, 2),
  [72] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_directive_repeat1, 2), SHIFT_REPEAT(7),
  [75] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_relocation, 5),
  [77] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [79] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_operand, 1),
  [81] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [83] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_directive, 3),
  [85] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_constant, 2),
  [87] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_constant_hex, 2),
  [89] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_operand_parens, 4),
  [91] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_instruction, 2),
  [93] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [95] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_relocation, 8),
  [97] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_directive_arg, 1),
  [99] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [101] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [103] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_operand_no_parens, 1),
  [105] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_operand_parens, 3),
  [107] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_instruction, 4),
  [109] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [111] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [113] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [115] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_reloc_symbol, 1),
  [117] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [119] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [121] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_instruction, 6),
  [123] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [125] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [127] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [129] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [131] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_riscvasm(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif

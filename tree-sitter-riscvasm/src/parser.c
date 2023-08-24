#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 48
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 28
#define ALIAS_COUNT 0
#define TOKEN_COUNT 16
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 1
#define MAX_ALIAS_SEQUENCE_LENGTH 8
#define PRODUCTION_ID_COUNT 2

enum {
  sym_identifier = 1,
  anon_sym_LF = 2,
  anon_sym_COMMA = 3,
  sym_directive_id = 4,
  aux_sym_directive_arg_token1 = 5,
  anon_sym_PERCENT = 6,
  anon_sym_LPAREN = 7,
  anon_sym_RPAREN = 8,
  anon_sym_DASH = 9,
  anon_sym_0x = 10,
  aux_sym_constant_hex_token1 = 11,
  sym_constant_dec = 12,
  sym_label = 13,
  sym_instr_id = 14,
  sym_comment = 15,
  sym_source_file = 16,
  sym_directive = 17,
  sym_directive_arg = 18,
  sym_relocation = 19,
  sym_constant = 20,
  sym_constant_hex = 21,
  sym_instruction = 22,
  sym_operand = 23,
  sym_operand_parens = 24,
  sym_operand_no_parens = 25,
  aux_sym_source_file_repeat1 = 26,
  aux_sym_directive_repeat1 = 27,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_identifier] = "identifier",
  [anon_sym_LF] = "\n",
  [anon_sym_COMMA] = ",",
  [sym_directive_id] = "directive_id",
  [aux_sym_directive_arg_token1] = "directive_arg_token1",
  [anon_sym_PERCENT] = "%",
  [anon_sym_LPAREN] = "(",
  [anon_sym_RPAREN] = ")",
  [anon_sym_DASH] = "-",
  [anon_sym_0x] = "0x",
  [aux_sym_constant_hex_token1] = "constant_hex_token1",
  [sym_constant_dec] = "constant_dec",
  [sym_label] = "label",
  [sym_instr_id] = "instr_id",
  [sym_comment] = "comment",
  [sym_source_file] = "source_file",
  [sym_directive] = "directive",
  [sym_directive_arg] = "directive_arg",
  [sym_relocation] = "relocation",
  [sym_constant] = "constant",
  [sym_constant_hex] = "constant_hex",
  [sym_instruction] = "instruction",
  [sym_operand] = "operand",
  [sym_operand_parens] = "operand_parens",
  [sym_operand_no_parens] = "operand_no_parens",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym_directive_repeat1] = "directive_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_identifier] = sym_identifier,
  [anon_sym_LF] = anon_sym_LF,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [sym_directive_id] = sym_directive_id,
  [aux_sym_directive_arg_token1] = aux_sym_directive_arg_token1,
  [anon_sym_PERCENT] = anon_sym_PERCENT,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [anon_sym_DASH] = anon_sym_DASH,
  [anon_sym_0x] = anon_sym_0x,
  [aux_sym_constant_hex_token1] = aux_sym_constant_hex_token1,
  [sym_constant_dec] = sym_constant_dec,
  [sym_label] = sym_label,
  [sym_instr_id] = sym_instr_id,
  [sym_comment] = sym_comment,
  [sym_source_file] = sym_source_file,
  [sym_directive] = sym_directive,
  [sym_directive_arg] = sym_directive_arg,
  [sym_relocation] = sym_relocation,
  [sym_constant] = sym_constant,
  [sym_constant_hex] = sym_constant_hex,
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
  [sym_identifier] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_LF] = {
    .visible = true,
    .named = false,
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
  [sym_label] = {
    .visible = true,
    .named = true,
  },
  [sym_instr_id] = {
    .visible = true,
    .named = true,
  },
  [sym_comment] = {
    .visible = true,
    .named = true,
  },
  [sym_source_file] = {
    .visible = true,
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

enum {
  field_relocation = 1,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_relocation] = "relocation",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 1},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_relocation, 1},
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
  [14] = 12,
  [15] = 15,
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
  [35] = 20,
  [36] = 36,
  [37] = 37,
  [38] = 38,
  [39] = 39,
  [40] = 40,
  [41] = 21,
  [42] = 15,
  [43] = 25,
  [44] = 44,
  [45] = 45,
  [46] = 46,
  [47] = 36,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  switch (state) {
    case 0:
      if (eof) ADVANCE(11);
      if (lookahead == '"') ADVANCE(3);
      if (lookahead == '#') ADVANCE(33);
      if (lookahead == '%') ADVANCE(17);
      if (lookahead == '(') ADVANCE(18);
      if (lookahead == ')') ADVANCE(19);
      if (lookahead == ',') ADVANCE(13);
      if (lookahead == '-') ADVANCE(20);
      if (lookahead == '.') ADVANCE(29);
      if (lookahead == '/') ADVANCE(5);
      if (lookahead == '0') ADVANCE(22);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(23);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(24);
      if (('G' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('g' <= lookahead && lookahead <= 'z')) ADVANCE(30);
      END_STATE();
    case 1:
      if (lookahead == '\n') ADVANCE(12);
      if (lookahead == '"') ADVANCE(3);
      if (lookahead == '#') ADVANCE(33);
      if (lookahead == '%') ADVANCE(17);
      if (lookahead == '(') ADVANCE(18);
      if (lookahead == ',') ADVANCE(13);
      if (lookahead == '-') ADVANCE(20);
      if (lookahead == '/') ADVANCE(5);
      if (lookahead == '0') ADVANCE(26);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(1)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(27);
      if (lookahead == '.' ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(30);
      END_STATE();
    case 2:
      if (lookahead == '"') ADVANCE(3);
      if (lookahead == '#') ADVANCE(33);
      if (lookahead == '%') ADVANCE(17);
      if (lookahead == '(') ADVANCE(18);
      if (lookahead == '-') ADVANCE(20);
      if (lookahead == '/') ADVANCE(5);
      if (lookahead == '0') ADVANCE(26);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(2)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(27);
      if (lookahead == '.' ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(30);
      END_STATE();
    case 3:
      if (lookahead == '"') ADVANCE(16);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(3);
      END_STATE();
    case 4:
      if (lookahead == '#') ADVANCE(33);
      if (lookahead == '/') ADVANCE(5);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(4)
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(25);
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
      if (lookahead == ':') ADVANCE(28);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(14);
      END_STATE();
    case 9:
      if (lookahead == ':') ADVANCE(28);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(9);
      END_STATE();
    case 10:
      if (eof) ADVANCE(11);
      if (lookahead == '#') ADVANCE(33);
      if (lookahead == '.') ADVANCE(8);
      if (lookahead == '/') ADVANCE(5);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(10)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(9);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(31);
      END_STATE();
    case 11:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 12:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(12);
      END_STATE();
    case 13:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 14:
      ACCEPT_TOKEN(sym_directive_id);
      if (lookahead == ':') ADVANCE(28);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(14);
      END_STATE();
    case 15:
      ACCEPT_TOKEN(sym_directive_id);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(15);
      END_STATE();
    case 16:
      ACCEPT_TOKEN(aux_sym_directive_arg_token1);
      if (lookahead == '"') ADVANCE(16);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(3);
      END_STATE();
    case 17:
      ACCEPT_TOKEN(anon_sym_PERCENT);
      END_STATE();
    case 18:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 19:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 20:
      ACCEPT_TOKEN(anon_sym_DASH);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(anon_sym_0x);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(aux_sym_constant_hex_token1);
      if (lookahead == 'x') ADVANCE(21);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(23);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(25);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(aux_sym_constant_hex_token1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(23);
      if (('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(25);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(aux_sym_constant_hex_token1);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(24);
      if (lookahead == '.' ||
          ('G' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('g' <= lookahead && lookahead <= 'z')) ADVANCE(30);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(aux_sym_constant_hex_token1);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(25);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(sym_constant_dec);
      if (lookahead == 'x') ADVANCE(21);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(27);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(sym_constant_dec);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(27);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(sym_label);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(15);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(30);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(sym_instr_id);
      if (lookahead == ':') ADVANCE(28);
      if (lookahead == '.' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(31);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(sym_comment);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(sym_comment);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(33);
      END_STATE();
    default:
      return false;
  }
}

static bool ts_lex_keywords(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  switch (state) {
    case 0:
      ACCEPT_TOKEN(ts_builtin_sym_end);
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
  [6] = {.lex_state = 2},
  [7] = {.lex_state = 10},
  [8] = {.lex_state = 10},
  [9] = {.lex_state = 2},
  [10] = {.lex_state = 2},
  [11] = {.lex_state = 10},
  [12] = {.lex_state = 2},
  [13] = {.lex_state = 1},
  [14] = {.lex_state = 2},
  [15] = {.lex_state = 1},
  [16] = {.lex_state = 1},
  [17] = {.lex_state = 1},
  [18] = {.lex_state = 1},
  [19] = {.lex_state = 1},
  [20] = {.lex_state = 1},
  [21] = {.lex_state = 1},
  [22] = {.lex_state = 2},
  [23] = {.lex_state = 1},
  [24] = {.lex_state = 1},
  [25] = {.lex_state = 1},
  [26] = {.lex_state = 2},
  [27] = {.lex_state = 1},
  [28] = {.lex_state = 1},
  [29] = {.lex_state = 1},
  [30] = {.lex_state = 1},
  [31] = {.lex_state = 1},
  [32] = {.lex_state = 1},
  [33] = {.lex_state = 1},
  [34] = {.lex_state = 0},
  [35] = {.lex_state = 0},
  [36] = {.lex_state = 4},
  [37] = {.lex_state = 0},
  [38] = {.lex_state = 1},
  [39] = {.lex_state = 0},
  [40] = {.lex_state = 0},
  [41] = {.lex_state = 0},
  [42] = {.lex_state = 0},
  [43] = {.lex_state = 0},
  [44] = {.lex_state = 0},
  [45] = {.lex_state = 0},
  [46] = {.lex_state = 2},
  [47] = {.lex_state = 4},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_identifier] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [sym_directive_id] = ACTIONS(1),
    [aux_sym_directive_arg_token1] = ACTIONS(1),
    [anon_sym_PERCENT] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [anon_sym_DASH] = ACTIONS(1),
    [anon_sym_0x] = ACTIONS(1),
    [aux_sym_constant_hex_token1] = ACTIONS(1),
    [sym_constant_dec] = ACTIONS(1),
    [sym_instr_id] = ACTIONS(1),
    [sym_comment] = ACTIONS(3),
  },
  [1] = {
    [sym_source_file] = STATE(39),
    [sym_directive] = STATE(33),
    [sym_instruction] = STATE(33),
    [aux_sym_source_file_repeat1] = STATE(8),
    [ts_builtin_sym_end] = ACTIONS(5),
    [sym_directive_id] = ACTIONS(7),
    [sym_label] = ACTIONS(9),
    [sym_instr_id] = ACTIONS(11),
    [sym_comment] = ACTIONS(3),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 12,
    ACTIONS(13), 1,
      sym_identifier,
    ACTIONS(15), 1,
      anon_sym_LF,
    ACTIONS(17), 1,
      anon_sym_PERCENT,
    ACTIONS(19), 1,
      anon_sym_LPAREN,
    ACTIONS(21), 1,
      anon_sym_DASH,
    ACTIONS(23), 1,
      anon_sym_0x,
    ACTIONS(25), 1,
      sym_constant_dec,
    ACTIONS(27), 1,
      sym_comment,
    STATE(15), 1,
      sym_constant_hex,
    STATE(18), 1,
      sym_constant,
    STATE(30), 1,
      sym_operand,
    STATE(28), 3,
      sym_relocation,
      sym_operand_parens,
      sym_operand_no_parens,
  [39] = 11,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(25), 1,
      sym_constant_dec,
    ACTIONS(29), 1,
      sym_identifier,
    ACTIONS(31), 1,
      anon_sym_PERCENT,
    ACTIONS(33), 1,
      anon_sym_LPAREN,
    ACTIONS(35), 1,
      anon_sym_DASH,
    ACTIONS(37), 1,
      anon_sym_0x,
    STATE(15), 1,
      sym_constant_hex,
    STATE(18), 1,
      sym_constant,
    STATE(38), 1,
      sym_operand,
    STATE(28), 3,
      sym_relocation,
      sym_operand_parens,
      sym_operand_no_parens,
  [75] = 11,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(25), 1,
      sym_constant_dec,
    ACTIONS(29), 1,
      sym_identifier,
    ACTIONS(31), 1,
      anon_sym_PERCENT,
    ACTIONS(33), 1,
      anon_sym_LPAREN,
    ACTIONS(35), 1,
      anon_sym_DASH,
    ACTIONS(37), 1,
      anon_sym_0x,
    STATE(15), 1,
      sym_constant_hex,
    STATE(18), 1,
      sym_constant,
    STATE(27), 1,
      sym_operand,
    STATE(28), 3,
      sym_relocation,
      sym_operand_parens,
      sym_operand_no_parens,
  [111] = 8,
    ACTIONS(21), 1,
      anon_sym_DASH,
    ACTIONS(23), 1,
      anon_sym_0x,
    ACTIONS(25), 1,
      sym_constant_dec,
    ACTIONS(27), 1,
      sym_comment,
    ACTIONS(41), 1,
      anon_sym_LF,
    STATE(15), 1,
      sym_constant_hex,
    ACTIONS(39), 2,
      aux_sym_directive_arg_token1,
      sym_identifier,
    STATE(13), 2,
      sym_directive_arg,
      sym_constant,
  [138] = 7,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(25), 1,
      sym_constant_dec,
    ACTIONS(35), 1,
      anon_sym_DASH,
    ACTIONS(37), 1,
      anon_sym_0x,
    STATE(15), 1,
      sym_constant_hex,
    ACTIONS(43), 2,
      aux_sym_directive_arg_token1,
      sym_identifier,
    STATE(29), 2,
      sym_directive_arg,
      sym_constant,
  [162] = 7,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(45), 1,
      ts_builtin_sym_end,
    ACTIONS(47), 1,
      sym_directive_id,
    ACTIONS(50), 1,
      sym_label,
    ACTIONS(53), 1,
      sym_instr_id,
    STATE(7), 1,
      aux_sym_source_file_repeat1,
    STATE(33), 2,
      sym_directive,
      sym_instruction,
  [185] = 7,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(7), 1,
      sym_directive_id,
    ACTIONS(9), 1,
      sym_label,
    ACTIONS(11), 1,
      sym_instr_id,
    ACTIONS(56), 1,
      ts_builtin_sym_end,
    STATE(7), 1,
      aux_sym_source_file_repeat1,
    STATE(33), 2,
      sym_directive,
      sym_instruction,
  [208] = 7,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(58), 1,
      sym_identifier,
    ACTIONS(60), 1,
      anon_sym_DASH,
    ACTIONS(62), 1,
      anon_sym_0x,
    ACTIONS(64), 1,
      sym_constant_dec,
    STATE(34), 1,
      sym_constant,
    STATE(42), 1,
      sym_constant_hex,
  [230] = 7,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(60), 1,
      anon_sym_DASH,
    ACTIONS(62), 1,
      anon_sym_0x,
    ACTIONS(64), 1,
      sym_constant_dec,
    ACTIONS(66), 1,
      sym_identifier,
    STATE(42), 1,
      sym_constant_hex,
    STATE(45), 1,
      sym_constant,
  [252] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(45), 2,
      ts_builtin_sym_end,
      sym_label,
    ACTIONS(68), 2,
      sym_directive_id,
      sym_instr_id,
  [264] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(37), 1,
      anon_sym_0x,
    ACTIONS(70), 1,
      sym_constant_dec,
    STATE(20), 1,
      sym_constant_hex,
  [277] = 4,
    ACTIONS(27), 1,
      sym_comment,
    ACTIONS(72), 1,
      anon_sym_LF,
    ACTIONS(74), 1,
      anon_sym_COMMA,
    STATE(19), 1,
      aux_sym_directive_repeat1,
  [290] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(62), 1,
      anon_sym_0x,
    ACTIONS(76), 1,
      sym_constant_dec,
    STATE(35), 1,
      sym_constant_hex,
  [303] = 3,
    ACTIONS(27), 1,
      sym_comment,
    ACTIONS(78), 1,
      anon_sym_LF,
    ACTIONS(80), 2,
      anon_sym_COMMA,
      anon_sym_LPAREN,
  [314] = 4,
    ACTIONS(27), 1,
      sym_comment,
    ACTIONS(82), 1,
      anon_sym_LF,
    ACTIONS(84), 1,
      anon_sym_COMMA,
    ACTIONS(86), 1,
      anon_sym_LPAREN,
  [327] = 4,
    ACTIONS(27), 1,
      sym_comment,
    ACTIONS(88), 1,
      anon_sym_LF,
    ACTIONS(90), 1,
      anon_sym_COMMA,
    STATE(17), 1,
      aux_sym_directive_repeat1,
  [340] = 4,
    ACTIONS(27), 1,
      sym_comment,
    ACTIONS(93), 1,
      anon_sym_LF,
    ACTIONS(95), 1,
      anon_sym_COMMA,
    ACTIONS(97), 1,
      anon_sym_LPAREN,
  [353] = 4,
    ACTIONS(27), 1,
      sym_comment,
    ACTIONS(74), 1,
      anon_sym_COMMA,
    ACTIONS(99), 1,
      anon_sym_LF,
    STATE(17), 1,
      aux_sym_directive_repeat1,
  [366] = 3,
    ACTIONS(27), 1,
      sym_comment,
    ACTIONS(101), 1,
      anon_sym_LF,
    ACTIONS(103), 2,
      anon_sym_COMMA,
      anon_sym_LPAREN,
  [377] = 3,
    ACTIONS(27), 1,
      sym_comment,
    ACTIONS(105), 1,
      anon_sym_LF,
    ACTIONS(107), 2,
      anon_sym_COMMA,
      anon_sym_LPAREN,
  [388] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(109), 1,
      sym_identifier,
    STATE(37), 1,
      sym_operand_no_parens,
  [398] = 3,
    ACTIONS(27), 1,
      sym_comment,
    ACTIONS(111), 1,
      anon_sym_LF,
    ACTIONS(113), 1,
      anon_sym_COMMA,
  [408] = 3,
    ACTIONS(27), 1,
      sym_comment,
    ACTIONS(115), 1,
      anon_sym_LF,
    ACTIONS(117), 1,
      anon_sym_COMMA,
  [418] = 3,
    ACTIONS(27), 1,
      sym_comment,
    ACTIONS(119), 1,
      anon_sym_LF,
    ACTIONS(121), 1,
      anon_sym_COMMA,
  [428] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(109), 1,
      sym_identifier,
    STATE(44), 1,
      sym_operand_no_parens,
  [438] = 3,
    ACTIONS(27), 1,
      sym_comment,
    ACTIONS(123), 1,
      anon_sym_LF,
    ACTIONS(125), 1,
      anon_sym_COMMA,
  [448] = 3,
    ACTIONS(27), 1,
      sym_comment,
    ACTIONS(93), 1,
      anon_sym_LF,
    ACTIONS(95), 1,
      anon_sym_COMMA,
  [458] = 3,
    ACTIONS(27), 1,
      sym_comment,
    ACTIONS(88), 1,
      anon_sym_LF,
    ACTIONS(127), 1,
      anon_sym_COMMA,
  [468] = 3,
    ACTIONS(27), 1,
      sym_comment,
    ACTIONS(129), 1,
      anon_sym_LF,
    ACTIONS(131), 1,
      anon_sym_COMMA,
  [478] = 3,
    ACTIONS(27), 1,
      sym_comment,
    ACTIONS(133), 1,
      anon_sym_LF,
    ACTIONS(135), 1,
      anon_sym_COMMA,
  [488] = 3,
    ACTIONS(27), 1,
      sym_comment,
    ACTIONS(137), 1,
      anon_sym_LF,
    ACTIONS(139), 1,
      anon_sym_COMMA,
  [498] = 2,
    ACTIONS(27), 1,
      sym_comment,
    ACTIONS(141), 1,
      anon_sym_LF,
  [505] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(143), 1,
      anon_sym_RPAREN,
  [512] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(101), 1,
      anon_sym_RPAREN,
  [519] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(145), 1,
      aux_sym_constant_hex_token1,
  [526] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(147), 1,
      anon_sym_RPAREN,
  [533] = 2,
    ACTIONS(27), 1,
      sym_comment,
    ACTIONS(149), 1,
      anon_sym_LF,
  [540] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(151), 1,
      ts_builtin_sym_end,
  [547] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(153), 1,
      anon_sym_LPAREN,
  [554] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(105), 1,
      anon_sym_RPAREN,
  [561] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(78), 1,
      anon_sym_RPAREN,
  [568] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(119), 1,
      anon_sym_RPAREN,
  [575] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(155), 1,
      anon_sym_RPAREN,
  [582] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(157), 1,
      anon_sym_RPAREN,
  [589] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(159), 1,
      sym_identifier,
  [596] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(161), 1,
      aux_sym_constant_hex_token1,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 39,
  [SMALL_STATE(4)] = 75,
  [SMALL_STATE(5)] = 111,
  [SMALL_STATE(6)] = 138,
  [SMALL_STATE(7)] = 162,
  [SMALL_STATE(8)] = 185,
  [SMALL_STATE(9)] = 208,
  [SMALL_STATE(10)] = 230,
  [SMALL_STATE(11)] = 252,
  [SMALL_STATE(12)] = 264,
  [SMALL_STATE(13)] = 277,
  [SMALL_STATE(14)] = 290,
  [SMALL_STATE(15)] = 303,
  [SMALL_STATE(16)] = 314,
  [SMALL_STATE(17)] = 327,
  [SMALL_STATE(18)] = 340,
  [SMALL_STATE(19)] = 353,
  [SMALL_STATE(20)] = 366,
  [SMALL_STATE(21)] = 377,
  [SMALL_STATE(22)] = 388,
  [SMALL_STATE(23)] = 398,
  [SMALL_STATE(24)] = 408,
  [SMALL_STATE(25)] = 418,
  [SMALL_STATE(26)] = 428,
  [SMALL_STATE(27)] = 438,
  [SMALL_STATE(28)] = 448,
  [SMALL_STATE(29)] = 458,
  [SMALL_STATE(30)] = 468,
  [SMALL_STATE(31)] = 478,
  [SMALL_STATE(32)] = 488,
  [SMALL_STATE(33)] = 498,
  [SMALL_STATE(34)] = 505,
  [SMALL_STATE(35)] = 512,
  [SMALL_STATE(36)] = 519,
  [SMALL_STATE(37)] = 526,
  [SMALL_STATE(38)] = 533,
  [SMALL_STATE(39)] = 540,
  [SMALL_STATE(40)] = 547,
  [SMALL_STATE(41)] = 554,
  [SMALL_STATE(42)] = 561,
  [SMALL_STATE(43)] = 568,
  [SMALL_STATE(44)] = 575,
  [SMALL_STATE(45)] = 582,
  [SMALL_STATE(46)] = 589,
  [SMALL_STATE(47)] = 596,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT_EXTRA(),
  [5] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(5),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(2),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(25),
  [15] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_instruction, 1),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(46),
  [19] = {.entry = {.count = 1, .reusable = false}}, SHIFT(22),
  [21] = {.entry = {.count = 1, .reusable = false}}, SHIFT(12),
  [23] = {.entry = {.count = 1, .reusable = false}}, SHIFT(36),
  [25] = {.entry = {.count = 1, .reusable = false}}, SHIFT(15),
  [27] = {.entry = {.count = 1, .reusable = false}}, SHIFT_EXTRA(),
  [29] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [31] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [33] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [35] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [37] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [39] = {.entry = {.count = 1, .reusable = false}}, SHIFT(24),
  [41] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_directive, 1),
  [43] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [45] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2),
  [47] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(5),
  [50] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(33),
  [53] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(2),
  [56] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1),
  [58] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [60] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [62] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [64] = {.entry = {.count = 1, .reusable = false}}, SHIFT(42),
  [66] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [68] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2),
  [70] = {.entry = {.count = 1, .reusable = false}}, SHIFT(20),
  [72] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_directive, 2),
  [74] = {.entry = {.count = 1, .reusable = false}}, SHIFT(6),
  [76] = {.entry = {.count = 1, .reusable = false}}, SHIFT(35),
  [78] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_constant, 1),
  [80] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_constant, 1),
  [82] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_relocation, 5, .production_id = 1),
  [84] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_relocation, 5, .production_id = 1),
  [86] = {.entry = {.count = 1, .reusable = false}}, SHIFT(9),
  [88] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_directive_repeat1, 2),
  [90] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_directive_repeat1, 2), SHIFT_REPEAT(6),
  [93] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_operand, 1),
  [95] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_operand, 1),
  [97] = {.entry = {.count = 1, .reusable = false}}, SHIFT(26),
  [99] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_directive, 3),
  [101] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_constant, 2),
  [103] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_constant, 2),
  [105] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_constant_hex, 2),
  [107] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_constant_hex, 2),
  [109] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [111] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_relocation, 8, .production_id = 1),
  [113] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_relocation, 8, .production_id = 1),
  [115] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_directive_arg, 1),
  [117] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_directive_arg, 1),
  [119] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_operand_no_parens, 1),
  [121] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_operand_no_parens, 1),
  [123] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_instruction, 4),
  [125] = {.entry = {.count = 1, .reusable = false}}, SHIFT(3),
  [127] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_directive_repeat1, 2),
  [129] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_instruction, 2),
  [131] = {.entry = {.count = 1, .reusable = false}}, SHIFT(4),
  [133] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_operand_parens, 3),
  [135] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_operand_parens, 3),
  [137] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_operand_parens, 4),
  [139] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_operand_parens, 4),
  [141] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [143] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [145] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [147] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [149] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_instruction, 6),
  [151] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [153] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [155] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [157] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [159] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [161] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
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
    .field_names = ts_field_names,
    .field_map_slices = ts_field_map_slices,
    .field_map_entries = ts_field_map_entries,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .keyword_lex_fn = ts_lex_keywords,
    .keyword_capture_token = sym_identifier,
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif

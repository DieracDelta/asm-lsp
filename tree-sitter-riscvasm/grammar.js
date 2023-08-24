/* eslint-disable-next-line spaced-comment */
/// <reference types="tree-sitter-cli/dsl" />
// @ts-check

// TODO we also presumably want a parser for linker scripts...
//
// resources:
//   - https://austinhenley.com/blog/parsingriscv.html
//   - https://michaeljclark.github.io/asm.html
//   - the ISA itself...
const PREC = {
  unary: 1,
  binary: 2,
  ternary: 3,
}

module.exports = grammar({
  name: 'riscvasm',

  extras: $ => [
    $.comment,
    /\s/,
  ],

  word: $ => $.identifier,

  rules: {
    source_file: $ => repeat(seq(
      choice($.label, $.instruction, $.directive),
      '\n',
    )),

    directive: $ => seq(
      $.directive_id,
      optional(seq(
        choice($.directive_arg, $.constant),
        repeat(seq(",", choice($.directive_arg, $.constant)))
      )),
    ),

    directive_id: _ => token(/[.][a-zA-Z0-9_.]+/),

    directive_arg: $ => choice($.identifier, /".*"/),

    relocation: $ => seq(
      '%',
      field('relocation', $.identifier),
      '(',
      choice($.identifier, $.constant),
      ')',
      optional(seq('(', choice($.identifier, $.constant), ')')),
    ),

    constant: $ => seq(optional("-"), choice($.constant_hex, $.constant_dec)),

    constant_hex: _ => seq("0x", /[0-9A-Fa-f]+/),

    constant_dec: _ => /[0-9]+/,

    instruction: $ => seq(
      $.instr_id,
      optional(seq(
        $.operand,
        optional(seq(
          ",",
          $.operand,
          optional(seq(",", $.operand)),
        )),
      )),
    ),

    operand: $ => prec.right(choice($.operand_parens, $.operand_no_parens, $.relocation, $.constant)),

    operand_parens: $ => seq(optional($.constant), "(", $.operand_no_parens, ")"),

    operand_no_parens: $ => $.identifier,

    label: _ => token(/[a-zA-Z0-9_.]+:/),

    // identifier must begin with letter or dot
    identifier: _ => token(/[a-zA-Z_.][a-zA-Z0-9_.]*/),

    // identifier must not begin with dot
    instr_id: _ => token(/[a-zA-Z_][a-zA-Z0-9_.]*/),

    comment: _ => token(choice(
      seq('#', /.*/),
      seq('//', /.*/),
      seq(
        '/*',
        /[^*]*\*+([^/*][^*]*\*+)*/,
          '/'
        )
    )),

    // pseudo_instuction: $ => "",
    //
    //
    // comment: $ => "",
    //
    // directive: $ => "",

    // reloc_symbol: $ => choice(
    //   "hi",
    //   "lo",
    //   "pcrel_hi",
    //   "pcrel_lo",
    //   "tprel_hi",
    //   "tprel_lo",
    //   "tprel_add"
    // ),

    // binary_operator: $ => choice(
    //   "li",
    //   "la",
    //   "mv",
    //   "not",
    //   "neg",
    //   "negw",
    //   "sext.w",
    //   "seqz",
    //   "snez",
    //   "sltz",
    //   "sgtz",
    //   "fmv.s",
    //   "fabs.s",
    //   "fneg.s",
    //   "fmv.d",
    //   "fabs.d",
    //   "fneg.d",
    //   "beqz",
    //   "bnez",
    //   "blez",
    //   "bgez",
    //   "bltz",
    //   "bgtz"
    // ),
  }
});

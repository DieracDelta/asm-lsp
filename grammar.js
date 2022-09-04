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

const OP_DELIMITER = ",";

module.exports = grammar({
  name: 'riscvasm',

  extras: $ => [
    $.comment,
    $._whitespace,
  ],

  rules: {
    source_file: $ => repeat($._root),

    _root: $ => seq(choice($.label, $.instruction, $.directive), '\n'),

    label: $ => /[a-zA-Z0-9_.]+:/,

    directive: $ => seq($.directive_id, optional(seq(choice($.directive_arg, $.constant), repeat(seq(OP_DELIMITER, choice($.directive_arg, $.constant)))))),

    directive_id: $ => /[.][a-zA-Z0-9_.]+/,

    directive_arg: $ => choice($.identifier, /".*"/),

    relocation: $ => seq('%', $.reloc_symbol, '(', choice($.identifier, $.constant), ')', optional(seq('(', choice($.identifier, $.constant), ')'))),

    // identifier must begin with letter or dot
    identifier: $ => /[a-zA-Z_.][a-zA-Z0-9_.]*/,

    // identifier must not begin with dot
    instr_id: $ => /[a-zA-Z_][a-zA-Z0-9_.]*/,

    constant: $ => seq(optional("-"), choice($.constant_hex, $.constant_dec)),

    constant_hex: $ => seq("0x", /[0-9A-Fa-f]+/),

    constant_dec: $ => /[0-9]+/,

    reloc_symbol: $ => $.identifier,

    instruction: $ => seq($.instr_id,
      optional(
        seq($.operand, optional(
          seq(OP_DELIMITER, $.operand,
            optional(seq(OP_DELIMITER, $.operand))))))),

    operand: $ => prec.right(choice($.operand_parens, $.operand_no_parens, $.relocation, $.constant)),

    operand_parens: $ => seq(optional($.constant), "(", $.operand_no_parens, ")"),

    operand_no_parens: $ => $.identifier,


    comment: $ => token(choice(
      seq('#', /.*/),
      seq('//', /.*/),
      seq(
        '/*',
        /[^*]*\*+([^/*][^*]*\*+)*/,
          '/'
        )
      )),

      _whitespace: $ => token(/\s/),

    //
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

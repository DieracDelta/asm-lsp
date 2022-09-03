// TODO we also presumably want a parser for linker scripts...
//
// resources:
//   - https://austinhenley.com/blog/parsingriscv.html
//   - https://michaeljclark.github.io/asm.html
//   - the ISA itself...

module.exports = grammar({
  name: 'riscvasm',

  rules: {
    source_file: $ => repeat($._root),

    _root: $ => seq(choice($.label), '\n'),

    label: $ => seq($.identifier, ':'),

    identifier: $ => /[a-zA-Z0-9_]+/,

  }
});

# What is this?

Both a treesitter grammar and a LSP server implementaiton for RISC-V assembly. THe LSP server is implemented with Tower-lsp and tokio, and uses the treesitter grammar under the hood.


The treesitter grammar lives in in the `tree-sitter-riscvasm` subdirectory of the project root.

The LSP server implementation lives in the `lsp` subdirectory of the project root.

# Build

The only build requirement is having `nix` installed with `flakes` enabled.


To build, run:

```bash
nix develop -c just build
```

To test, run:

```bash
nix develop -c just test
```

# Text editor support

## Neovim + Lsp-Config

This is the only supported option for now. To enable, for now we spoof a different language server:

```lua
local util = require 'lspconfig.util'
    require'lspconfig'.efm.setup {
      cmd = { '$PATH_TO_LSP_EXECUTABLE' },
      filetypes = { 'asm' },
      root_dir = function(fname)
        return util.find_git_ancestor(fname) or vim.loop.os_homedir()
      end,
      settings = {},
      init_options = {},
    }
```

Note that you'll need to fill in the lsp path. [Example usage](https://github.com/DieracDelta/vimconfig/blob/master/modules/lsp.nix#L220).

Once more features are implemented, proper text editor support will be added.

# Features

- [x] Parser
- LSP
  - [ ] Documentation
  - [ ] Hover
  - [ ] Code Completion
  - [ ] Errors
  - [ ] Hints and Lints
- Integration with chatgpt
  - [ ] Overall suggestions displayed as hints
  - [ ] Append error information to error list
  - [ ] Completion suggestions
  - [ ] Caching of queries


default: build lint test

build:
  echo Building lsp...
  cargo build --release --workspace --examples --bins --tests

build_all:
  echo Building all...
  cd tree-sitter-riscvasm && tree-sitter generate && cd ..
  cargo build --release --workspace --examples --bins --tests

test:
  echo Testing...
  cargo test --release --workspace -- --nocapture --test-threads=1
  cd tree-sitter-riscvasm && tree-sitter test

clean:
  echo Cleaning...
  cargo clean

lint:
  echo Linting…
  cargo clippy --release --workspace --examples --bins --tests
  cargo fmt

fmt:
  cargo fmt

fix:
  cargo fix --allow-unstaged --allow-staged

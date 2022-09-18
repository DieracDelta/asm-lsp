default: build lint test

build:
  echo Building…
  cargo build --release --workspace --examples --bins --tests

test:
  echo Testing…
  cargo test --release --workspace -- --nocapture --test-threads=1
  cd tree-sitter-riscvasm && tree-sitter test

lint:
  echo Linting…
  cargo clippy --release --workspace --examples --bins --tests
  cargo fmt

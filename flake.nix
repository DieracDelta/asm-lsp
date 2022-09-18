{
  description = "Riscv ASM Tree-sitter grammar";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixpkgs-unstable";
    utils.url = "github:numtide/flake-utils";
    fenix = {
      url = "github:nix-community/fenix";
      inputs.nixpkgs.follows = "nixpkgs";
    };
  };

  outputs = { self, nixpkgs, utils, fenix }:
    utils.lib.eachDefaultSystem (system:
    let
        fenixStable = fenix.packages.${system}.stable.withComponents [ "cargo" "clippy" "rust-src" "rustc" "rustfmt" "llvm-tools-preview" ];
        CARGO_TARGET_DIR = "target_dirs/nix_rustc";
        rustOverlay = final: prev:
          {
            rustc = fenixStable;
            cargo = fenixStable;
            rust-src = fenixStable;
          };
        pkgs = import nixpkgs {
          inherit system;
          overlays = [
            rustOverlay
          ];
        };
        in {
          devShell = pkgs.mkShell {
            inherit CARGO_TARGET_DIR;
            LD_LIBRARY_PATH = "${pkgs.zlib}/lib";
            buildInputs =
              with pkgs; [
                zlib
                # for rust bindings
                fenixStable fenix.packages.${system}.rust-analyzer
                # tree-sitter-cli
                tree-sitter
                # for using wasm playground
                emscripten
                just
                nodejs_latest
              ] ++
              pkgs.lib.optionals stdenv.isDarwin [ darwin.apple_sdk.frameworks.Security pkgs.libiconv darwin.apple_sdk.frameworks.SystemConfiguration ];
          };
        }
    );
}

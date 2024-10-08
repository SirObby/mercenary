let
  nixpkgs = fetchTarball "https://github.com/NixOS/nixpkgs/tarball/nixos-23.11";
  pkgs = import nixpkgs { config = {}; overlays = []; };
in

pkgs.mkShellNoCC {
  packages = with pkgs; [
    clang
    cmake
    pkg-config
#    libpqxx
#    postgresql.lib
    postgresql
    json_c
    gdb
  ];
}

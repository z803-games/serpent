{
  inputs.nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";

  outputs = {
    self,
    nixpkgs,
  }: let
    system = "x86_64-linux";
    pkgs = import nixpkgs {inherit system;};

    gbdk = pkgs.stdenv.mkDerivation {
      pname = "gbdk";
      version = "4.5.0";

      src = pkgs.fetchzip {
        url = "https://github.com/gbdk-2020/gbdk-2020/releases/download/4.5.0/gbdk-linux64.tar.gz";
        hash = "sha256-SeLoKHRAAq+3xVog8kBV9hj2wrQ24JvOQml3A8p1Yyg=";
      };

      nativeBuildInputs = with pkgs; [
        autoPatchelfHook
        makeWrapper
      ];

      buildInputs = with pkgs; [
        stdenv.cc.cc.lib
        zlib
      ];

      installPhase = ''
        mkdir -p $out
        cp -r . $out
        wrapProgram $out/bin/lcc --set GBDKDIR "$out/"
      '';
    };
  in {
    devShells.${system}.default = pkgs.mkShell {
      packages = [
        gbdk
        pkgs.clang-tools
        pkgs.gnumake
        pkgs.gearboy
        pkgs.bear
      ];

      shellHook = ''
        export GBDK_HOME=${gbdk}
        export PATH=$GBDK_HOME/bin:$PATH
      '';
    };
  };
}

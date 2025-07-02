{ pkgs ? import <nixpkgs> {} }:

pkgs.mkShell {
  buildInputs = with pkgs; [
    xorg.libX11.dev
    xorg.libXext.dev
    xorg.libXrandr.dev
    xorg.libXinerama.dev
    xorg.libXcursor.dev
    xorg.libXi.dev
    xorg.libXfixes.dev
    zlib
    gcc
    gnumake
    zsh
  ];
  
  shellHook = ''
    export CPPFLAGS="-I${pkgs.xorg.libX11.dev}/include"
    export LDFLAGS="-L${pkgs.xorg.libX11}/lib"
    export PKG_CONFIG_PATH="${pkgs.xorg.libX11.dev}/lib/pkgconfig:$PKG_CONFIG_PATH"
    exec zsh
  '';
}


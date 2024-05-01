#!/usr/bin/fish
set root (pwd)
$root/fish/debug/init.fish
cmake --build $root/build/debug


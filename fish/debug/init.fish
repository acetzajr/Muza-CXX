#!/usr/bin/fish
set root (pwd)
$root/fish/util/mkdir.fish "build"
$root/fish/util/mkdir.fish "build/debug"
cmake -S=$root -B=$root/build/debug -DCMAKE_BUILD_TYPE=Debug


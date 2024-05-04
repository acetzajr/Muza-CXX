#!/bin/fish
set style Google
clang-format -style=$style -dump-config >.clang-format

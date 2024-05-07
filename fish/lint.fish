#!/bin/fish
clang-tidy -format-style=file -header-filter=. -p build --quiet $argv
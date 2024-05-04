#!/bin/fish
set style Google
set c "clang-diagnostic-*"
set c "$c,clang-analyzer-*"
set c "$c,cppcoreguidelines-*"
set c "$c,google-*,modernize-*"
set c "$c,-modernize-use-trailing-return-type"
set c "$c,llvm-*"
set c "$c,performance-*"
set c "$c,readability-*"
clang-tidy --checks=$c --dump-config >.clang-tidy

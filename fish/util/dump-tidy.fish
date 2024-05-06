#!/bin/fish
set style Google
set c "clang-diagnostic-*"
set c "$c,clang-analyzer-*"
set c "$c,cppcoreguidelines-*"
set c "$c,google-*,modernize-*"
set c "$c,llvm-*"
set c "$c,performance-*"
set c "$c,readability-*"
set c "$c,bugprone-*"
set c "$c,portability-*"
set c "$c,cert-*"
set c "$c,-modernize-use-trailing-return-type"
set c "$c,-cppcoreguidelines-avoid-magic-numbers"
set c "$c,-readability-magic-numbers"
set c "$c,-modernize-use-nodiscard"
set c "$c,-cppcoreguidelines-avoid-goto"
clang-tidy --checks=$c --dump-config >.clang-tidy

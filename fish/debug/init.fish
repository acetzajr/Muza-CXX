#!/bin/fish
fish/util/mkdir.fish build
fish/util/mkdir.fish build/debug
set c_compiler clang
set cpp_compiler clang++
cmake -B=build/debug -DCMAKE_BUILD_TYPE=Debug -S=. -DCMAKE_CXX_COMPILER=$cpp_compiler -DCMAKE_C_COMPILER=$c_compiler

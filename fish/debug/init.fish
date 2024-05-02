#!/usr/bin/fish
fish/util/mkdir.fish build
fish/util/mkdir.fish build/debug
cmake -S=. -B=build/debug -DCMAKE_BUILD_TYPE=Debug

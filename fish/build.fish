#!/bin/fish
fish/init.fish $argv[1]
if not test $status -eq 0
    exit $status
end
set jobs 16
cmake --build build --config $argv[1] --target $argv[2] --parallel $jobs --

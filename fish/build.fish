#!/bin/fish
fish/init.fish $argv[2]
if not test $status -eq 0
    exit $status
end
set jobs 16
cmake --build build --target $argv[1] --config $argv[2] --parallel $jobs --

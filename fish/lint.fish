#!/bin/fish
echo "> Linting C++ files..."
function lint
    for file in (find $argv[1] -type f -name "*.$argv[2]")
        clang-tidy -p build --quiet $file
        if not test $status -eq 0
            echo "** Problems inside '$file'"
            exit 1
        end
    end
end
lint source cxx
lint include hxx

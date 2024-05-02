#!/usr/bin/fish
set style GNU
echo "> Formatting c files..."
function format
    if test $argv = c
        set directory source
    else
        set directory include
    end
    for file in (find $directory -type f -name "*.$argv")
        clang-format --style=$style --Werror --dry-run $file &>/dev/null
        if not test $status -eq 0
            clang-format --style=$style -i $file &>/dev/null
            echo "  $file formatted"
            set count (math $math + 1)
        end
    end
end
set count 0
format c
format h
if test $count -eq 0
    echo "  no files formatted"
end

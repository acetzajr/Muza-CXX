#!/bin/fish
function format
    if test $argv = cpp
        set ext c
    else
        set ext h
    end
    for file in (find c -type f -name "*.$argv")
        mv $file (path change-extension $ext $file)
    end
end
format cpp
format hpp


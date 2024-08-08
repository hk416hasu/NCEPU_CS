#!/bin/env bash

shopt -s globstar

for file in /path/to/targetDir/**/*; do
    if [[ -f "$file" ]]; then
        echo "${file##*.}"
    fi
done | sort -u 

exit 0


am i here?
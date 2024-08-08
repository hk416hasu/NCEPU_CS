#!/bin/env bash

shopt -s globstar

for file in **/*; do
    if [[ -f "$file" ]]; then
        echo "${file##*.}"
    fi
done | sort -u 

exit 0

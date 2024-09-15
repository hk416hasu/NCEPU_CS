#!/bin/env bash

shopt -s globstar

for file in **/*.{asm,hex,ihx,lk,lst,map,mem,rel,rst,sym}; do
    if [[ -f "$file" ]]; then
        rm "$file"
    fi
done

exit 0

#!/bin/env bash

shopt -s globstar

for file in **/*.{asm,hex,ihx,lk,lst,map,mem,rel,rst,sym}; do
    rm "$file"
done

exit 0

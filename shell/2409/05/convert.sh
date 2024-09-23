#!/bin/env bash

# Before first, remove files NOT png
find . -type f ! -name "*.png" -delete

# At first, rename here
for file in *.png; do 
    name=${file%.*}
    if [[ ${#name} -eq 1 ]]; then
        mv "$file" "00$file"
    elif [[ ${#name} -eq 2 ]]; then
        mv "$file" "0$file"
    fi
done

# Second, convert them to pdf
convert *.png "../$(basename $PWD).pdf"

# then u can use pdf-viewer to print that pdf to Four Pages One Side

exit 0

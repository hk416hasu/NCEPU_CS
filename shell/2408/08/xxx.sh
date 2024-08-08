#!/bin/env bash

: > output

for file in ./anime/**/*; do
    if [[ -f "$file" ]]; then 
        echo "$file" >> output 
    fi
done;

cat output | less

#!/bin/env bash

for file in **/*.webp; do
    if [[ -f "$file" ]]; then
        convert "$file" "${file%.webp}.png" && rm "$file"
    fi
done;

exit 0

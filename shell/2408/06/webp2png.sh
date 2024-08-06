#!/bin/env bash

for file in **/*.webp; do   # ** will Lists complete file tree, recursively.
    if [[ -f "$file" ]]; then
        convert "$file" "${file%.webp}.png" && rm "$file"
    fi
done;

exit 0

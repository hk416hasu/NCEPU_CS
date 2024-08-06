#!/bin/env bash

find . -type f -name '*.webp' -exec sh -c '
    for file; do 
        convert "$file" "${file%.webp}.png" && rm "$file" 
    done
' sh {} +

exit 0
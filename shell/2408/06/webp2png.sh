#!/bin/env bash

for file in *.webp; do
    convert "$file" "${file%.webp}.png"
    rm "$file"
done;

exit 0

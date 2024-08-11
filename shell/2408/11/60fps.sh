#!/bin/env bash

for file in *.mp4; do
    output="[60fps]$file"
    ffmpeg -i "$file" -vf "minterpolate='fps=60'" "$output"
done

exit 0

#!/bin/env bash

for file in *.mp4; do
    output="[60fps]$file"
    nohup ffmpeg -i "$file" -vf "minterpolate='fps=60'" "$output" > /dev/null 2>&1 &
    # redirect stdout to /dev/null, and redirect stderr to stdout
done

exit 0

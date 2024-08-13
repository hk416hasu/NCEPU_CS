#!/bin/env bash

for file in *.mp3; do
    ffmpeg -i "$file" -metadata comment= codec copy "../abab/${file}"
done

exit 0

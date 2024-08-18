#!/bin/env bash

find . -type f \( -name "*.mp4" -o -name "*.mkv" \) -exec sh -c "ffmpeg -v error -i '{}' -map 0:1 -f null - 2>>error.log" \;


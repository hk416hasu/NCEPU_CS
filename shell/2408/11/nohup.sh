#!/bin/env bash

file='[SHANA][I.G&CASO][Lucky_Star][01][BDRIP][1920x1080][x264_FLAC_2][8ECF808D].mp4'

nohup ffmpeg -i "$file" -vf "scale=64:64" "[64:64]$file" > /dev/null 2>&1 &

exit 0

#!/bin/env bash

shopt -s globstar

# use varible to replace static path
echo "plz give the absolute path of target dir"
read -r tardir     # target directory 
if [[ -d "$tardir" ]]; then
    echo "$tardir" "exists"
else
    echo "$tardir" "doesn't exist."
fi

for file in ./anime/**/*.{jpg,png}; do
    newpath="${file/anime/anime_640x360}"
    newdir="${newpath%/*}"
    mkdir -p "$newdir"
    cp "$file" "$newpath"
done

: '    
for file in ./anime/**/*.mp4; do
    newpath="${file/anime/anime_640x360}"
#    newdir="${newpath%/*}"
#    mkdir -p "$newdir"
    ffmpeg -i "$file" -vf scale=640:-1 "$newpath"
done
'

exit 0

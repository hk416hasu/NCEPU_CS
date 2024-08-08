#!/bin/env bash

shopt -s globstar

# use varible to replace static path
echo "plz give the absolute path of target dir"
read -r tardir     # get  target directory from input 
# plz trans ~ later
if [[ ! -d "$tardir" ]]; then
    echo "$tardir" "doesn't exist."
    exit 1
fi

echo -e "\nplz preview the target dir \n"
ls "$tardir" | head -n 5
open "$tardir"
echo -e "\nis this your target dir?"
echo -n "enter yes/no: "
read flag

if [[ "$flag" != "yes" ]]; then
    exit 2
fi

cd "$(dirname "$tardir")"
# pwd
relapath='./'$(basename "$tardir")
# echo $relapath
oldname=$(basename "$tardir")
newname="[640x360]""$oldname"

for file in $relapath/**/*.{jpg,png}; do
    newpath="${file/"$oldname"/"$newname"}"
    newdir="$(dirname "$newpath")"
    mkdir -p "$newdir"
    cp "$file" "$newpath"
done

for file in $relapath/**/*.mp4; do
    newpath="${file/"$oldname"/"$newname"}"
#    newdir="$(dirname "$newpath")"
#    mkdir -p "$newdir"
    ffmpeg -i "$file" -vf scale=640:-1 "$newpath"
done


: '    
for file in ./anime/**/*.{jpg,png}; do
    newpath="${file/anime/anime_640x360}"
    newdir="${newpath%/*}"
    mkdir -p "$newdir"
    cp "$file" "$newpath"
done

for file in ./anime/**/*.mp4; do
    newpath="${file/anime/anime_640x360}"
#    newdir="${newpath%/*}"
#    mkdir -p "$newdir"
    ffmpeg -i "$file" -vf scale=640:-1 "$newpath"
done
'

exit 0

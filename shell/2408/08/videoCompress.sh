#!/bin/env bash

shopt -s globstar

# use varible to replace static path
echo "plz give the absolute path of target dir"
read -r tardir     # get  target directory from input 
if [[ ! -d "$tardir" ]]; then
    echo "$tardir" "doesn't exist."
    exit 1
fi

echo -e "\nplz preview the target dir \n"
ls "$tardir" | head -n 5
open "$tardir"
echo -e "\nis this your target dir?"
echo -n "enter yes/no: "
read -r flag

if [[ "$flag" != "yes" ]]; then
    exit 2
fi

cd "$(dirname "$tardir")" || exit 1
relapath='./'$(basename "$tardir")
name=$(basename "$tardir")
newname="[640x360]""$name"

for file in "$relapath"/**/*.{jpg,png}; do
    newpath="${file/"$name"/"$newname"}"
    newdir="$(dirname "$newpath")"
    mkdir -p "$newdir"
    cp "$file" "$newpath"
done

for file in "$relapath"/**/*.mp4; do
    newpath="${file/"$name"/"$newname"}"
#    newdir="$(dirname "$newpath")"
#    mkdir -p "$newdir"
    ffmpeg -i "$file" -vf scale=640:-1 "$newpath"
done

exit 0

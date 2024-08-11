#!/bin/env bash

# this script can help u copy photos and compress videos with dir structures.

# plz use findallsuffix.sh to collect all suffix of your target dir first
# then u need to modify those suffix in this script

resolution="-1:640"

shopt -s globstar

# use varible to replace static path
echo "plz enter the path of target dir:"
read -r tardir     # get target directory from input 
if [[ ! -d "$tardir" ]]; then
    echo "$tardir" "doesn't exist."
    exit 1
fi

echo -e "\nplz preview the target dir: \n"
ls "$tardir" | head -n 5
open "$tardir"
echo -e "\nis this your target dir?"
echo -n "enter yes/no: "
read -r flag

if [[ "$flag" != "yes" ]]; then
    exit 2
fi

cd "$(dirname "$tardir")" || exit 1
name=$(basename "$tardir")
newname="[$resolution]$name"

for file in "./$name"/**/*.{jpg,png}; do
    newpath="${file/"$name"/"$newname"}"
    newdir="$(dirname "$newpath")"
    mkdir -p "$newdir"
    cp "$file" "$newpath"
done

for file in "./$name"/**/*.mp4; do
    newpath="${file/"$name"/"$newname"}"
    newdir="$(dirname "$newpath")"
    mkdir -p "$newdir"
    ffmpeg -i "$file" -vf scale="$resolution" "$newpath"
done

exit 0

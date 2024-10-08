#!/bin/env bash

# plz use findallsuffix.sh to collect all suffix of your target dir
# then u need to modify those suffix in this script

shopt -s globstar

# use varible to replace static path
echo "plz give the absolute path(from /) of target dir"
read -r tardir     # get target directory from input 
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
    echo "$PWD" > log
# relapath='./'$(basename "$tardir")
name=$(basename "$tardir")
newname="[abab]$name"
#    echo "relapath: $relapath" >> log
    echo "name: $name" >> log
    echo "newname: $newname" >> log

for file in "./$name"/**/*.{jpg,png}; do
    newpath="${file/"$name"/"$newname"}"
    newdir="$(dirname "$newpath")"
        echo "file: $file" >> log
        echo "newpath: $newpath" >> log
        echo "newdir: $newdir" >> log
    mkdir -p "$newdir"
    cp "$file" "$newpath"
done

for file in "./$name"/**/*.mp4; do
    newpath="${file/"$name"/"$newname"}"
        echo "file: $file" >> log
        echo "$newpath" >> log
    newdir="$(dirname "$newpath")"
    mkdir -p "$newdir"
    ffmpeg -i "$file" -vf scale=640:-1 "$newpath"
done

exit 0

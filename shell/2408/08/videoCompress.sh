#!/bin/env bash

shopt -s globstar

for file in ./anime/**/*.{jpg,png}; do
    newpath="${file/anime/anime_640x360}"
    newdir="${newpath%/*}"
    mkdir -p "$newdir"
    cp "$file" "$newpath"
done
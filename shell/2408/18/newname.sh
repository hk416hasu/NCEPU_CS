#!/bin/env bash
for file in *.mp4; do 
    newname=$(echo "$file" | awk -F ']' '{print $2 "]" $3 "]" $4 "].mp4"}')
    mv "$file" "$newname"
done

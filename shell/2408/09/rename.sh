#!/bin/env bash

for file in *.mp4; do
    newname="第0${file#*[^0-9]}"
    #    echo $newname
    mv "$file" "$newname"
done 

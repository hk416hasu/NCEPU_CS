#!/bin/env bash

cd ~/Desktop/the_missing_semester/Chinese || exit

for file in *; do
    # echo $file | awk '{print $4 $5 $6}'
    newname=$(echo "$file" | awk '{print $4 " " $5 " " $6}')
    # echo $newname
    mv "$file" "$newname"
    # mv $file "$newname"  is not okay, because $file contains space so that it will be interrupted to multiple arguments.

done

exit 1

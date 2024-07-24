#!/bin/bash

file="./while.sh"
#filename=$(basename $file)

if [ -x $file ]
then
echo "\"$file\"" is executble
else
echo "\"$file\"" is not executable
fi

exit

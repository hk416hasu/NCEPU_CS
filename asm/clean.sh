#!/bin/env bash 

find . -type f \( -name "*.EXE" -o -name "*.OBJ" \) -not -path '*/MASM/*' -exec rm {} +
#find . -path ./MASM -prune -o -type f -name "*EXE" -exec rm {} +

#https://cn.linux-console.net/?p=19752

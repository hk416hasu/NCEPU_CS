#!/bin/env bash

gcc hello.c -o hello
gcc world.c -o world

rm foo.txt foo.bak

i=0
while [[ i -le 10000 ]]; do
  ./hello & ./world & wait
  echo -ne "\n" >> foo.txt
  cat foo.txt >> foo.bak
  > foo.txt
  let "i=i+1"
done

cat foo.bak | sort | uniq

exit 0

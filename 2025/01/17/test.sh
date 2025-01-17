#!/bin/env bash

gcc hello.c -o hello
gcc world.c -o world
gcc write1.c -o write1

rm foo.txt foo.bak

i=0
while [[ i -le 100000 ]]; do
  # ./hello & ./world & wait
  ./write1
  echo -ne "\n" >> foo.txt
  cat foo.txt >> foo.bak
  > foo.txt
  let "i=i+1"
done

cat foo.bak | sort | uniq

exit 0

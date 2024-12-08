#!/bin/env bash

##### u should rewrite these #####
program="./a"
input_file="./input"
output_file="./expectedOutput"
##### ##### ##### ##### #####

##### Build #####
make
if [ ! -f "./a" ]; then
  echo "Can not find building target"
  exit 1
fi

##### Robus #####

if [ ! -f "$input_file" ] || [ ! -f "$output_file" ]; then
  echo "lost input or output files"
  exit 1
fi

inputs=($(cat "$input_file"))
outputs=($(cat "$output_file"))

if [ ${#inputs[@]} -ne ${#outputs[@]} ]; then
  echo -e "\033[1;31mError\033[0m: the Input and Output of test-case do NOT match!!"
  exit 1
fi

##### Start Testing #####

for i in ${!inputs[@]}; do
  input=${inputs[$i]}
  expected=${outputs[$i]}

  output=$("$program" $input)

  echo -n "case_$i "
  if [ "$output" != "$expected" ]; then
    echo -e "\033[1;31mWrong\033[0m:"
    echo -e "  input : "$input""
    echo -e "  expect: "$expected""
    echo -e "  output: "$output""
  else
    echo "pass! "$input" -> "$output""
  fi
done

exit 0

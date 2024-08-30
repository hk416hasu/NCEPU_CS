#!/bin/env bash

echo 0 > divideBy5
echo 5 >> divideBy5

i=0
for i in {1..9}; do
    echo "${RANDOM}5" >> divideBy5
    echo "${RANDOM}0" >> divideBy5
done

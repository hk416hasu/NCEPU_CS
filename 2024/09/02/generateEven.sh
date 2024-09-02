#!/bin/env bash

# to verify the RegEx as follow , to identify all evens:
# [1-9]?[0-9]*[02468]

if [[ -f even ]]; then
    rm even
fi

for i in {2,4,6,8,10}; do
    echo "$i" >> even
done

for i in {0..4}; do
    echo "${RANDOM}0" >> even
    echo "${RANDOM}2" >> even
    echo "${RANDOM}4" >> even
    echo "${RANDOM}6" >> even
    echo "${RANDOM}8" >> even
done

exit 0

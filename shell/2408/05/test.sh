#!/bin/env bash

filepath="./abab.sh"
runtimes=0

: > stdout.log
: > stderr.log

while [[ $? -eq 0 ]]; do
    # runtimes=$((runtimes+1))
    let runtimes++
    ./abab.sh 1>>stdout.log 2>>stderr.log 
done

echo "runtimes is $runtimes"
echo -e "\nstderr.log is : "
cat stderr.log
echo -e "\nstdout.log is : "
cat stdout.log

echo -n "line of stdout.log is : " 
echo "$(wc -l < stdout.log)" # yes, (command group)

exit 0

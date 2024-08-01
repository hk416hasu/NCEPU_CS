#!/bin/env bash

i=1

while : # equal to " while true "
do
#i=1    # why should i be set before while?
echo $i
#i=`expr $i + 1`
#i=$(expr $i + 1)
#i=$((i+1))
let i++
sleep 1
done

exit

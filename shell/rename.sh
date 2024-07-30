#/bin/env bash

cd ~/Desktop/the_missing_semester/Chinese

for file in *; do
    echo $file | awk '{print $4 $5 $6}'
    #$newname=$(echo $file | awk '{print $4 $5 $6}')
    #echo $newname
    # mv $file $newname
done

exit 1

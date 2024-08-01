#!/bin/bash

PATH=/sys/bus/acpi/drivers/battery/PNP0C0A:00/power_supply/BAT0

cd $PATH

echo `/bin/cat $PATH/capacity`
echo $(/bin/cat $PATH/capacity)
# echo $(cat $PATH/capacity) # cat is not a built-in  
echo $(/bin/cat capacity)

exit 0

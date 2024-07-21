#!/bin/bash


LOG_FILE="$(pwd)/log"

#LOG_FILE='$pwd/log'   # this is wrong because there is only string in ' '
#LOG_FILE="($pwd)/log" # this is a wrong in varible
#LOG_FILE="$pwd/log"   # wrong too

echo "hello? (frmm echo)" > $LOG_FILE
echo "hello? (from tee)"  | tee -a "$LOG_FILE"

current_date=$(date)
current_user=$(users)
uptime=$(uptime -p)




exit 0

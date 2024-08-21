#!/bin/env bash
# this is a script to check the difference 
# between "source xxx.sh" and "bash xxx.sh" and "./xxx.sh"

cd /home/hk416

# the result tells us that : source is running in current bash, 
# and ./xxx.sh and bash xxx.sh will run in a new one.

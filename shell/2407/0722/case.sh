#!/bin/env bash

var=$1

case "$var" in
#	a) echo "\$var = a" ;;	# in "", '\' prevent '$' from being interrupted as a value
	a) echo '$var = a' ;;	
	a) echo "$var = a" ;;	# this will not be echo forever	
	b) echo "\$var = b" ;;
esac

exit
	

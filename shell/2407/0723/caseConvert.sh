#!/bin/bash

var=veryMixedUpVariable
echo ${var}            # veryMixedUpVariable
echo ${var^}           # VeryMixedUpVariable
#         *              First char --> uppercase.
echo ${var^^}          # VERYMIXEDUPVARIABLE
#         **             All chars  --> uppercase.
echo ${var,}           # veryMixedUpVariable
#         *              First char --> lowercase.
echo ${var,,}          # verymixedupvariable
#**       		 All chars  --> lowercase.

# veryMixedUpVariable 
# VeryMixedUpVariable
# VERYMIXEDUPVARIABLE
# veryMixedUpVariable
# verymixedupvariable

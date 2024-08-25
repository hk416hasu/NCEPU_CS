#!/bin/env bash


fileArray=("ag" "brightness" "mpvline" "sound")

for elem in "${fileArray[@]}"; do
    sudo rm "/usr/bin/${elem}"
    ln -s "$PWD/${elem}" "/usr/bin/${elem}"
done

#!/bin/env bash

while [[ $? -eq true ]]; do ./abab.sh; done

while ./abab.sh; do :; done

exit 0
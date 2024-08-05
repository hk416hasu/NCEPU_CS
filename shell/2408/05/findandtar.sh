#!/bin/env bash

mkdir foo && cd foo

touch {a..h}.bar && touch {a..d}.abab

# xargs is a powerful tool for taking input from stdin (often from pipes), converting that input into arguments, and then executing a command with those arguments. It helps connect commands that need arguments with those that generate lists of items. By managing long lists of arguments efficiently, xargs ensures commands can process large amounts of data seamlessly.
# ls | xargs rm

find . -type f -name '*.bar' -print | xargs tar -cf bar.tar.gz


exit 0

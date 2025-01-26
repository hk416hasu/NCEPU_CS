#!/bin/env bash

gcc -static fork_printf_v2.c

strace -e trace=write -f -o trace_stdout ./a.out > /dev/pts/0
strace -e trace=write -f -o trace_pipe ./a.out | cat > /dev/null

echo 'strace log of `./a.out to stdout(tty)`: '
grep "write(" ./trace_stdout

echo 'strace log of `./a.out | cat`: '
grep "write(" ./trace_pipe

exit 0

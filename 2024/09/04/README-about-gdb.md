this is a subset of Quick Guide to GDB
but it's enough for beginners like me.

At first, u should use
```bash
    gcc -g source.c [-o]
```
to compile your code to enable debug mode.

Second, use this flag to start with gdb
```bash
    gdb -tui ./a.out
```

then u can use 
```bash
    run
    break filename:lineNum # to set breakpoint
    # break source.c:9

    print variable      # print value of a variable
    print/t variable    # in binary
    print/x variable    # in hex

    info locals         # print all variables in local
```
---

some shortcuts about gdb's TUI mode

```bash
    <c-x>,a     # enter or leave TUI mode
    <c-x>,2     # change windows number? and it can show asm code 
    <c-x>,1     # select the curr window to remain

    up, down, left, right to move the code
```

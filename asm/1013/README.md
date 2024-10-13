### What's the TOP LEVEL of writing asm? ###
####        ---- " I'm the Complier "

step 1: adstract a complicated state transition ( S1 -> S2 )
step 2: draw the parser tree of "S1 -> S2" ( if has )
step 3: Topological-Sort and Generate Target Code (like 8086 asm)



### for-loop model ###

#### ---- which can help u trans C to asm ####
// 可嵌套

```asm
    initialize iterator
loop_begin:
    cmp xx, xx  ; conditions
    如果条件不满足就跳到“外一层”的end（具体分析）
    some statements which meet conditions
loop_end:
    update iterator
    jmp loop_begin(of this loop)
```


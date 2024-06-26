Read:
    li      $r0,    0           # 数组首地址, 以立即数形式给出
    li      $r1,    10          # 计数器, 即数组元素个数
    li      $r2,    0           # val寄存器
    li      $r3,    0           # sum寄存器

Loop_R:
    beqz    $r1,    5           # beqz $r1, End 条件判断
    lw      $r0,    $r2,    0   # 从(r0)读取数值放进r2
    addu    $r2,    $r3,    $r3 # sum = sum + val
    addiu   $r1,    -1          # count--
    addiu   $r0,    1           # addr += '1'
    b       -6                  # b Loop_R, 循环

End:
    sw      $r0,    $r3,    0   # 将sum写回内存

01101   000   00000000
01101   001   00001010
01101   010   00000000
01101   011   00000000

00100   001   00000101
10011   000   010   00000
11100   010   011   011   01
01001   001   11111111
01001   000   00000001

11011   000   011   00000
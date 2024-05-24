.data
array: .space 40   # 预留40个字节空间，相当于10个整数

.text
.globl Write

Write:
	la	$t0,	array		# 数组首地址
	li	$t1,	10		# 计数器count
	li	$t2,	1		# 数值val

Loop_W:
	bnez	$t1,	Store		# 根据计数器的值决定跳转与否
	b	Read

Store:
	sw	$t2,	($t0)		# 将数值$t2存入内存($t0)
	addiu	$t0,	$t0,	4	# 更新数组下标
	addiu	$t2,	$t2,	1	# 更新数值
	addiu	$t1,	$t1,	-1	# 更新计数器
	b	Loop_W

Read:
	la	$t0,	array		# 重置数组首地址
	li	$t1,	10		# 重置计数器
	li	$t2,	0		# 重置数值val
	li	$t3,	0		# 和寄存器sum
	
Loop_R:
	bnez	$t1,	Load		# 根据计数器的值决定跳转与否
	b	End
	
Load:
	lw	$t2,	($t0)		# 从内存($t0)中读取数值, 放到t2
	add	$t3,	$t3,	$t2	# 累加: sum = sum + val
	addiu	$t1,	$t1,	-1	# 更新计数器
	addiu	$t0,	$t0,	4	# 更新数组下标
	b	Loop_R
	
End:
	sw	$t3,	($t0)

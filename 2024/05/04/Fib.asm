0000h	LI		$r0, 7			; 计数器
0001h	LI		$r1, 0			; fib(n-1)
0002h	LI		$r2, 1			; fin(n)
0003h	LI		$r3, 0			; tmp Reg
0004h	LI		$r4, Looop		; Looop Addr
0005h	LI		$r5, Cal		; Cal Addr
0006h	LI		$r6, ed			; End Addr
0007h	LI		$r7, store		; 存储fib(n)的地址
	
Looop:
0007h	BNEZ	$r0, 1			; 循环判断
0008h	JR		$r6				; 若计数器等于0, 则跳转至结束部分

Cal:
0009h	MOVE	$r3, $r2		; 备份fib(n)
000Ah	ADDU	$r2, $r2, $r1 	; fib(n+1) = fib(n) + fib(n-1)
000Bh	MOVE	$r1, $r3		; 更新fib(n-1)
000Ch	ADDIU	$r0, -1			; 更新计数器	
000Dh	JR		$r4				; 跳转至循环判断

ed:
000Dh	SW		$r7, $r2		; 结果存入主存

minimal: minimal.S
	# gcc -nostdlib -no-pie minimal.S
	gcc -S minimal.S > minimal.s
	as -o minimal.o minimal.s
	ld -o minimal minimal.o

clean:
	rm -f minimal.s minimal.o minimal


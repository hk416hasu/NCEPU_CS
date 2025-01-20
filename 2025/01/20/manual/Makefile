minimal: minimal.s
	# gcc -nostdlib -no-pie ./minimal.s
	as -o minimal.o ./minimal.s
	ld -o minimal ./minimal.o

clean:
	rm -f minimal.o minimal

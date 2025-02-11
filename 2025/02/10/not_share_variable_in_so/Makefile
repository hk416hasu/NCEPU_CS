CC = gcc
CFLAGS = -Wall
LDFLAGS = -L. -Wl,-rpath,.

all: main a b

lib.so: lib.c
	$(CC) -shared -fPIC -o lib.so lib.c

a: lib.so a.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o a ./a.c -l:lib.so

b: lib.so b.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o b ./b.c -l:lib.so

main: lib.so main.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o main ./main.c -l:lib.so

run: a b
	# LD_LIBRARY_PATH=. ./main
	# ./main
	./a > /dev/tty & ./b > /dev/tty &

.PHONY: clean
clean:
	rm -rf ./main ./lib.so a b


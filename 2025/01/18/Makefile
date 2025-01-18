# compiler
cc = gcc

# compiler flags
CFLAGS = -nostdlib

# Target executable
TARGET = ./sh

# source files
SRCS = sh-xv6.c

$(TARGET): $(SRCS) # Dependency
	$(cc) $(CFLAGS) -o $(TARGET) $(SRCS) 

clean:
	rm -f $(TARGET)

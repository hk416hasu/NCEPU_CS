# compiler
cc = gcc

# compiler flags
CFLAGS = -Wall -g

# Target executable
TARGET = ./a.out

# source files
SRCS = main.c hello.c

$(TARGET): $(SRCS) # Dependency
	$(cc) $(CFLAGS) $(SRCS) -o $(TARGET) 

clean:
	rm -f $(TARGET)

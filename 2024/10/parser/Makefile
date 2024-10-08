# compiler
cc = gcc

# compiler flags
CFLAGS = -Wall -g

# Target executable
TARGET = ./a

# source files
SRCS = main.c getNextToken.c 

$(TARGET): $(SRCS)
	$(cc) $(CFLAGS) $(SRCS) -o $(TARGET) 

clean:
	rm -f $(TARGET)

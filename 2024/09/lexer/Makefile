# compiler
cc = gcc

# compiler flags
CFLAGS = -Wall -g

# Target executable
TARGET = ./a

# source files
SRCS = main.c loadFileToArray.c getNextToken.c KWTable.c

$(TARGET): $(SRCS) # Dependency
	$(cc) $(CFLAGS) $(SRCS) -o $(TARGET) 

clean:
	rm -f $(TARGET)

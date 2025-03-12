CC = g++
CFLAGS = -Werror -Wall -O2
DEBUG_FLAGS = -Werror -Wall -g

TARGET = up
SRCS = test.cc
OBJS = $(SRCS:.cc=.o)

.PHONY: all debug clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

%.o: %.cc
	$(CC) $(CFLAGS) -c $< -o $@

debug: CFLAGS = DEBUG_FLAGS
debug: clean $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

clean:
	rm -rf $(OBJS) $(TARGET)


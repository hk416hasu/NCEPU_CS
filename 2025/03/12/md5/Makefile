CC = g++
CFLAGS = -Werror -Wall -O2
DEBUG_FLAGS = -Werror -Wall -g
LDFLAGS = -lssl -lcrypto

TARGET = md5
SRCS = main.cc md5.cc
OBJS = $(SRCS:.cc=.o)

.PHONY: all clean debug

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET) $(LDFLAGS)

%.o: %.cc
	$(CC) $(CFLAGS) -c $< -o $@

debug: clean
	$(MAKE) CFLAGS="$(DEBUG_FLAGS)" $(TARGET)

clean:
	rm -rf $(TARGET) $(OBJS)

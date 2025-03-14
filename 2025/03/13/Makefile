CC = g++
CFLAGS = -Werror -Wall -O2
DEBUG_FLAGS = -Werror -Wall -g
LFLAGS = -lssl -lcrypto

TARGET = md5
SRCS = main.cc md5.cc
OBJS = $(SRCS:.cc=.o)

.PHONY = all debug clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET) $(LFLAGS)

%.o: %.cc
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS) $(TARGET)

debug: clean
	$(MAKE) CFLAGS="$(DEBUG_FLAGS)"

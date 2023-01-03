CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
RM = rm -f
OBJECTS = linkedlist.o
SOURCE = $(OBJECTS:.o=.c)
TARGET = $(OBJECTS:.o=)

.PHONY: all clean

all: $(TARGET)

clean: $(TARGET) $(OBJECTS)
	$(RM) $^

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJECTS): $(SOURCE)
	$(CC) $(CFLAGS) -c $^

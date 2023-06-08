CC = gcc
CFLAGS = -Wall -Wextra -std=c11
TARGET = port-simulator
SRC = $(wildcard *.c) components/container/container.component.c\
components/cross/cross.component.c\
components/docks/docks.component.c\
components/ship/ship.component.c\
structs/node/node.c\
structs/list/list.c\
structs/stack/stack.c\
structs/queue/queue.c\
structs/stack/stack.c\
utils/utils.c\
main.c

OBJ = $(SRC:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ) $(TARGET)
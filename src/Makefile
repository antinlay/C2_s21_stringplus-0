CC=gcc
CFLAGS=--std=c11 -Wall -Werror -Wextra


all: s21_string

door_struct: dmanager_module.c
	$(CC) $(CFLAGS) $^ -o ../build/Quest_1

list_test: list.c
	$(CC) $(CFLAGS) $^ -o ../build/Quest_2

stack_test: stack.c
	$(CC) $(CFLAGS) $^ -o ../build/Quest_3

clean:
	rm -rf ../build/*
	rm -rf *.o
	rm -rf *.a
	rm -rf *.so
rebuild: clean all


CC=gcc
CFLAGS=-c -std=c11 -Wall -Werror -Wextra
LDFLAGS=-L. -ls21_string
SOURCES=s21_string.c 
OBJECTS=$(SOURCES:.c=.o)
GCOVFLAGS=--coverage
HTML_CREATE=lcov -t a.out -o rep.info -c -d .; genhtml -o report rep.info
OS := $(shell uname)

ifeq ($(OS), Darwin)
	CHECK_H=-lcheck
else
	CHECK_H=-lcheck -lsubunit -lm -lrt -lpthread -D_GNU_SOURCE
endif

all: clean s21_string.o s21_string.a test

build: *.o
	$(CC) *.o -o ../materials/build/

test: s21_test.c
	$(CC) s21_test.c s21_string.a -o a.out $(CHECK_H)


s21_string.o: *.c
	$(CC) $(CFLAGS) -c s21_memchr.c s21_memcmp.c

s21_string.a: *.o
	ar rcs s21_string.a *.o
	ranlib s21_string.a

clean:
	rm -rf *.o ../materials/build/*
	rm -rf *.a
	rm -rf *.o
	rm -rf *.so
rebuild: clean all


CC=gcc
CFLAGS=-std=c11 -Wall -Werror -Wextra
LDFLAGS=-L. -ls21_string
SOURCES=s21_strlen.c s21_memcpy.c 
OBJECTS=$(SOURCES:.c=.o)
LIBRARY=s21_test.c s21_string.a
GCOVFLAGS=--coverage
HTML_CREATE=lcov -t "test" -o rep.info -c -d .; genhtml -o report rep.info
OS := $(shell uname)

ifeq ($(OS), Darwin)
	CHECK_H=-lcheck
else
	CHECK_H=-lcheck -lsubunit -lm -lrt -lpthread -D_GNU_SOURCE
endif

all: s21_string.a test gcov_report

s21_string.a:
	$(CC) $(CFLAGS) -c $(SOURCES)
	ar rcs s21_string.a $(OBJECTS)
	ranlib s21_string.a

test: s21_test.c
	$(CC) $(CFLAGS) $(LIBRARY) -o test $(CHECK_H)
	./test

gcov_report:
	$(CC) $(GCOVFLAGS) $(LIBRARY) -o test $(CHECK_H)
	./test
	$(HTML_CREATE)
	open ./report/index.html

clean:
	rm -rf *.o test
	rm -rf *.a
	rm -rf *.o
	rm -rf *.so
	rm -rf *.gcda *.gcno test rep.info
	rm -rf report

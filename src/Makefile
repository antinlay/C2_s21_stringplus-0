
CC=gcc
CFLAGS=-std=c11 -Wall -Werror -Wextra -g
SOURCES=s21_itoa.c s21_strcpy.c s21_memset.c s21_strlen.c s21_memcpy.c s21_strcspn.c s21_strncpy.c s21_strrchr.c s21_strerror.c s21_memchr.c s21_memcmp.c s21_memmove.c s21_strncat.c s21_strcmp.c s21_strncmp.c s21_strpbrk.c s21_strcat.c s21_strchr.c s21_strstr.c s21_strspn.c s21_strtok.c s21_insert.c s21_trim.c s21_to_upper.c s21_to_lower.c s21_sprintf.c
OBJECTS=$(SOURCES:.c=.o)
GCOVFLAGS=-L. -ls21_string --coverage
HTML=lcov -t "test" -o rep.info -c -d .
OS = $(shell uname)

ifeq ($(OS), Darwin)
	CHECK_H=-lcheck
else
	CHECK_H=-lcheck
endif

all: gcov_report

s21_string.a: clean $(OBJECTS)
	ar rcs libs21_string.a $(OBJECTS)

test: s21_string.a
	$(CC) $(CFLAGS) s21_string_test.c $(SOURCES) -o test $(CHECK_H) $(GCOVFLAGS)
	./test

gcov_report: test
	$(HTML)
	genhtml -o report rep.info
	open ./report/index.html

clean:
	rm -rf *.o *.a *.so *.gcda *.gcno *.gch rep.info *.html *.css test report
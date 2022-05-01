
CC=gcc
CFLAGS=-std=c11 -Wall -Werror -Wextra
PFLAGS = -fprofile-arcs -ftest-coverage
SOURCES=s21_sprintf.c s21_strcpy.c s21_memset.c s21_strlen.c s21_memcpy.c s21_strcspn.c s21_strncpy.c s21_strrchr.c s21_strerror.c
OBJECTS=$(SOURCES:.c=.o)
LCOVPATH=../datasets/gcovr/5.1/libexec/bin/
GCOVFLAGS=-lgcov --coverage
GCONV_FLAGS=$(LCOVPATH)gcovr
OS := $(shell uname)

ifeq ($(OS), Darwin)
	CHECK_H=-lcheck
else
	CHECK_H=-lcheck -lsubunit -lm -lrt -lpthread -D_GNU_SOURCE
endif

all: clean gcov_report

s21_string.a: clean
	$(CC) $(CFLAGS) -c $(PFLAGS) $(SOURCES)
	ar rcs s21_string.a $(OBJECTS)
	ranlib s21_string.a

test: clean s21_string.a
	$(CC) $(CFLAGS) -c $(PFLAGS) s21_test.c $(SOURCES)
	$(CC) $(CHECK_H) $(GCOVFLAGS) -o test s21_test.o s21_string.a $(OBJECTS)
	./test

gcov_report: clean test
	$(GCONV_FLAGS) -r . --html-details -o report.html
	open ./report.html

clean:
	rm -rf *.o *.a *.so *.gcda *.gcno *.gch *.html *.css test report



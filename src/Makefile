
BPATH=../materials/build/
CC=gcc
CFLAGS=-std=c11 -Wall -Werror -Wextra
SOURCES=s21_strcpy.c s21_memset.c s21_strlen.c s21_strcat.c s21_memcpy.c s21_strcspn.c s21_strncpy.c s21_strrchr.c s21_strerror.c s21_insert.c s21_trim.c s21_to_upper.c s21_to_lower.c s21_sprintf.c
OBJECTS=$(SOURCES:.c=.o)
PFLAGS=-fprofile-arcs -ftest-coverage
GCOVFLAGS=--coverage
LCOVPATH=../datasets/lcov/1.15/libexec/bin/
HTML=$(LCOVPATH)lcov -t "test" -o rep.info -c -d .; $(LCOVPATH)genhtml -o report rep.info
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
	$(CC) $(CFLAGS) $(GCOVFLAGS) $(PFLAGS) s21_test.c s21_string.a $(SOURCES) -o $(BPATH)test $(CHECK_H)
	$(BPATH)test # DELETE BEFORE FINISH PROJECT

gcov_report: clean test
	$(HTML)
	open ./report/index.html # DELETE BEFORE FINISH PROJECT

clean:
	rm -rf *.o *.a *.so *.gcda *.gcno *.gch rep.info *.html *.css $(BPATH)test report

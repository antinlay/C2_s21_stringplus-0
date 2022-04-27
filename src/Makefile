CC=gcc
CFLAGS=-c -std=c11 -Wall -Werror -Wextra

all: build

build: s21_strlen.o s21_strcpy.o s21_memset.o s21_memcpy.o
	$(CC) s21_strlen.o s21_strcpy.o s21_memset.o s21_memcpy.o -o ..materials/build/build

build-static: data_stat.a main.o
	$(CC) data_stat.a main.o -o ../../build/Quest_5

build-dynamic: data_io.o data_stat.o data_process.so decision.o main.o
	$(CC) -L../../build data_io.o data_stat.o data_process.so decision.o main.o -o ../../build/Quest_6

data_io.o: ../data_libs/data_io.c
	$(CC) $(CFLAGS) -c ../data_libs/data_io.c -o data_io.o

data_stat.o: ../data_libs/data_stat.c
	$(CC) $(CFLAGS) -c ../data_libs/data_stat.c -o data_stat.o

data_process.o: ../data_module/data_process.c
	$(CC) $(CFLAGS) -c ../data_module/data_process.c -o data_process.o

data_process.so: ../data_module/data_process.c
	$(CC) -fPIC -c ../data_module/data_process.c -o data_process.so

decision.o: ../yet_another_decision_module/decision.c
	$(CC) $(CFLAGS) -c ../yet_another_decision_module/decision.c -o decision.o

main.o: main_executable_module.c
	$(CC) $(CFLAGS) -c main_executable_module.c -o main.o

data_stat.a: data_stat.o data_io.o data_process.o decision.o
	ar rc data_stat.a data_stat.o data_io.o data_process.o decision.o
	ranlib data_stat.a


clean:
	rm -rf *.o ../../build/* ../data_libs/*.o ../data_module/*.o ../yet_another_decision_module/*.o
	rm -rf *.a
	rm -rf *.o
	rm -rf *.so
rebuild: clean all

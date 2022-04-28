#ifndef S21_STRING_H
#define S21_STRING_H
#include <stddef.h>
// #include <stdio.h>
#define s21_NULL ((void*)0)
typedef unsigned s21_size_t;

void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
char *s21_strcpy(char *dest, const char *src);
s21_size_t s21_strlen(const char *str);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
s21_size_t s21_strcspn(const char *str1, const char *str2);
char *s21_strerror(int errnum);

#endif
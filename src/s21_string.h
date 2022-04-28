#ifndef S21_STRING_H
#define S21_STRING_H
// #include <stddef.h>
// #include <stdio.h>

#define NULL ((void*)0)
typedef unsigned size_t;

void *s21_memcpy(void *dest, const void *src, size_t n);
void *s21_memset(void *str, int c, size_t n);
char *s21_strcpy(char *dest, const char *src);
size_t s21_strlen(const char *str);
char *s21_strncpy(char *dest, const char *src, size_t n);
size_t s21_strcspn(const char *str1, const char *str2);
char *s21_strerror(int errnum);

#endif
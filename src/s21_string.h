#include <errno.h>
#include <stddef.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef _S21_STRING_H_
#define _S21_STRING_H_

#define s21_NULL ((void*)0)
typedef long unsigned s21_size_t;

void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
char *s21_strcpy(char *dest, const char *src);
s21_size_t s21_strlen(const char *str);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
s21_size_t s21_strcspn(const char *str1, const char *str2);
char *s21_strerror(int errnum);
char *s21_strrchr(const char *str, int c);
// int sprintf(char *str, const char *format, ...);

#endif
#ifndef _S21_STRING_H_
#define _S21_STRING_H_
#include <stddef.h>
#include <stdarg.h>
// #include <stdio.h>
#define s21_NULL ((void*)0)
// #ifndef S21_SIZE_T_
typedef unsigned s21_size_t;
#define S21_FUNC { "s21_memcpy_test", "s21_strlen_test" }

// char s21_func[] = {  };
//  "s21_memset", "s21_strcpy", "s21_strerror", "s21_strcspn",
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
char *s21_strcpy(char *dest, const char *src);
s21_size_t s21_strlen(const char *str);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
s21_size_t s21_strcspn(const char *str1, const char *str2);
char *s21_strerror(int errnum);

#endif
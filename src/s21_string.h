#include <stddef.h>
#include <stdio.h>

void *s21_memcpy(void *dest, const void *src, size_t n);
void *s21_memset(void *str, int c, size_t n);
char *s21_strcpy(char *dest, const char *src);
size_t s21_strlen(const char *str);
char *s21_strncpy(char *dest, const char *src, size_t n);
size_t s21_strcspn(const char *str1, const char *str2);
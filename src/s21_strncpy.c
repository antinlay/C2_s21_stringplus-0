#include "s21_string.h"

// Копирует до n символов из строки, на которую указывает src, в dest
char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
    s21_size_t i;
    for (i = 0; i < n; i++, src++) {
        if (!*src) break;
    }
    if (i < n) {
        s21_memcpy(dest, src, i);
        s21_memset(dest + i, 0, n - i);
    } else {
        s21_memcpy(dest, src, n);
    }
    return dest;
}
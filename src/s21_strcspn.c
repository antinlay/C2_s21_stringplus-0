#include "s21_string.h"

// Вычисляет длину начального сегмента str1, который полностью состоит из символов, не входящих в str2
s21_size_t s21_strcspn(const char *str1, const char *str2) {
    const char *p, *spanp;
    char c, sc;
    for (p = str1;;) {
        c = *p++;
        spanp = str2;
        do {
            if ((sc = *spanp++) == c) return(p - 1 - str1);
        } while (sc != 0);
    }
}
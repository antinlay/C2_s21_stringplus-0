// #include <string.h>
#include "s21_string.h"

// int main(void) {
//     char dest[] = "ghjldfhkjgdkgjhfd\0";
//     char dest0[] = "ghjldfhkjgdkgjhfd\0";
//     char src[] = "^%^&*^&Y*&#IHJF\0";
//     // size_t n = 5;
//     printf("%ld\n", s21_strcspn(dest, src));
//     // s21_strncpy(dest0, src, n);
//     printf("%ld", s21_strcspn(dest, dest0));
//     return 0;
// }
// Вычисляет длину начального сегмента str1, который полностью состоит из символов, не входящих в str2
size_t s21_strcspn(const char *str1, const char *str2) {
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
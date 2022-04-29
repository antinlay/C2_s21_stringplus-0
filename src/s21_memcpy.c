// #include <string.h>
#include "s21_string.h"

// int main(void) {
//     char dest[] = "ghjldfhkjgdkgjhfd\0";
//     char dest0[] = "ghjldfhkjgdkgjhfd\0";
//     char src[] = "^%^&*^&Y*&#IHJF\0";
//     s21_size_t n = 5;
//     // memcpy(dest, src, n);
//     // puts(dest);
//     s21_memcpy(dest0, src, n);
//     // puts(dest0);
//     return 0;
// }

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
    for (int i = 0; i < (int)n; ++i) *((char*)dest + i) = *((char*)src + i);
    return (char*)dest;
}
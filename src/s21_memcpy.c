// #include <string.h>
#include "s21_string.h"

// int main(void) {
//     char dest[] = "ghjldfhkjgdkgjhfd\0";
//     char dest0[] = "ghjldfhkjgdkgjhfd\0";
//     char src[] = "^%^&*^&Y*&#IHJF\0";
//     size_t n = 5;
//     memcpy(dest, src, n);
//     puts(dest);
//     s21_memcpy(dest0, src, n);
//     puts(dest0);
//     return 0;
// }

void *s21_memcpy(void *dest, const void *src, size_t n) {
	char *dst = dest;
	const char *s = src;
    while (n-- > 0) *dst++ = *s++;
    return dst;
}
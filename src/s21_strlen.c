// #include <string.h>
#include "s21_string.h"

// int main(void) {
//     char dest[] = "ghjldfhkjgdkgjhfd\0";
//     printf("%zu\n", s21_strlen(dest));
//     printf("%zu", strlen(dest));
//     return 0;
// }

s21_size_t s21_strlen(const char *str) {
    register const char *s;

	for (s = str; *s; ++s);
	return(s - str);
}
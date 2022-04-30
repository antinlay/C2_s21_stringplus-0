#include <stdio.h>
// #include <string.h>
#include "s21_string.h"


char *s21_strchr(const char *str, int c) {
    for (; *str != '\0' && *str != c; ++str);
    return *str == c ? (char *) str : NULL;
}


// int main() {

//     char str[100]= "hello everybody";
//     printf(s21_strchr(str, 'l'));

//     return 0;
// }

// #include <string.h>
// #include <stdio.h>
#include "string.h"

char *s21_strrchr(const char *str, int c) {
    char *save;
    char ch;

    for (save = (char *) 0; (ch = *str); str++) {
        if (ch == c) save = (char *) str;
    }
    return save;
}

// int main(void) {
//     char dest[] = "ghjldfhk22dkgjhfd\0";
//     int k = 'j';
//     puts(s21_strrchr(dest, k));
//     puts(strrchr(dest, k));
// }
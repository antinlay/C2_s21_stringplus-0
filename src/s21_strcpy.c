#include "s21_string.h"

char *s21_strcpy(char *dest, const char *src) {
    char *s_dest = dest;
    while ((*dest++ = *src++) != '\0') {
    }
    return s_dest;
}

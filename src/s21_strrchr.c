#include "string.h"

char *s21_strrchr(const char *str, int c) {
    char *save;
    char ch;

    for (save = (char *)0; (ch = *str); str++) {
        if (ch == c) save = (char *)str;
    }
    return save;
}

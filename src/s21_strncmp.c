#include "s21_string.h"

int s21_strncmp(const char* str1, const char* str2, s21_size_t n) {
    s21_size_t i;
    for (i = 0; i < n - 1; i++) {
        if (str1[i] != str2[i]) break;
    }
    return str1[i] - str2[i];
}

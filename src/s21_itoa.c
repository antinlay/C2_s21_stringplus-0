#include "s21_string.h"
// #include <stdio.h>

void s21_itoa(int n, char *str) {
    int num = 0, i = 0;
    // num - temp chisla, i - kolichestvo celyh desyatkov
    if (n < 0) {
        num = (n = -n);
        for (i = 1; num >= 10; num /= 10) {
            i *= 10;
        }
        *str++ = '-';
        for (; i > 0; i /= 10) {
            *str++ = 48 + n / i;  // esli i < 10 togda i = 1
            n %= i;
        }
        *str = '\0';
    } else {
        num = n;
        for (i = 1; num >= 10; num /= 10) {
            i *= 10;
        }
        for (; i > 0; i /= 10) {
            *str++ = 48 + n / i;  // esli i < 10 togda i = 1
            n %= i;
        }
        *str = '\0';
    }
}

// int main(void) {
//     char str1[40];
//     int num = -431;
//     s21_itoa(num, str1);
//     printf("%s", str1);
//     return 0;
// }

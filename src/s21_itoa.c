// #include "s21_string.h"
#include <stdio.h>
#include <string.h>

// void s21_itoa(int m, char *str) {

//         int power = 0, j = 0;
//         j = m;
//         for (power = 1; j >= 10; j /= 10)
//             power *= 10;
//         for (; power > 0; power /= 10) {
//             *str++ = 48 + m / power;
//             m %= power;
//         }

// }

void s21_itoa(long long int n, char *str) {
    // char *tmp;
    long int ten = 10;
    long int asc_0 = 48;
    long int num = 0;
    long int i = 0;
    int neg = 0;
    int len = 0;
    if (n < 0) {
        num = -n;
        neg = 1;
    } else {
        num = n;  // prisvaivaem num dannoe chislo
    }
    //  nahodim kolichestvo celyh desyatkov v num
    for (i = 1; num >= ten; num /= ten) {
        i *= ten;
        ++len;
    }
    //  pribavlyaem smeshenie otnositelno simvola '0' (decimal ASCII 48)
    for (; i > 0; i /= ten) {
        *str++ = asc_0 + n / i;  // esli i < 10 togda i = 1
        n %= i;
    }
    *str = '\0';
    if (neg == 1) {
        for (size_t i = len; i > 0; --i) {
            str[i + 1] = str[i];
        }
        for (size_t i = 0; i < 1; ++i) {
            str[i] = '-';
        }
    }
}

int main(void) {
    char str[40];
    // char *t;
    int i = -1656;
    // unsigned long long int in = i;
    // t = str;
    // do {
    // 	*t = "0123456789"[i % 10];
    //     *t += 1;
    //     printf("%s\n", t);
    // } while (i /= 10);
    // s21_itoa(i, s);
    s21_itoa(i, str);
    // sprintf(s, "Alina formmat %2d", i);

    // printf("%s", s21_i_to_a(n));
    // printf("%s", str);
    printf("%s", str);
    // char buf[n + 2];
    // char p[2] = "\0";

    // printf("%u", s21_strlen(p));
}

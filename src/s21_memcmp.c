#include "s21_string.h"

int s21_memcmp(s1, s2, n) const void *s1, *s2;
s21_size_t n;
{
    if (n != 0) {
        const unsigned char *p1 = s1, *p2 = s2;
        do {
            if (*p1 != *p2) return (*p1 - *p2);
            p1++;
            p2++;
            n--;
        } while (n != 0);
    }
    return (0);
}

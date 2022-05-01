#include "s21_string.h"
#include <stdio.h>

void *s21_memchr(const void *str, int c, s21_size_t n)
{
    int result = 0;
    char *s;
    if (n != 0)
    {
        const unsigned char *p = str;
        do
        {
            if (*p == c)
            {
                s = ((void *)(p));
                result = 1;
                break;
            }
            else
            {
                p++;
                n--;
            }
        } while (n != 0);
    }
    return (result == 1) ? s : s21_NULL;
}
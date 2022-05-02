#include "s21_string.h"

char *s21_strtok(char *str, const char *delim)
{

    int s = 0;
    static char *next;

    if (str)
    {
        next = str;
        while (*next && s21_strchr(delim, *next))
            *next++ = '\0';
    }
    if (!*next)
    {
        s = 1;
    } else {
        str = next;
        while (*next && !s21_strchr(delim, *next))
            ++next;
        while (*next && s21_strchr(delim, *next))
            *next++ = '\0';
    }
    return (s == 1) ? s21_NULL : str;
}
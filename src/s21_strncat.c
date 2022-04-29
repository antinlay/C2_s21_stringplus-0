#include <stdio.h>
// #include <string.h>
#include "s21_string.h"

char *s21_strncat(char *dst, const char *src, s21_size_t n)
{
    if (n != 0)
    {
        char *d = dst;
        const char *s = src;
        while (*d != 0)
            d++;
        do
        {
            if ((*d = *s) == 0)
                break;
            s++;
            d++;
        } while (--n != 0);
        {
            *d = 0;
        }
    }
    return (dst);
}

// int main()
// {
//     char source1[4] = "000";
//     char source2[15] = "000";
//     char app[15] = "12345";

//     printf("stingh app:  %s\n", app);

//     strncat(source1, app, 3);
//     printf("stingh source1: %s\n", source1);

//     strncat(source2, app, 7);
//     printf("stingh source2: %s\n", source2);

//     char source11[15] = "000";
//     char source22[15] = "000";

//     char app1[15] = "12345";

//     printf("s21_strncat app:  %s\n", app1);

//     s21_strncat(source11, app1, 3);

//     printf("s21_strncat source1: %s\n", source11);

//     s21_strncat(source22, app1, 7);

//     printf("s21_strncat source2: %s\n", source22);

//     return 0;
// }

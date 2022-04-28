//#if defined(LIBC_SCCS) && !defined(lint)
//static char sccsid[] = "@(#)memchr.c;
//#endif /* LIBC_SCCS and not lint */
//#include <sys/cdefs.h>
//__FBSDID("$FreeBSD: src/lib/libc/string/memchr.c,v 1.4 2002/03/21 18:44:54 obrien Exp $");

//memchr – поиск первого вхождения указанного символа в массиве

#include "s21_string.h"
#include <stdio.h>
// #include <string.h>
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
// проверка
// int main()
// {

//     char *sym;
//     char *sym1;
//     // исходные массивы
//     unsigned const char str[5] = "1234";
//     unsigned const char str1[5] = "1234";

//     sym = s21_memchr(str, '!', 4);
//     sym1 = memchr(str1, '!', 4);
//     if (sym != s21_NULL)
//         sym[0] = '!';
//     if (sym1 != s21_NULL)
//         sym1[0] = '!';
//     printf("%s\n", sym);
//     printf("%s\n", sym1);
// }

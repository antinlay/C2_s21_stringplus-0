//#if defined(LIBC_SCCS) && !defined(lint)
//static char sccsid[] = "@(#)memchr.c;
//#endif /* LIBC_SCCS and not lint */
//#include <sys/cdefs.h>
//__FBSDID("$FreeBSD: src/lib/libc/string/memchr.c,v 1.4 2002/03/21 18:44:54 obrien Exp $");

#include <string.h>
#include <stdio.h>

void *s21_memchr(s, c, n)
    const void *s;
    unsigned char c;
    size_t n;
{
    if (n != 0) {
        const unsigned char *p = s;

        do {
            if (*p == c)
                return ((void *)(p));
            p++;
            n--;
        } while (n != 0);
    }
    return (NULL);
}
//проверка
int main () {
    
    char *sym;
    char *sym1;
    // исходные массивы
    unsigned const char str[5] = "1234";
    unsigned const char str1[5] = "1234";
    
    sym = s21_memchr (str, '3', 4);
    sym1 = memchr (str1, '3', 4);
    if (sym != NULL)
          sym[0]='!';
    if (sym1 != NULL)
          sym1[0]='!';
    printf("%s\n", sym);
    printf("%s\n", sym1);
    
}

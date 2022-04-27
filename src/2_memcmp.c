//#if defined(LIBC_SCCS) && !defined(lint)
//static char sccsid[] = "@(#)memcmp.c    8.1 (Berkeley) 6/4/93";
//#endif /* LIBC_SCCS and not lint */
//#include <sys/cdefs.h>
//__FBSDID("$FreeBSD: src/lib/libc/string/memcmp.c,v 1.4 2002/03/21 18:44:54 obrien Exp $");

#include <stdio.h>
#include <string.h>


int
s21_memcmp(s1, s2, n)
    const void *s1, *s2;
    size_t n;
{
    if (n != 0) {
        const unsigned char *p1 = s1, *p2 = s2;

        do {
            if (*p1 != *p2)
                return (*p1 - *p2);
            p1++;
            p2++;
            n--;
        } while (n != 0);
    }
    return (0);
}

// провека
int main () {
   // Исходные массивы
   unsigned char src[15]="1234567890";
   unsigned char dst[15]="1234567890";

   // memcmp сравниваем первые 10 байт массивов src и dst
   if (memcmp (src, dst, 10) == 0)
      printf ("memcmp области памяти в массиве одинаковые.\n");
   else
      printf ("memcmp области памяти в массиве различные.\n");
    
    // s21_memcmp сравниваем первые 10 байт массивов src и dst
    if (memcmp (src, dst, 10) == 0)
       printf ("s21memcmp области памяти в массиве одинаковые.\n");
    else
       printf ("s21memcmp области памяти в массиве различные.\n");
    
   return 0;
}

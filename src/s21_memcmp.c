// Функция s21_memcmp побайтно сравнивает два массива (области памяти), 
// на которые указывают аргументы arr1 и arr2. Каждый байт массива 
// определяется типом unsigned char. Сравнение продолжается, 
// пока не будут проверено n байт или пока не встретятся 
// отличающиеся байты.

#include "s21_string.h"
#include <stdio.h>
#include <stddef.h>



int
s21_memcmp(s1, s2, n)
    const void *s1, *s2;
    s21_size_t n;
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
// int main () {
//    // Исходные массивы
//    unsigned char src[15]="1234567890";
//    unsigned char dst[15]="1234567890";

//    // memcmp сравниваем первые 10 байт массивов src и dst
//    if (memcmp (src, dst, 10) == 0)
//       printf ("memcmp области памяти в массиве одинаковые.\n");
//    else
//       printf ("memcmp области памяти в массиве различные.\n");
    
//     // s21_memcmp сравниваем первые 10 байт массивов src и dst
//     if (memcmp (src, dst, 10) == 0)
//        printf ("s21memcmp области памяти в массиве одинаковые.\n");
//     else
//        printf ("s21memcmp области памяти в массиве различные.\n");
    
//    return 0;
// }

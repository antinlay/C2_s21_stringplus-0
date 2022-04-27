#include <stdio.h>
#include <string.h>
#include <stddef.h>

void * s21_memmove (void *dest, const void *src, size_t len)
{
  char *d = dest;
  const char *s = src;
      if (d < s) {
    while (len != 0)
      *d = *s;
    d++;
    s++;
    len--;
    } else {
        const char *lasts = s + (len-1);
        char *lastd = d + (len-1);
        while (len != 0) {
        *lastd = *lasts;
        lastd--;
        lasts--;
        len--;
        }
    }
  return dest;
}

//проверка
int main ()
{
   // Исходный массив данных для memmove
   unsigned char src_memmove[10]="123456789";
    
   // печать массива memmove
   printf ("src memmove старый: %s\n",src_memmove);

   // Копируем 3 байт массива memmove
   memmove (&src_memmove[4], &src_memmove[3], 3);

   // Печать массива src_memove на консоль для memmove
   printf ("src memmove новый: %s\n",src_memmove);
    
    // Исходный массив данных для s21_memmove
    unsigned char src_s21_memove[10]="123456789";
    
    // Вывод массива src на консоль
    printf ("src s21 memove старый: %s\n",src_s21_memove);

    // Копируем 3 байт
    memmove (&src_s21_memove[4], &src_s21_memove[3], 3);

    // Вывод массива src на консоль
    printf ("src s21 memove новый: %s\n",src_s21_memove);

   return 0;
}

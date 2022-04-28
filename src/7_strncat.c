#include <stdio.h>
#include <string.h>

char * s21_strncat(char *  dst, const char *  src, s21_size_t n)
{
    if (n != 0) {
        char *d = dst;
        const char *s = src;

        while (*d != 0)
            d++;
        do {
            if ((*d = *s) == 0)
                break;
            s++;
            d++;
        } while (--n != 0); {
         
            *d = 0;
            
        }
    }
    return (dst);
}

int main ()
{
   // Массивы для добавления строк
   char source1[15]="000";
   char source2[15]="000";
   // Строка добавления
   char app[15]="12345";

   // Печать добавляемой строки
   printf ("stingh app:  %s\n",app);

   // Добавление строки app в строку src1, но не более трех символов
   strncat (source1, app,3);
   // Вывод результата
   printf ("stingh source1: %s\n",source1);

   // Добавление строки app в строку src2, но не более семи символов
   strncat (source2, app,7);
   // Вывод результата
   printf ("stingh source2: %s\n",source2);
    
    // Массивы для добавления строк
    char source11[15]="000";
    char source22[15]="000";
    // Строка добавления
    char app1[15]="12345";

    // Печать добавляемой строки
    printf ("s21_strncat app:  %s\n",app1);

    // Добавление строки app в строку src1, но не более трех символов
    s21_strncat (source11, app1,3);
    // Вывод результата
    printf ("s21_strncat source1: %s\n",source11);

    // Добавление строки app в строку src2, но не более семи символов
    s21_strncat (source22, app1,7);
    // Вывод результата
    printf ("s21_strncat source2: %s\n",source22);


   return 0;
}

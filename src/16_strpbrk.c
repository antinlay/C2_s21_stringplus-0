#include <stdio.h>
#include <string.h>

char * s21_strpbrk(const char *s1, const char *s2)
{
    const char *scanp;
    int c, sc;

    while ((c = *s1) != 0) {
        s1++;
            for (scanp = s2; (sc = *scanp++) != '\0';)
                if (sc == c)
                    return ((char *)(s1 - 1));
        }
        return (NULL);
}

int main ()
{
   // Массив со строкой для поиска
   char str [11]="01234567";
   // Набор символов, которые должны входить в искомый сегмент
   char sym [10]="69";
   // Переменная, в которую будет занесен адрес первого найденного символа
   char *isym;

   //Поиск символов
   isym = strpbrk (str,sym);

   //Вывод результата поиска на консоль
   if ( isym == NULL)
      printf ("Символы не найдены\n");
   else
      printf ("Искомый символ на позиции %ld\n",isym-str+1);
    
    //Поиск символов
    isym = s21_strpbrk (str,sym);

    //Вывод результата поиска на консоль
    if ( isym == NULL)
       printf ("Символы не найдены\n");
    else
       printf ("Искомый символ на позиции %ld\n",isym-str+1);

   return 0;
}

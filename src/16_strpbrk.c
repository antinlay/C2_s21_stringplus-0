#include <stdio.h>
#include <string.h>

char * s21_strpbrk(const char *string1, const char *string2)
{
    const char *scanp;
    int c, sc;
    int result = 0;
    char * s;

    while ((c = *string1) != 0) {
        string1++;
        for (scanp = string2; (sc = *scanp++) != '\0';) {
                if (sc == c && result == 0) {
                    s = ((char *)(string1 - 1));
                    result = 1;
                   }
        }
    }
    return (result == 1) ? s : NULL;
                    
}

int main ()
{
   // Массив со строкой для поиска
   char str [11]="01234567";
   // Набор символов, которые должны входить в искомый сегмент
   char sym [10]="143";
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

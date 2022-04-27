#include <stdio.h>
#include <string.h>

int s21_strcmp(char *str1, char *str2) {
    for ( ; *str1 && *str1 == *str2; str1++, str2++) {
        }
    return (*str1 - *str2);
}

int main (void)
{
   // Сравниваемые строки
   char str1[1024]="12305";
   char str2[1024]="12345";
  
   // Сравниваем две строки
   if (strcmp (str1, str2)==0)
      puts ("strcmp Строки идентичны\n");
   else
      puts ("strcmp Строки отличаются\n");
    // Сравниваем две строки
    if (s21_strcmp (str1, str2)==0)
       puts ("s21_strcmp Строки идентичны\n");
    else
       puts ("s21_strcmp Строки отличаются\n");

   return 0;
}

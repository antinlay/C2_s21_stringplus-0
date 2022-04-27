#include <string.h>
#include <stdio.h>

int
s21_strncmp(const char *s1, const char *s2, size_t n)
{
    int result = 0;
    if (n != 0) {
    do {
        if (*s1 != *s2++)
            result = (*(const unsigned char *)s1 -
                *(const unsigned char *)(s2 - 1));
        if (*s1++ == '\0')
            break;
    } while (--n != 0);
    }
    return (result);
}

    int main ()
    {
       // Сравниваемые строки
       char str1[16]="1234567890";
       char str2[16]="11234507890";
        int n = 5;
      
       // Сравниваем первые пять символов двух строк
       if (strncmp (str1, str2, n) == 0)
          printf("strncmp Первые " "%d"" символов строк идентичны\n", n);
       else
           printf("strncmp Первые " "%d"" символов строк не идентичны\n", n);
        
      
        // Сравниваем первые пять символов двух строк
        if (s21_strncmp (str1, str2,5) == 0)
            printf("s21_strncmp Первые " "%d"" символов строк идентичны\n", n);
        else
            printf("s21_strncmp Первые " "%d"" символов строк не идентичны\n", n);

       return 0;
    }

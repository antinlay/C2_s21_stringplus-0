#include <stdio.h>
#include "s21_string.h"
#include <stddef.h>
// #include <string.h>

void *s21_memset(void *str, int c, s21_size_t n)
{
  char *b_char = (char *)str;
  while (*b_char && n > 0)
  {
    *b_char = c;
    b_char++;
    n--;
  }

  return (str == s21_NULL) ? s21_NULL : str;
}

// int main() {

//     char str[] = "hello everybody";

//         s21_memset(str, 'a', 5);
//         printf("%s\n", str);

//         memset(str, 'a', 5);
//         printf("%s\n", str);

//     return 0;
// }

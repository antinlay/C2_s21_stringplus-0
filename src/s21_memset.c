#include "s21_string.h"

void  *s21_memset(void *str, int c, s21_size_t n) {
    char *b_char = (char *)str;
    int res = 0;

        if (str == NULL) res = 1;
    
  while(*b_char && n > 0)
    {
      *b_char = c;
      b_char++;
      n--;
    }
  return (res = 0) ? (str) : NULL;
}

// int main() {
    
//     char str[] = "hello everybody";
    
//         s21_memset(str, 'a', 5);
//         printf("%s\n", str);
    
//     return 0;
// }

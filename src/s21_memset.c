#include "s21_string.h"

void  *s21_memset(void *str, int c, size_t n) {
    char *b_char = (char *)str;

        if (str == NULL) return NULL;
    
  while(*b_char && n > 0)
    {
      *b_char = c;
      b_char++;
      n--;
    }
  return(str);
}

// int main() {
    
//     char str[] = "hello everybody";
    
//         s21_memset(str, 'a', 5);
//         printf("%s\n", str);
    
//     return 0;
// }

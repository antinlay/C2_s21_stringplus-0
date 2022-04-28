#include "s21_string.h"
// #include <string.h>

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
  return (res = 1) ? NULL : (str);
}

// int main() {
    
//     char str[] = "FUCKlo everybody";
    
//         memset(str, '1', 5);
//         printf("%s\n", str);
//         s21_memset(str, '2', 3);
//         printf("%s\n", str);
    
//     return 0;
// }

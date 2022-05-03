#include "s21_string.h"
// #include <stdlib.h>

void *s21_to_lower(const char *str) {
  int len = s21_strlen(str);
  int i = 0;
  char* low_str = s21_NULL;
  low_str = malloc((len) * sizeof(char));
  
  while (i < len) {
    if (str[i] >= 'A' && str[i] <= 'Z') {
        low_str[i] = str[i] + 32;
    } else {
        low_str[i] = str[i];
    }
    i++;
  }
  low_str[i] = '\0';
  return len == 0 ? s21_NULL : low_str;
}

#include "s21_string.h"
#include <stdlib.h>

void *s21_to_lower(const char *str) {
  int len = s21_strlen(str);
  int i = 0;
  char* up_str = (char*)malloc((len+1) * sizeof(char));
  
  while (i < len) {
    if (str[i] >= 'A' && str[i] <= 'Z') {
      up_str[i] = str[i] + 32;
    }
    ++i;
  }
  return len != 0 ? up_str : s21_NULL;
}
#include "s21_string.h"
#include <stdlib.h>

void *s21_to_upper(const char *str) {
  int len = s21_strlen(str);
  int i = 0;
  char* up_str = s21_NULL;
  up_str = (char*)malloc((len) * sizeof(char));
  
  while (i < len) {
    if (str[i] >= 'a' && str[i] <= 'z') {
      up_str[i] = str[i] - 32;
    } else {
      up_str[i] = str[i];
    }
    i++;
  }
  return len != 0 ? up_str : s21_NULL;
}
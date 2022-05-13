#include "s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  const char *scanp;
  int c, sc;
  int result = 0;
  char *s = "";

  while ((c = *str1) != 0) {
    str1++;
    for (scanp = str2; (sc = *scanp++) != '\0';) {
      if (sc == c && result == 0) {
        s = ((char *)(str1 - 1));
        result = 1;
      }
    }
  }
  return (result == 1) ? s : s21_NULL;
}

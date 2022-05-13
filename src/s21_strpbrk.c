#include "s21_string.h"

char *s21_strpbrk(const char *string1, const char *string2) {
  const char *scanp;
  int c, sc;
  int result = 0;
  char *s = "";

  while ((c = *string1) != 0) {
    string1++;
    for (scanp = string2; (sc = *scanp++) != '\0';) {
      if (sc == c && result == 0) {
        s = ((char *)(string1 - 1));
        result = 1;
      }
    }
  }
  return (result == 1) ? s : s21_NULL;
}

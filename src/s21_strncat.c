#include "s21_string.h"

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  if (n != 0) {
    char *d = dest;
    const char *s = src;
    while (*d != 0) d++;
    do {
      if ((*d = *s) == 0) break;
      s++;
      d++;
    } while (--n != 0);
    { *d = 0; }
  }
  return dest;
}

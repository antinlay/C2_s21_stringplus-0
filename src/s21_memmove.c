#include "s21_string.h"

void *s21_memmove(void *dest, const void *src, s21_size_t n) {
  char *d = dest;
  const char *s = src;
  if (d < s) {
    while (n--) {
      *d = *s;
      d++;
      s++;
    }
  } else {
    const char *lasts = s + (n - 1);
    char *lastd = d + (n - 1);
    while (n != 0) {
      *lastd = *lasts;
      lastd--;
      lasts--;
      n--;
    }
  }
  d[s21_strlen(dest)] = '\0';
  return dest;
}

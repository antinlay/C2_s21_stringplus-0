#include "s21_string.h"

void * s21_memmove (void *dest, const void *src, s21_size_t len)
{
  char *d = dest;
  const char *s = src;
      if (d < s) {
    while (len--)
      *d = *s;
    d++;
    s++;
    len--;
    } else {
        const char *lasts = s + (len-1);
        char *lastd = d + (len-1);
        while (len != 0) {
        *lastd = *lasts;
        lastd--;
        lasts--;
        len--;
        }
    }
  return dest;
}
#include "s21_string.h"

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  const char *p;
  char sc;
  for (p = str1;;) {
    const char *spanp;
    char c = *p++;
    spanp = str2;
    do {
      if ((sc = *spanp++) == c) return (p - 1 - str1);
    } while (sc != 0);
  }
}

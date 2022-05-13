#include "s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  const unsigned char *p1 = str1, *p2 = str2;
  int res = 0;
  for (s21_size_t i = 0; i < n && res == 0; i++) {
    if (p1[i] != p2[i]) {
      res = p1[i] - p2[i];
    }
  }
  return res;
}

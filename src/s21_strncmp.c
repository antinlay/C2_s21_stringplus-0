#include "s21_string.h"

int s21_strncmp(const char* s1, const char* s2, s21_size_t n) {
  s21_size_t i;
  for (i = 0; i < n - 1; i++) {
    if (s1[i] != s2[i]) break; 
    }
  return s1[i] - s2[i];
}
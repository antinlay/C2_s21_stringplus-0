#include "s21_string.h"

s21_size_t s21_strlen(const char *str) {
  const char *s;
  for (s = str; *s != '\0'; ++s) {
  }
  s21_size_t len = s - str;
  return len;
}

#include "s21_string.h"

char* s21_strcat(char* dest, const char* src) {
  char* start = dest;
  int len = s21_strlen(dest);
  int iter = 0;

  while ((*(dest + len + iter++) = *src++) && (*src != '\0')) {
  }

  return start;
}
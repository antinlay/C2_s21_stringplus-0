#include "s21_string.h"
// #include <stdlib.h>

void* s21_insert(const char* src, const char* str, s21_size_t start_index) {
  char* len;
  int ok = -1;
  s21_size_t len_src;

  if (src == s21_NULL || str == s21_NULL) {
    len = s21_NULL;
    ok = 0;
  }

  if (ok == -1) {
    len_src = s21_strlen(src);
    if (len_src < start_index) {
      len = s21_NULL;
      ok = 1;
    }
  }

  char* result = s21_NULL;
  s21_size_t allStrLen = 0;

  if (ok == -1) {
    s21_size_t len_str;
    len_str = s21_strlen(str);
    allStrLen = len_src + len_str;

    result = (char*)calloc((len_src + len_str +1), sizeof(char));

    for (int i = 0; i < (int)start_index; i++) {
      result[i] = src[i];
    }

    s21_strcat(result, str);

    for (int i = 0; i + start_index + len_str < len_src + len_str; i++) {
      result[i + start_index + len_str] = src[i + start_index];
    }
  }
  return allStrLen != 0 || len != s21_NULL ? result : s21_NULL;
}
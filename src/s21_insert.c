#include "s21_string.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *pointer = s21_NULL;
  if (src != s21_NULL && str != s21_NULL) {
    s21_size_t src_length = s21_strlen(src);
    s21_size_t str_length = s21_strlen(str);
    s21_size_t memory_size = src_length + str_length + 1;
    if (start_index <= src_length) {
      pointer = calloc(memory_size, sizeof(char));
      if (pointer != s21_NULL) {
        for (s21_size_t i = 0; i < start_index; i++) {
          pointer[i] = src[i];
        }
        for (s21_size_t i = 0; i < str_length; i++) {
          pointer[i + start_index] = str[i];
        }
        for (s21_size_t i = 0; i < src_length - start_index; i++) {
          pointer[i + start_index + str_length] = src[i + start_index];
        }
        pointer[memory_size - 1] = '\0';
      }
    }
  }
  return pointer;
}

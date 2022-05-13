#include "s21_string.h"

// void* s21_insert(const char* src, const char* str, s21_size_t start_index) {
//   char* len;
//   int ok = -1;
//   s21_size_t len_src;

//   if (src == s21_NULL || str == s21_NULL) {
//     len = s21_NULL;
//     ok = 0;
//   }

//   if (ok == -1) {
//     len_src = s21_strlen(src);
//     if (len_src < start_index) {
//       len = s21_NULL;
//       ok = 1;
//     }
//   }

//   char* result = s21_NULL;
//   s21_size_t allStrLen = 0;

//   if (ok == -1) {
//     s21_size_t len_str;
//     int end_str = 0;
//     len_str = s21_strlen(str);
//     allStrLen = len_src + len_str;

//     result = (char*)calloc((len_src + len_str + 1), sizeof(char));

//     for (int i = 0; i < (int)start_index; i++) {
//       result[i] = src[i];
//     }

//     s21_strcat(result, str);

//     for (int i = 0; i + start_index + len_str < len_src + len_str; i++) {
//       result[i + start_index + len_str] = src[i + start_index];
//       end_str = i + start_index + len_str;
//     }
//     result[end_str + 1] = '\0';
//   }
//   return allStrLen != 0 || len != s21_NULL ? result : s21_NULL;
// }
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
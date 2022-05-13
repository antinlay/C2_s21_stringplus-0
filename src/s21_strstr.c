#include "s21_string.h"

char *s21_strstr(const char *s, const char *find) {
  char c;
  int z = 0;

  if ((c = *find++) != '\0') {
    s21_size_t len = s21_strlen(find);
    do {
      char sc;
      do {
        if ((sc = *s++) == '\0') {
          z = 1;
          break;
        }
      } while (sc != c);
      if (z == 1) break;
    } while (s21_strncmp(s, find, len) != 0);
    s--;
  }
  return (z == 1) ? s21_NULL : ((char *)s);
}

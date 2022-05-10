#include "s21_string.h"

char *s21_convert(unsigned int num, int base) {
  static char Representation[] = "0123456789ABCDEF";
  static char buffer[50];
  char *ptr;
  ptr = &buffer[49];
  *ptr = '\0';
  do {
    *--ptr = Representation[num % base];
    num /= base;
  } while (num != 0);
  return ptr;
}

void s21_itoa(int n, int base, char *buf) {
  char *str;
  if (n < 0) {
    n = -n;
    *buf = '-';
    buf++;
  }
  str = s21_convert(n, base);
  while (*str != '\0') {
    *buf = *str;
    str++;
    buf++;
  }
  *buf = '\0';
}

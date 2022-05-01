#include <stdio.h>
// #include <stdlib.h>
#include <string.h>
#include <stdarg.h>

struct specifiers {
    char flag;
    int width;
    int acc;
    char length;
    char spec;
} specifiers;

int length(const char* str) {
  return (*str == 'L' || *str == 'l' || *str == 'h');
}

int flag(const char* format) {
  return (*format == '-' || *format == '+' || *format == ' ' || *format == '#' ||
          *format == '0');
}

int numb(const char* format) { return (*format >= '0' && *format <= '9'); }

int number(const char* format, int* i) {
  int res = 0;
  int k = 0;
  while (numb(format + *i)) {
    res *= 10;
    res += *(format + *i) - '0';
    (*i)++;
    k++;
  }
  if (k == 0) res = -1;
  return res;
}

void param(int* d, char* format, va_list* p_arg, int* i) {
  int sign = 1;
  if (*(format + *i) == '-') {
    sign = -1;
    (*i)++;
  } else if (*(format + *i) == '+') {
    (*i)++;
  }
  *d = sign * number(format, i);
  if (*(format + *i) == '*') {
    *d = va_arg(*p_arg, int);
    (*i)++;
  }
}

void pfill(char* format, va_list* p_arg, int* i) {
  (*i)++;
  if (flag(format + *i)) {
    specifiers.flag = *(format + *i);
    (*i)++;
  } else {
    specifiers.flag = 'e';
  }
  param(&(specifiers.width), format, p_arg, i);
  if (*(format + *i) == '.') {
    (*i)++;
    param(&(specifiers.acc), format, p_arg, i);
  } else {
    specifiers.acc = -1;
  }
  if (length(format + *i)) {
    (specifiers).length = *(format + *i);
    (*i)++;
  } else {
    (specifiers).length = 'e';
  }
  (specifiers).spec = *(format + *i);
  if (*(format + *i) == 'c' && (specifiers).width == -1)
    (specifiers).width = 1;
  else if ((*(format + *i) == 'e' || *(format + *i) == 'E' || *(format + *i) == 'f' ||
            *(format + *i) == 'g' || *(format + *i) == 'G') &&
           ((specifiers).acc == -1))
    (specifiers).acc = 6;
}

int s21_sprintf(char *str, char *format, ...) {
    va_list p_arg;
    int count = 0;
    // int out = 0;
    va_start(p_arg, format);
    for (int i = 0; *(format + i) != '\0'; ++i) {
        if (*(format + i) != '%') {
            str[strlen(str)] = *(format + i);
        }
        if (*(format + i) == 'd') {
            pfill((char*)(format), &p_arg, &i);
            str[strlen(str)] = va_arg(p_arg, int);
        }
  }
  va_end(p_arg);
  return count;


    // int out = 0; int count = 0;
    // va_list p_arg;         //указатель va_list
    // va_start(p_arg, format);    // устанавливаем указатель
    // printf("%s\n", format);
    // for (char *p = format;*p; p++) {
    //     if (*p != '%') {
    //         out += 1;
    //         printf("%d\n", out);
    //         str[strlen(str)] = *p;
    //         if (*p == 'd') {
    //             count += 1;
    //             str[strlen(str)] = va_arg(p_arg, count);
    //             printf("%d\n", count);
    //         }
    //     }

    // }
    // printf("%s\n", str);
    // va_end(p_arg); // завершаем обработку параметров
    // return out;
}

int main(void) {
    char str[50] = "";
    char format[20] = "My age %d years %d";
    int age = 23;
    // sprintf(str, format, age);
    // printf("%s\n", str);
    int res;
    res = s21_sprintf(str, format, age, age);
    printf("%s\n", str);
    printf("%d\n", res);
    return 0;
}

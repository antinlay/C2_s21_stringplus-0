#include "s21_string.h"

struct specifiers {
  char flag;
  int width;
  int acc;
  char length;
  char spec;
} specifiers;

int numb(const char* str) { return (*str >= '0' && *str <= '9'); }
int length(const char* str) {
  return (*str == 'L' || *str == 'l' || *str == 'h');
}

int number(const char* str, int* i) {
  int res = 0;
  int k = 0;
  while (numb(str + *i)) {
    res *= 10;
    res += *(str + *i) - '0';
    (*i)++;
    k++;
  }
  if (k == 0) res = -1;
  return res;
}

int len_int(int res) {
  int k = 0;
  if (res == 0) k = 1;
  if (res < 0) res *= -1;
  while (res > 0) {
    res /= 10;
    k++;
  }
  return k;
}

int poww(int j, int p) {
  int k = j;
  if (p == 0) {
    j = 1;
  } else if (p != 1) {
    p--;
    while (p > 0) {
      j *= k;
      p--;
    }
  }
  return j;
}

void param(int* d, char* str, va_list* string, int* i) {
  int sign = 1;
  if (*(str + *i) == '-') {
    sign = -1;
    (*i)++;
  } else if (*(str + *i) == '+') {
    (*i)++;
  }
  *d = sign * number(str, i);
  if (*(str + *i) == '*') {
    *d = va_arg(*string, int);
    (*i)++;
  }
}

int pread_c_pr(char* str, int* j) {
  int k = 1;
  *(str + *j) = '%';
  (*j)++;
  *(str + *j) = '\0';
  return k;
}

int flag(const char* str) {
  return (*str == '-' || *str == '+' || *str == ' ' || *str == '#' ||
          *str == '0');
}

void pfill(char* str, va_list* string, int* i) {
    (*i)++;
    if (flag(str + *i)) {
        specifiers.flag = *(str + *i);
        (*i)++;
    } else {
        specifiers.flag = 'e';
    }
    param(&(specifiers.width), str, string, i);
    if (*(str + *i) == '.') {
        (*i)++;
        param(&(specifiers.acc), str, string, i);
    } else {
        specifiers.acc = -1;
    }
    if (length(str + *i)) {
        (specifiers).length = *(str + *i);
        (*i)++;
    } else {
        (specifiers).length = 'e';
    }
    (specifiers).spec = *(str + *i);
    if (*(str + *i) == 'c' && (specifiers).width == -1)
        (specifiers).width = 1;
    else if ((*(str + *i) == 'e' || *(str + *i) == 'E' || *(str + *i) == 'f' ||
                *(str + *i) == 'g' || *(str + *i) == 'G') &&
            ((specifiers).acc == -1))
        (specifiers).acc = 6;
}

void pcopy_int(char* copy, int res) {
  int k = len_int(res), j = 0;
  if (res < 0) res *= -1;
  for (int i = poww(10, k - 1); i > 0; i /= 10, ++j) {
    copy[j] = res / i + '0';
    res = res % i;
  }
  copy[j] = '\0';
}

void pcopy_str(char* str, int* j, const char* copy) {
  for (int k = 0; copy[k] != '\0'; ++k, (*j)++) str[*j] = copy[k];
  str[*j] = '\0';
}

void flag_read_minus(char* str, int* j, char* copy, int* len) {
  pcopy_str(str, j, copy);
  flag_read(str, j, ' ', len);
  str[*j] = '\0';
  (*len)++;
}

void flag_read(char* str, int* j, char c, int* len) {
  while (specifiers.width - *len > 0) {
    str[*j] = c;
    (*j)++;
    (*len)++;
  }
}

void flag_read_zero(char* str, int* j, char* copy, int* len) {
  flag_read(str, j, '0', len);
  pcopy_str(str, j, copy);
  (*len)++;
}

void flag_read_plus_space(char* str, int* j, char* copy, int res, int* len, int indic) {
  (*len)++;
  flag_read(str, j, ' ', len);
  if (res >= 0 && indic == 0)
    str[*j] = '+';
  else if (res >= 0 && indic == 1)
    str[*j] = ' ';
  else
    str[*j] = '-';
  (*j)++;
  pcopy_str(str, j, copy);
  (*len)++;
}

int pread_c(char* str, int* j, va_list* string) {
  char c = '\0';
  char copy[256];
  int len = 2;
  if (specifiers.length == 'l') {
    wchar_t ch = (wchar_t)va_arg(*string, int);
    c = ch;
  } else if (specifiers.length == 'e') {
    char ch = (char)va_arg(*string, int);
    c = ch;
  }
  copy[0] = c;
  copy[1] = '\0';
  if (specifiers.flag == '-') {
    flag_read_minus(str, j, copy, &len);
  } else if (specifiers.flag == '0') {
    flag_read_zero(str, j, copy, &len);
  } else {
    flag_read(str, j, ' ', &len);
    pcopy_str(str, j, copy);
  }
  return len - 1;
}

int pread_d(char* str, int* j, int res) {
  char copy[256];
  int len = len_int(res);
  if (len >= specifiers.acc && res != 0) {
    pcopy_int(copy, res);
  } else {
    int k = 0;
    int r = specifiers.acc - len;
    while (r - k > 0) {
      copy[k] = '0';
      ++k;
    }
    pcopy_int(copy + r, res);
    len += r;
  }
  if (specifiers.flag == '+')
    flag_read_plus_space(str, j, copy, res, &len, 0);
  else if (specifiers.flag == '-')
    flag_read_minus_int(str, j, copy, res, &len);
  else if (specifiers.flag == ' ')
    flag_read_plus_space(str, j, copy, res, &len, 1);
  else if ((specifiers.flag == '0') && (specifiers.acc == -1))
    flag_read_zero_int(str, j, copy, res, &len);
  else
    flag_read_int(str, j, copy, res, &len);
  return len - 1;
}
// change strlen!!!
int pread_x_o(char* str, int* j, long res, int base) {
  char copy[256], copy1[256];
  ltoaa(res, copy, base);
  int len = s21_strlen(copy), l = 0;  
  if (len >= specifiers.acc && res != 0) {
    pcopy_str(copy1, &l, copy);
  } else {
    int k = 0;
    int r = specifiers.acc - len;
    while (r - k > 0) {
      copy1[k] = '0';
      ++k;
    }
    pcopy_str(copy1, &k, copy);
    len += r;
  }
  if (specifiers.flag == '-') {
    flag_read_minus(str, j, copy1, &len);
    len--;
  } else if (specifiers.flag == '#') {
    flag_read_spec(str, j, copy1, &len, base);
    // len--;
  } else {
    flag_read(str, j, ' ', &len);
    pcopy_str(str, j, copy1);
  }
  flag_read(str, j, ' ', &len);
  return len;
}

void ltoaa(long value, char* buffer, int base) {
  if (value < 0) value *= -1;
  int i = 0;
  while (value) {
    int r = value % base;
    if (r >= 10) {
      buffer[i++] = 65 + (r - 10) + ('X' - specifiers.spec);
    } else {
      buffer[i++] = 48 + r;
    }
    value = value / base;
  }
  if (i == 0) {
    buffer[i++] = '0';
  }
  buffer[i] = '\0';
  reverse(buffer, 0, i - 1);
}

char* reverse(char* buffer, int i, int j) {
  while (i < j) {
    swapp(&buffer[i++], &buffer[j--]);
  }
  return buffer;
}

void swapp(char* x, char* y) {
  char t = *x;
  *x = *y;
  *y = t;
}

int copy_f(char* copy, long double res) {
  int len = len_int(res);
  int k = (int)res;
  if (res < 0) {
    res *= -1;
    k *= -1;
  }
  pcopy_int(copy, k);
  copy[len] = '.';
  len++;
  int l = 0;
  while (res >= 0 && l < specifiers.acc) {
    l++;
    res *= 10;
    k = (int)res % 10;
    copy[len] = k + '0';
    len++;
  }
  return len;
}

int pread_i(char* str, int* j, int res) {
  char copy1[256];
  pcopy_int(copy1, res);
  int i = 0;
  int n = number(copy1, &i);
  if (res < 0) n *= -1;
  return pread_d(str, j, n);
}

int pread_e(char* copy, int* p, long double res) {
  int k;
  int len;
  if (res < 0) res *= -1;
  if (res >= 1.0 || res * -1.0 >= 1.0) {
    k = 1;
    while (res / 10 >= 1.0) {
      (*p)++;
      res /= 10;
    }
  } else {
    k = -1;
    while (res < 1.0) {
      (*p)++;
      res *= 10;
    }
  }
  len = copy_f(copy, res);
  while (specifiers.acc - len > 0) {
    copy[len] = '0';
    ++len;
  }
  if (specifiers.spec == 'e' || specifiers.spec == 'E')
    copy[len] = specifiers.spec;
  else if (specifiers.spec == 'g')
    copy[len] = 'e';
  else if (specifiers.spec == 'G')
    copy[len] = 'E';
  ++len;
  if (k >= 0)
    copy[len] = '+';
  else
    copy[len] = '-';
  len++;
  if (*(p) >= 10) {
    copy[len] = '0' + *(p) / 10;
    ++len;
    copy[len] = '0' + (*p) % 10;
    ++len;
  } else {
    copy[len] = '0';
    ++len;
    copy[len] = '0' + *p;
    ++len;
  }
  copy[len] = '\0';
  (len)++;
  return len - 1;
}

int flag_pount(const char* copy) {
  int j = 0;
  for (int i = 0; copy[i] != '\0'; ++i)
    if (copy[i] == '.') j = 1;
  return j;
}

void flag_read_spec(char* str, int* j, char* copy, int* len, int base) {
  (*len) += 2;
  while (specifiers.width - *len > 0) {
    str[*j] = ' ';
    (*j)++;
    (*len)++;
  }
  str[*j] = '0';
  (*j)++;
  if (base == 16) {
    str[*j] = specifiers.spec;
    (*j)++;
  }
  pcopy_str(str, j, copy);
}

void flag_read_minus_int(char* str, int* j, char* copy, int res, int* len) {
  if (res < 0) {
    str[*j] = '-';
    (*j)++;
    (*len)++;
  }
  flag_read_minus(str, j, copy, len);
}

void flag_read_spec_float(char* str, int* j, char* copy, int res, int* len) {
  if (res < 0) (*len)++;
  flag_read(str, j, ' ', len);
  if (res < 0) {
    str[*j] = '-';
    (*j)++;
  }
  pcopy_str(str, j, copy);
  (*len)++;
  if (!flag_pount(copy)) {
    str[*j] = '.';
    (*j)++;
    str[*j] = '\0';
  }
}

void flag_read_zero_int(char* str, int* j, char* copy, int res, int* len) {
  if (res < 0) {
    str[*j] = '-';
    (*j)++;
    (*len)++;
  }
  flag_read_zero(str, j, copy, len);
}

void flag_read_int(char* str, int* j, char* copy, int res, int* len) {
  if (res < 0) (*len)++;
  flag_read(str, j, ' ', len);
  if (res < 0) {
    str[*j] = '-';
    (*j)++;
  }
  pcopy_str(str, j, copy);
  (*len)++;
}

int pread_f(char* str, int* j, long double res) {
  char copy[256];
  int len, p = 0, k = len_int((int)res), sign = 1;
  if (res < 0) sign = -1;
  if (specifiers.spec == 'f') {
    len = copy_f(copy, res);
    while (specifiers.acc - (len - k - 1) > 0) {
      copy[len] = '0';
      ++len;
    }
    copy[len] = '\0';
  } else if ((specifiers.spec == 'E') || (specifiers.spec == 'e')) {
    len = pread_e(copy, &p, res);
  } else {
    len = pread_e(copy, &p, res);
    if (!(p < -4 || p >= specifiers.acc)) {
      len = copy_f(copy, res);
      len--;
      while (specifiers.acc - (len + 1) > 0) {
        copy[len] = '0';
        ++len;
      }
      copy[len] = '\0';
    }
  }
  if (specifiers.flag == '+')
    flag_read_plus_space(str, j, copy, sign, &len, 0);
  else if (specifiers.flag == '-')
    flag_read_minus_int(str, j, copy, sign, &len);
  else if (specifiers.flag == ' ')
    flag_read_plus_space(str, j, copy, sign, &len, 1);
  else if (specifiers.flag == '#')
    flag_read_spec_float(str, j, copy, sign, &len);
  else if ((specifiers.acc <= 6) && (specifiers.flag == '0'))
    flag_read_zero_int(str, j, copy, sign, &len);
  else
    flag_read_int(str, j, copy, sign, &len);
  return len - 1;
}

int pread_s(char* str, int* j, va_list* string) {
  char copy[256];
  int i = 0;
  if (specifiers.length == 'l') {
    wchar_t* ch = va_arg(*string, wchar_t*);
    if (specifiers.acc != -1) {
      for (i = 0; *(ch + i) != '\0' && i < specifiers.acc; ++i) copy[i] = ch[i];
      copy[i] = '\0';
    } else {
      for (i = 0; *(ch + i) != '\0'; ++i) copy[i] = ch[i];
      copy[i] = '\0';
    }
  } else if (specifiers.length == 'e') {
    char* ch = va_arg(*string, char*);
    if (specifiers.acc != -1) {
      for (i = 0; *(ch + i) != '\0' && i < specifiers.acc; ++i) copy[i] = ch[i];
      copy[i] = '\0';
    } else {
      for (i = 0; *(ch + i) != '\0'; ++i) copy[i] = ch[i];
      copy[i] = '\0';
    }
  }
  if (specifiers.flag == '-') {
    flag_read_minus(str, j, copy, &i);
  } else if (specifiers.flag == '0') {
    flag_read_zero(str, j, copy, &i);
  } else {
    flag_read(str, j, ' ', &i);
    pcopy_str(str, j, copy);
  }
  return i;
}

int pwrite_int(char* str, int* j, va_list* string) {
  int res = 0;
  long d_str = 0;
  if (specifiers.length == 'e') {
    int result = va_arg(*string, int);
    d_str = result;
  } else if (specifiers.length == 'l') {
    long result = (long)va_arg(*string, int);
    d_str = result;
  } else if (specifiers.length == 'h') {
    short result = (short)va_arg(*string, int);
    d_str = result;
  }
  if (specifiers.spec == 'd')
    res = pread_d(str, j, d_str);
  else
    res = pread_i(str, j, d_str);
  return res;
}

int pwrite_int_unsign(char* str, int* j, va_list* string) {
  int res = 0;
  long d_str = 0;
  if (specifiers.length == 'e') {
    unsigned int result = (unsigned int)va_arg(*string, int);
    d_str = result;
  } else if (specifiers.length == 'l') {
    unsigned long result = (unsigned long)va_arg(*string, int);
    d_str = result;
  } else if (specifiers.length == 'h') {
    unsigned short result = (unsigned short)va_arg(*string, int);
    d_str = result;
  }
  if ((specifiers.spec == 'X') || (specifiers.spec == 'x'))
    res = pread_x_o(str, j, d_str, 16);
  else if (specifiers.spec == 'o')
    res = pread_x_o(str, j, d_str, 8);
  else
    res = pread_x_o(str, j, d_str, 10);
  return res;
}

int pwrite_float(char* str, int* j, va_list* string) {
  long double d_str = 0.0;
  long double result = (long double)va_arg(*string, double);
  d_str = result;
  return pread_f(str, j, d_str);
}

int read_sprintf(char* str, int* j, va_list* string, int counter) {
  int r = 0;
  if (specifiers.spec == 'c')
    r = pread_c(str, j, string);
  else if ((specifiers.spec == 'd') || (specifiers.spec == 'i'))
    r = pwrite_int(str, j, string);
  else if ((specifiers.spec == 'f') || (specifiers.spec == 'g') ||
           (specifiers.spec == 'G') || (specifiers.spec == 'e') ||
           (specifiers.spec == 'E'))
    r = pwrite_float(str, j, string);
  else if (specifiers.spec == 's')
    r = pread_s(str, j, string);
  else if ((specifiers.spec == 'x') || (specifiers.spec == 'X') ||
           (specifiers.spec == 'o') || (specifiers.spec == 'u'))
    r = pwrite_int_unsign(str, j, string);
  else if (specifiers.spec == 'n')
    pread_n(str, j, counter);
  else if (specifiers.spec == '%')
    r = pread_c_pr(str, j);
  return r;
}

void pread_n(char* str, int* j, int count) {
  char copy[256];
  int len = len_int(count);
  pcopy_int(copy, count);
  flag_read_int(str, j, copy, count, &len);
}

int s21_sprintf(char *str, const char *format, ...) {
    va_list string;
    int counte = 0;
    int j = 0;
    va_start(string, format);
    for (int i = 0; *(format + i) != '\0'; ++i) {
    if (*(format + i) == '%') {
        pfill((char*)(format), &string, &i);
        counte += read_sprintf(str, &j, &string, counte);
    }
    }
    va_end(string);
    return counte;
}

// int main(void) {
//     char c[20];
//     int s = -789;
//     int s1 = 11101;
//     // char strin[5];
//     // int st = '6';
//     // char r[100];
//     // double st_e = 9.765625e-05;
//     // float st_g = 1.111111;
//     // int st_o = 01234;
//     // char res[100];
//     // char st_s[10] = "qwey";
//     // unsigned int st_u = 1234;
//     // int st_x = 0x1234;
//     s21_sprintf(c, "sa\ndas%ddsas\nda", s);
//     printf("%s\n", c);
//     sprintf(c, "wqeqw\ne%dsa\nd", s1);
//     printf("%s\n", c);
//     // sprintf(c, "%d\n", s);
//     // printf("%d \n", sum(3, 1, 2, 3, 4));
//     // printf("%d \n", sum(6, 12, 21, 13, 4, 5));
//     return 0;
// }
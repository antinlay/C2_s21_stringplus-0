#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "s21_string.h"

struct s_sprintf {
  va_list args;  //  argument dlya zapisi
  int wdt;       //  shirina
  int prc;       //  tochnost'
  int hash;
  int zero;   //  00123.1
  int pnt;    //  . tochka
  int pol;    //  polyarnost'
  int len;    //  poluchennaya dlina stroki
  int sign;   //  (+ ili -) polozhitel'noe ili otricatel'noe
  int perc;   // % procent
  int align;  // ' ' flag align
  int spec;   // specificator (d, c, s, i)
} p;

// void s21_zero(char str[40], char format[40], char buf[40], int j, int i);
int s21_swrite(char str[40], char buf[40], int j);
int s21_atoi(const char *buf, int i);
// int s21_valist(char buf[40]);
// void p_flag(char input_char);
// void parser(char *str, const char *format);
int s21_sprintff(char *str, const char *format, ...);
void s21_ftoa(char buf_p[1000], long double num);
void s21_struct_init();

int main(void) {
  char str0[1000];
  char str1[1000];
  int num0 = 19;
  int num1 = -149;
  s21_size_t unum0 = 22;
  double fnum0 = 19.11132;
  double fnum1 = 0.000006125361;
  char test = 'W';
  char s[30] = "WAGA669*))";
  char format[1000] =
      // "CHAR %c__\tD_INT: %d__\tI_INT: %i__\tSTR0: "
      // "%s__\t SIZE_T: %u__ "
      // "%%__[] "
      // "%d__"
      "FLOAT: %5.f";
  // \tEXP_e: %g__\tEXP_E: %E__\tg_exp: "
  // "%g__\tG_EXP: %G__";
  s21_sprintff(str0, format, fnum0);
  // , num1, s, unum0, num0, fnum0, fnum1,
  //  fnum1, fnum0, fnum0);
  sprintf(str1, format, fnum0);
  //  num0, num1, s, unum0, num0, fnum0, fnum1, fnum1,
  //         fnum0, fnum0);
  printf("\nSTR0: %s\nSTR1: %s\n", str0, str1);
  // s21_ftoa(str0, fnum0);
  // printf(
  //     "\nSTRUCT:\nwdt = %d\nprc = %d\nzero = %d\npnt = %d\nmin = %d\nlen = "
  //     "%d\nsign = %d\nperc = %d\nsp = %d\n",
  //     p.wdt, p.prc, p.zero, p.pnt, p.pol, p.len, p.sign, p.perc, p.align);
  return 0;
}

// int s21_align(char str[40], int j, int align) {
//     if (p.align == ' ' && p.sign == '+') {
//         align -= 1;
//         while (align--) {
//             str[j++] = 32;
//             // printf("str %s\np.align %d\n", str, sp);
//         }
//     } else if (p.align == ' ' && p.sign == '-') {
//         while (align--) {
//             str[j++] = 32;
//             // printf("str %s\np.align %d\n", str, sp);
//         }
//     }
//     return j;
// }

// void s21_zero(char str[40], char format[40], char buf[40], int j, int i) {
//     // IF '0'-----------------------------!!!!!!!
//     int align = 0, len = 0, digit = 0;
//     if (format[i] == '0' || (format[i] == '0' && p.sign != 0)) {
//         i += 1;
//         // int k = 0;
//         s21_valist(buf);
//         len = s21_strlen(buf);
//         digit = s21_atoi(format, i);
//         p.zero = digit - len;
//         align = digit - len;
//         printf("p.zero %d\nlen_d %d\ndigit %d\n", p.zero, len, digit);
//         while (align--) {
//             str[j++] = '0';
//             // printf("str %s\np.align %d\n", str, sp);
//         }
//         s21_swrite(str, buf, j, len);
//         j += digit;
//         i += 1;
//     }
// }

void s21_struct_init() {
  p.wdt = -1;
  p.zero = -1;
  p.spec = -1;
  p.sign = -1;
  p.prc = -1;
  p.pol = -1;
  p.pnt = -1;
  p.perc = -1;
  p.len = -1;
  p.hash = -1;
  p.align = -1;
}

int s21_swrite(char str[1000], char buf[1000], int i) {
  int k = 0;
  do {
    str[i] = buf[k];
    i++;
    k++;
  } while (buf[k] != '\0');
  return k;
}

int s21_atoi(const char *format, int i) {
  int digit = 0;
  for (; format[i] >= 0x30 && format[i] <= 0x39; i++) {
    digit = digit + (format[i] & 0x0F);
    digit *= BASE;
  }
  digit /= BASE;

  return digit;
}

void s21_ftoa(char buf_p[1000], long double num) {
  char *p_buf;
  if (p.prc == 0) p.prc = 6;
  int pow_num = 0, int_p = 0, i = 0, j = 0, dec = 0;
  int_p = (int)num;
  p_buf = fcvt(num, p.prc, &dec, &p.sign);

  if (dec <= 0) {
    if (p.sign == 1) {
      buf_p[i++] = '-';
      buf_p[i++] = '0';
      buf_p[i++] = '.';
    } else {
      buf_p[i++] = '0';
      buf_p[i++] = '.';
    }
    if (dec < 0) {
      do {
        buf_p[i++] = '0';
      } while (++dec);
    }
    while (p_buf[dec] != '\0') {
      buf_p[i++] = p_buf[dec++];
    }
  } else {
    if (p.sign == 1) {
      buf_p[i++] = '-';
    }
    do {
      buf_p[i++] = p_buf[j++];
    } while (--dec);
    buf_p[i] = '.';
    do {
      i += 1;
      buf_p[i] = p_buf[j];
    } while (p_buf[j++] != '\0');
  }
  buf_p[i] = '\0';
  p.prc = 0;
}

void s21_etoa(char buf_p[1000], long double num) {
  char *p_buf;
  char e_buf[1000];
  if (p.prc == -1) p.prc = 6;
  if (p.spec == 'E') p.prc = 7;
  int e = 0, int_p = 0, i = 0, j = 0, dec = 0;
  int_p = (int)num;
  p_buf = ecvt(num, p.prc, &dec, &p.sign);
  if (dec <= 0) {
    if (p.sign == 1) {
      buf_p[i++] = '-';
    }
    buf_p[i++] = p_buf[j++];
    buf_p[i++] = '.';
    while (p_buf[j] != '\0') {
      buf_p[i++] = p_buf[j++];
    }
    if ((dec - 1) <= -BASE) {
      buf_p[i++] = p.spec;
      dec = dec - 1;
      s21_itoa(dec, BASE, e_buf);
    } else {
      buf_p[i++] = p.spec;
      buf_p[i++] = '-';
      buf_p[i++] = '0';
      dec = -dec + 1;
      s21_itoa(dec, BASE, e_buf);
    }
    while (e_buf[e] != '\0') {
      buf_p[i++] = e_buf[e++];
    }

  } else {
    if (p.sign == 1) {
      buf_p[i++] = '-';
    }
    buf_p[i++] = p_buf[j++];
    buf_p[i++] = '.';
    // while (dec--) {
    //   buf_p[i++] = p_buf[j++];
    // }
    while (p_buf[j] != '\0') {
      buf_p[i++] = p_buf[j++];
    }
    if ((dec + 1) >= BASE) {
      buf_p[i++] = p.spec;
      buf_p[i++] = '+';
      dec = dec - 1;
      s21_itoa(dec, BASE, e_buf);
    } else {
      buf_p[i++] = p.spec;
      buf_p[i++] = '+';
      buf_p[i++] = '0';
      dec = dec - 1;
      s21_itoa(dec, BASE, e_buf);
    }
    while (e_buf[e] != '\0') {
      buf_p[i++] = e_buf[e++];
    }
  }
  buf_p[++i] = '\0';
  p.prc = 0;
}

void s21_gtoa(char buf_p[1000], long double num) {
  char *p_buf;
  char e_buf[1000];
  if (p.prc == 0) p.prc = 6;
  int spec = 0, e = 0, int_p = 0, i = 0, j = 0, dec = 0;
  if (p.spec == 'g')
    spec = 'e';
  else if (p.spec == 'G')
    spec = 'E';
  int_p = (int)num;
  p_buf = ecvt(num, p.prc, &dec, &p.sign);
  if (dec <= 0) {
    if (p.sign == 1) {
      buf_p[i++] = '-';
    }
    buf_p[i++] = p_buf[j++];
    buf_p[i++] = '.';
    while (p_buf[j] != '\0') {
      buf_p[i++] = p_buf[j++];
    }
    if ((dec - 1) <= -BASE) {
      buf_p[i++] = spec;
      dec = dec - 1;
      s21_itoa(dec, BASE, e_buf);
    } else {
      buf_p[i++] = spec;
      buf_p[i++] = '-';
      buf_p[i++] = '0';
      dec = -dec + 1;
      s21_itoa(dec, BASE, e_buf);
    }
    while (e_buf[e] != '\0') {
      buf_p[i++] = e_buf[e++];
    }

  } else {
    if (p.sign == 1) {
      buf_p[i++] = '-';
    }
    while (p_buf[j] != '\0') {
      buf_p[i++] = p_buf[j++];
    }
    if ((dec + 1) >= BASE) {
      buf_p[i++] = spec;
      buf_p[i++] = '+';
      dec = dec - 1;
      s21_itoa(dec, BASE, e_buf);
    } else {
      buf_p[i++] = spec;
      buf_p[i++] = '+';
      buf_p[i++] = '0';
      dec = dec - 1;
      s21_itoa(dec, BASE, e_buf);
    }
    while (dec--) {
      buf_p[i++] = e_buf[e++];
    }
  }
  buf_p[++i] = '\0';
  p.prc = 0;
}

int s21_fspec(char *buffer, int j) {
  char *slist = "cdeEfgGiopsSuxX\0";
  while (p.spec == -1 || buffer[j] == '%' || buffer[j] == '\0') {
    int m = 0;
    j++;
    while (slist[m] != '\0' && p.spec == -1) {
      if (buffer[j] == slist[m]) {
        p.spec = slist[m];
        break;
      }
      m++;
    }
  }
  printf("P.SPEC %c\n", p.spec);
  return p.spec != -1 ? j : 0;
}

int s21_flag(char *buffer, int j) {
  char *flist = ".#-+ ";
  while (buffer[j] != '%' && j > 0) {
    int m = 0;
    while (buffer[j] != '%' && buffer[j] != '\0' && m < 6) {
      if (buffer[j] == flist[m]) {
        if (m == 0) p.pnt = flist[m];
        if (m == 1) p.hash = flist[m];
        if (m == 2 || m == 3) p.pol = flist[m];
        if (m == 4) p.align = flist[m];
      }
      m++;
    }
    j--;
  }
  printf("P.PNT %d\tP.ZERO %d\tP.POL %d\tP.ALIGN %d\t", p.pnt, p.zero, p.pol,
         p.align);
  return j;
}
// bezhim ot % k spec (d)
int s21_wdt(char *buffer, int j) {
  int digit = 0;
  int m = j++;
  while (buffer[j] >= '0' && buffer[j] <= '9') {
    if (buffer[j] == '0' && (m - j) == 0) p.zero == '0';
    m++;
    digit += (buffer[j] & 0x0F);
    digit *= BASE;
    j++;
  }
  return digit /= BASE;
}

// // int s21_valist(char buf[40]) {
// //     int symb = va_arg(p.args, int);
// //     s21_itoa(symb, BASE, buf);
// //     // printf("VALIST %s\n", buf);
// //     return symb;
// // }

// void p_flag(char input_char) {
//     if (input_char == '.') p.pnt = 0;
//     if (input_char == 'd') p.spec += 'd';
//     if (input_char == 'c') p.spec += 'c';
//     if (input_char == 'i') p.spec += 'i';
//     if (input_char == 'f') p.spec += 'f';
//     if (input_char == 'u') p.spec += 'u';
//     if (input_char == 's') p.spec += 's';
//     if (input_char == '-') p.align = 0;
//     if (input_char == '+') p.sign = 0;
//     if (input_char == '%') p.perc = 0;
// }

// void parser(char *str, const char *format) {
// // struct s_printf *p;
// p.wdt = 0;
// p.prc = 0;
// p.zero = 0;
// p.pnt = 0;
// p.pol = 0;
// p.len = 0;
// p.sign = 0;
// p.perc = 0;
// p.align = 0;
// int i = 0, j = 0, symb = 0, digit = 0, align = 0, len_d = 0;
// char buf[40];
// // symb = va_arg(p.args, int);
// // s21_itoa(symb, BASE, buf);
// // len_d = strlen(buf);
// while (format[i] != '\0') {
//     if (format[i] == '%') {
//         // if (*format++ == '%' || *format++ == 'c' || *++format == 'd'
//         ||
//         //     *++format == 'i' || *++format == 'f' || *++format == 's'
//         ||
//         //     *++format == 'u' || *++format == '-' || *++format == '.'
//         ||
//         //     *++format == ' ' || *++format == 'h' || *++format == 'l')
//         { if (format[i + 1] == 'c') {
//             symb = va_arg(p.args, int);
//             str[j] = symb;
//             i++;
//             j++;
//         }
//         if (format[i + 1] == 'd') {
//             p.spec = 'd';
//             s21_valist(buf);
//             len_d = s21_strlen(buf);
//             j += s21_swrite(str, buf, j, len_d);
//             i += 1;
//             printf("HUY %s\nlen_d %d\n j = %d\n", buf, len_d, j);
//         }
//         if (format[i + 1] == '0' || (format[i + 1] == '0' && p.sign !=
//         0)) {
//             // i++;
//             //  INTERGER TO ASCII AND GET ARGUMENT
//             symb = s21_valist(buf);
//             //  GET LENGHT ARGUMENT
//             len_d = s21_strlen(buf);
//             //  ASCII TO INTEGER
//             digit = s21_atoi(buf, i);
//             //
//             align = digit - len_d;
//             //  IF LENGHT BUF > DIGIT
//             if (align <= 0) {
//                 p.zero = 0;
//                 align = len_d;
//                 s21_swrite(str, buf, j, len_d);
//             } else {
//                 p.zero = 1;
//                 s21_align(str, j, align);
//                 s21_swrite(str, buf, j, len_d);
//             }
//             printf("p.zero %d\nlen_d %d\ndigit %d\n", p.zero, len_d,
//             digit);
//             // while (align--) {
//             //     str[j++] = '0';
//             printf("buf %s\nalign %d\n", buf, align);
//             // }

//             j += digit;
//             i += 1;
//         }
//         // if (*++format = 'i') {
//         //     *str++ = va_arg(p.args, float);
//         // }
//         // if (*++format = 'f') {
//         //     *str++ = va_arg(p.args, float);
//         // }
//         // if (*++format = 's') {
//         //     *str++ = va_arg(p.args, char *);
//         // }
//         // if (*++format = 'u') {
//         //     *str++ = va_arg(p.args, float);
//         // }
//         // CHECK '-' and FLAG '+'
//         if (format[i + 1] == '-' || format[i + 1] == '+') {
//             i += 1;
//             // IF '0'-----------------------------!!!!!!!
//             if (format[i] == '0' || (format[i] == '0' && p.sign != 0)) {
//                 // i += 1;
//                 //  INTERGER TO ASCII AND GET ARGUMENT
//                 symb = s21_valist(buf);
//                 //  GET LENGHT BUF
//                 len_d = s21_strlen(buf);
//                 //  ASCII TO INTEGER GET INTEGER
//                 digit = s21_atoi(format, ++i);
//                 //  IF LENGHT BUF > DIGIT
//                 if ((digit - len_d) <= 0) {
//                     p.zero = 0;
//                     // i += 1;
//                 } else {
//                     align = digit - len_d;
//                     p.zero = 1;
//                 }
//                 printf("p.zero %d\nlen_d %d\ndigit %d\n", p.zero, len_d,
//                        digit);
//                 while (align--) {
//                     str[j++] = '0';
//                     // printf("str %s\np.align %d\n", str, sp);
//                 }
//                 s21_swrite(str, buf, j, len_d);
//                 // j += digit;
//                 // i += 1;
//             }
//             // IF '+'
//             if (format[i] == '+') {
//                 p.sign = '+';
//                 i += 1;
//                 while (format[i] == '+' || format[i] == '-') {
//                     p_flag(format[i]);
//                     i += 1;
//                 }
//                 digit = s21_atoi(format, i);
//                 if (digit != 0 && digit > len_d) {
//                     p.align = ' ';
//                     i += 1;
//                 } else {
//                     p.align = 0;
//                     p.zero = 0;
//                 }
//                 printf("digit after %d\n i = %d\n", digit, i);
//                 //  + FIND SPEC 'd'
//                 if (format[i] == 'd' && p.align == 0) {
//                     p.spec = 'd';
//                     symb = s21_valist(buf);
//                     len_d = s21_strlen(buf);
//                     if (symb > 0) {
//                         str[j] = '+';
//                         j++;
//                     }
//                     printf("BUF %s\n", buf);
//                     j += s21_swrite(str, buf, j, len_d);
//                     // j+=1;
//                     // i+=1;
//                     printf("STR %s\nj = %d\ni = %d\n", str, j, i);
//                 }
//                 //  + FIND SPEC 'd' WITH SPACE
//                 if (format[i] == 'd' && p.align == ' ') {
//                     p.spec = 'd';
//                     symb = s21_valist(buf);
//                     len_d = s21_strlen(buf);
//                     align = digit - len_d;
//                     printf("str0 %s\nalign0 %d\n", str, align);
//                     j = s21_align(str, j, align);
//                     printf("str1 %s\nalign1 %d\nj = %d\n", str, align,
//                     j);
//                     // }
//                     if (symb > 0) {
//                         str[j] = '+';
//                         j++;
//                     }
//                     j += s21_swrite(str, buf, j, len_d);
//                     // i+=1;
//                 }
//             }
//             // IF '-'
//             if (format[i] == '-') {
//                 p.sign = '-';
//                 i += 1;
//                 // NOT INCLUDE ADDITINAL '-' or '+'
//                 while (format[i] == '-' || format[i] == '+') {
//                     // p_flag(format[i]);
//                     i += 1;
//                 }
//                 // ATOI
//                 // printf("ATOI i = %d\n BUF = %s\n", i, buf);
//                 digit = s21_atoi(format, i);
//                 // printf("LATOI i = %d\n LBUF = %s\n", i, buf);
//                 if (digit > 0) {
//                     p.align = ' ';
//                     i += 1;
//                 } else {
//                     p.align = 0;
//                     p.zero = 0;
//                 }
//                 // printf
//                 //  - FIND SPEC 'd'
//                 if (format[i] == 'd' && p.align == 0) {
//                     p.spec = 'd';
//                     printf("buf sp %s\nlen_d %d\n", buf, len_d);
//                     s21_valist(buf);
//                     j += s21_swrite(str, buf, j, len_d);
//                     // i += 1;
//                 }

//                 //  - FIND SPEC 'd' WITH SPACE
//                 if (format[i] == 'd' && p.align == ' ') {
//                     p.spec = 'd';
//                     s21_valist(buf);
//                     len_d = s21_strlen(buf);
//                     align = digit - len_d;
//                     // printf("buf sp %s\nlen_d %d\n", buf, len_d);
//                     j += s21_swrite(str, buf, j, len_d);
//                     j = s21_align(str, j, align);
//                 }
//             }
//         }
//     } else {
//         str[j] = format[i];
//         j++;
//     }
//     i++;
// }
// // str[j] = '\0';
// }

int s21_sprintff(char *str, const char *format, ...) {
  char buffer[10000];
  char sbuf[100];
  char dbuf[1000];
  char fbuf[1000];
  char ebuf[100];
  char Ebuf[100];
  char *bufs;
  s21_size_t uspec = 0;
  double fspec = 0.0;
  double espec = 0.0;
  double Espec = 0.0;
  int spec = 0, i = 0, j = 0, m = 0, digit = 0;
  s21_struct_init();
  va_start(p.args, format);
  int len = 0, len_s = 0, len_f = 0, len_e = 0;
  do {
    buffer[len] = *format;
    len++;
  } while (*format++ != '\0');
  buffer[len] = '\0';
  while (buffer[j]) {
    while (buffer[j] != '%') {
      sbuf[i++] = buffer[j++];
      if (buffer[j] == '\0') break;
    }
    j = s21_fspec(buffer, j);
    s21_flag(buffer, j);
    p.wdt = s21_wdt(buffer, j);
    switch (buffer[j++]) {
      case 'c':
        p.spec = 'c';
        spec = va_arg(p.args, int);
        sbuf[i++] = spec;
        j += 1;
        break;
      case 'd':
        p.spec = 'd';
        spec = va_arg(p.args, int);
        s21_itoa(spec, BASE, dbuf);
        i += s21_swrite(sbuf, dbuf, i);
        j += 1;
        break;
      case 'i':
        p.spec = 'i';
        spec = va_arg(p.args, int);
        s21_itoa(spec, BASE, dbuf);
        i += s21_swrite(sbuf, dbuf, i);
        j += 1;
        break;
      case 'u':
        p.spec = 'u';
        uspec = va_arg(p.args, s21_size_t);
        s21_itoa(uspec, BASE, dbuf);
        i += s21_swrite(sbuf, dbuf, i);
        j += 1;
        break;
      case 's':
        p.spec = 's';
        bufs = va_arg(p.args, char *);
        len_s = s21_swrite(sbuf, bufs, i);
        i += len_s;
        j += 1;
        break;
      case '%':
        p.spec = '%';
        sbuf[i++] = p.spec;
        j += 1;
        break;
      case 'e':
        p.spec = 'e';
        espec = va_arg(p.args, double);
        s21_etoa(ebuf, espec);
        len_e = s21_swrite(sbuf, ebuf, i);
        i += len_e;
        j += 1;
        break;
      case 'E':
        p.spec = 'E';
        Espec = va_arg(p.args, double);
        s21_etoa(Ebuf, Espec);
        len_e = s21_swrite(sbuf, Ebuf, i);
        i += len_e;
        j += 1;
        break;
      case 'f':
        p.spec = 'f';
        fspec = va_arg(p.args, double);
        s21_ftoa(fbuf, fspec);
        len_f = s21_swrite(sbuf, fbuf, i);
        i += len_f;
        j += 1;
        break;
      case 'g':
        p.spec = 'g';
        espec = va_arg(p.args, double);
        s21_gtoa(ebuf, espec);
        len_e = s21_swrite(sbuf, ebuf, i);
        i += len_e;
        j += 1;
        break;
      case 'G':
        p.spec = 'G';
        Espec = va_arg(p.args, double);
        s21_gtoa(Ebuf, Espec);
        len_e = s21_swrite(sbuf, Ebuf, i);
        i += len_e;
        j += 1;
        break;
      // case '-':

      //   break;
      default:
        sbuf[i++] = buffer[j++];
        break;
    }
  }
  // sbuf[i] = '\0';
  for (int m = 0; sbuf[m] != '\0'; m++) {
    *str++ = sbuf[m];
  }
  *str = '\0';
  va_end(p.args);
  return 0;
}

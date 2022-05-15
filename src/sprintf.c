#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_string.h"

#define BSIZE 1000000

struct s_sprintf {
  va_list args;  //  argument dlya zapisi
  int wdt;       //  shirina
  int prc;       //  tochnost'
  int hash;
  int zero;   //  00123.1
  int pnt;    //  . tochka
  int pol;    //  polyarnost'
  int dec;    //  poluchennaya dlina int_p
  int sign;   //  (+ ili -) polozhitel'noe ili otricatel'noe
  int perc;   // % procent
  int align;  // ' ' flag align
  int spec;   // specificator (d, c, s, i)
  int digit;  // polozhenie digit
} p;

// void s21_zero(char str[40], char format[40], char buf[40], int j, int i);
s21_size_t s21_swrite(char str[BSIZE], char buf[BSIZE], int i);
int s21_atoi(const char *buf, int i);
// int s21_valist(char buf[40]);
// void p_flag(char input_char);
// void parser(char *str, const char *format);
int s21_sprintff(char *str, const char *format, ...);
void s21_ftoa(char buf_p[BSIZE], long double num);
void s21_struct_init();

int main(void) {
  char str0[1000] = "";
  char str1[1000] = "";
  int num0 = 19;
  int num1 = -149;
  s21_size_t unum0 = 22;
  double fnum0 = 0.0016516;
  double fnum1 = -.06125361;
  char test = 'W';
  char s[30] = "WAGA669*))";
  char format[500] =
      // "CHAR %c__\tD_INT: %d__\tI_INT: %i__\tSTR0: %s__\t SIZE_T: %u__ %%__[]
      // "
      "%d__FLOAT: %9.4f RAS %d DVA %4.2f QQ";
  // \tEXP_e: %g__\tEXP_E: %E__\tg_exp: "
  // "%g__\tG_EXP: %G__";
  s21_sprintff(str0, format, num0, fnum0, num1, fnum1);
  // , num1, s, unum0, num0, fnum0, fnum1,
  //  fnum1, fnum0, fnum0);
  sprintf(str1, format, num0, fnum0, num1, fnum1);
  //  num0, num1, s, unum0, num0, fnum0, fnum1, fnum1,
  //         fnum0, fnum0);
  printf("\nSTR0: %s\nSTR1: %s\n", str0, str1);
  // s21_ftoa(str0, fnum0);
  // printf(
  //     "\nSTRUCT:\nwdt = %d\nprc = %d\nzero = %d\npnt = %d\nmin = %d\nlen = "
  //     "%d\nsign = %d\nperc = %d\nalign = %d\n",
  //     p.wdt, p.prc, p.zero, p.pnt, p.pol, p.dec, p.sign, p.perc, p.align);
  return 0;
}

void s21_struct_init() {
  p.wdt = -1;
  p.zero = -1;
  p.spec = -1;
  p.sign = -1;
  p.prc = -1;
  p.pol = -1;
  p.pnt = -1;
  p.perc = -1;
  p.dec = -1;
  p.hash = -1;
  p.align = -1;
  p.digit = -1;
}

s21_size_t s21_swrite(char str[BSIZE], char buf[BSIZE], int i) {
  int k = 0;
  do {
    str[i] = buf[k];
    i++;
    k++;
  } while (buf[k] != '\0');
  str[i] = '\0';
  return k;
}

void s21_count_align(int num, int count) {
  if (p.pnt == -1) {
    if (p.prc <= 0) {
      p.prc = 6;
      if (p.align <= 0) {
        p.align = 0;
      }
    }
    if (p.wdt <= 0) {
      p.prc = 6;
      p.align = 0;
    } else
      p.align = p.wdt;
  } else {
    // if (num < 0 || p.pol > 0) {
    p.align = p.wdt;
    if (p.prc <= 0) {
      p.prc = 0;
      if (p.align <= 0) {
        p.align = 0;
      }
    }
  }
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

int s21_int_count(int num) {
  int dec = 0, int_p = (int)num;
  while (int_p) {
    dec++;
    int_p /= BASE;
  }
  return dec;
}

void s21_symb_align(char *buf_p, int num) {
  char a_buf[1000] = "";
  s21_size_t len_buf = s21_strlen(buf_p);
  if (p.align > len_buf) {
    s21_size_t symb = ' ';
    if (p.zero > 0) symb = '0';
    s21_memset(a_buf, symb, p.align - len_buf);
    s21_strcat(a_buf, buf_p);
    s21_strcpy(buf_p, a_buf);
  }
}

char *s21_sel_cvt(int num, int prc, int *dec, int *sign) {
  if (p.prc == 0 && p.pnt > -1) {
    ecvt(num, prc, dec, sign);
  }
}

void s21_add_sign(char *buf_p, int sign) {
  if (sign == 1) {
    s21_strcat(buf_p, "-");
    // p.sign = 1;
  }
  if (sign == 0 && p.pol == '+') s21_strcat(buf_p, "+");
}

void s21_pnt_num(char *buf_p, int num) {
  if (num == 0) {
    if (p.prc <= 0) {
      s21_strcat(buf_p, "0");
      // buf_p[i++] = '0';
    } else {
      s21_strcat(buf_p, "0.");
      // buf_p[i++] = '0';
      // buf_p[i++] = '.';
    }
  }
}

void s21_wrt_int(char *buf_p, char *p_buf) {
  s21_size_t dec = abs(p.dec);
  s21_strncat(buf_p, p_buf, dec);
}

void s21_wrt_zero(char *buf_p, int dec) {
  s21_size_t leb_buf = s21_strlen(buf_p);
  do {
    buf_p[leb_buf++] = '0';
  } while (++dec);
}

void s21_wrt_num(char *buf_p, char *p_buf) {
  s21_size_t i = s21_strlen(buf_p);
  s21_size_t k = 1, m = 1;
  if (p.sign == 0) m = 0;
  s21_strcat(buf_p, ".");
  // s21_strcat(buf_p, p_buf);
  do {
    // i += 1;
    buf_p[i + k] = p_buf[i - m];
  } while (p_buf[i++] != '\0');
}

void s21_ftoa(char buf_p[BSIZE], long double num) {
  char *p_buf;
  int pow_num = 0, count = 0, i = 0, j = 0, dec = 0;
  count = s21_int_count(num);
  s21_count_align((int)num, count);
  p.dec = count;
  if (p.prc == 0)
    p_buf = ecvt(num, p.dec, &dec, &p.sign);
  else
    p_buf = fcvt(num, p.prc, &dec, &p.sign);
  if (dec <= 0) {
    s21_add_sign(buf_p, p.sign);
    s21_pnt_num(buf_p, (int)num);
    if (dec < 0) {
      s21_wrt_zero(buf_p, dec);
      // dec = 0;
    }
    s21_strcat(buf_p, p_buf);
    // while (p_buf[dec] != '\0') {
    //   buf_p[i++] = p_buf[dec++];
    // }
  } else {
    printf("\n__I %d", i);
    s21_add_sign(buf_p, p.sign);
    s21_wrt_int(buf_p, p_buf);
    // if (p.pnt > 0 && p.prc > 0) {
    s21_wrt_num(buf_p, p_buf);
    // }
  }
  s21_symb_align(buf_p, (int)num);
}

void s21_etoa(char buf_p[BSIZE], long double num) {
  char *p_buf;
  char e_buf[BSIZE] = "";
  int e = 0, i = 0, j = 0, dec = 0;
  if (p.prc == -1) p.prc = 6;
  if (p.spec == 'E') p.prc = 7;
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

void s21_gtoa(char buf_p[BSIZE], long double num) {
  char *p_buf;
  char e_buf[] = "";
  int spec = 0, e = 0, i = 0, j = 0, dec = 0;
  if (p.prc == 0) p.prc = 6;
  if (p.spec == 'g')
    spec = 'e';
  else if (p.spec == 'G')
    spec = 'E';
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
    while (buffer[j] != '%' && buffer[j] != '\0' && m < 5) {
      if (buffer[j] == flist[m]) {
        if (m == 0) p.pnt = j;
        if (m == 1) p.hash = j;
        if (m == 2 || m == 3) p.pol = flist[m];
        if (m == 4) p.align = j;
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
  while (buffer[j] >= '0' && buffer[j] <= '9' && buffer[j] != '.') {
    digit += (buffer[j] & 0x0F);
    digit *= BASE;
    j++;
  }
  // p.digit = j;
  digit /= BASE;
  return digit;
}

int s21_prc(char *buffer, int j) {
  int digit = 0;
  if (p.pnt != -1) {
    j = p.pnt + 1;
    while (buffer[j] >= '0' && buffer[j] <= '9') {
      digit += (buffer[j] & 0x0F);
      digit *= BASE;
      j++;
    }
    digit /= BASE;
  }
  // p.digit = j;
  return digit;
}

void s21_case_f(char *sbuffer, char *fbuf) {
  double fspec = 0.0;
  p.spec = 'f';
  fspec = va_arg(p.args, double);
  s21_ftoa(fbuf, fspec);
  s21_struct_init();
}

int s21_sprintff(char *str, const char *format, ...) {
  char buffer[BSIZE] = "";
  char sbuffer[BSIZE] = "";
  char dbuf[BSIZE] = "";
  char ebuf[BSIZE] = "";
  char Ebuf[BSIZE] = "";
  char *bufs;
  s21_size_t uspec = 0;
  double fspec = 0.0;
  double espec = 0.0;
  double Espec = 0.0;
  int spec = 0, i = 0, j = 0, m = 0, digit = 0;
  s21_struct_init();
  va_start(p.args, format);
  int len = 0, len_s = 0, len_f = 0, len_e = 0;
  int j_spec = 0, j_flag = 0, wdt = 0, prc = 0;
  s21_strcpy(buffer, format);
  printf("BUFFER %s\n", buffer);
  while (buffer[j] != '\0') {
    while (buffer[j] != '%') {
      sbuffer[i++] = buffer[j++];
      if (buffer[j] == '\0') break;
    }
    if (buffer[j] == '\0') break;
    j_spec = s21_fspec(buffer, j);

    if (j_spec <= 0)
      ;
    else
      j = j_spec;

    j_flag = s21_flag(buffer, j);
    // if (p.pnt >= 0) {
    j = j_flag + 1;
    wdt = s21_wdt(buffer, j);
    prc = s21_prc(buffer, j);
    // }
    // if (p.pnt != -1) {
    p.wdt = wdt;
    p.prc = prc;
    // }
    j = j_spec;
    // }
    char fbuf[BSIZE] = "";
    switch (buffer[j++]) {
      case 'c':
        p.spec = 'c';
        spec = va_arg(p.args, int);
        sbuffer[i++] = spec;
        j += 1;
        s21_struct_init();
        break;
      case 'd':
        p.spec = 'd';
        spec = va_arg(p.args, int);
        s21_itoa(spec, BASE, dbuf);
        i += s21_strlen(dbuf);
        s21_strcat(sbuffer, dbuf);
        s21_struct_init();
        break;
      case 'i':
        p.spec = 'i';
        spec = va_arg(p.args, int);
        s21_itoa(spec, BASE, dbuf);
        i += s21_strlen(dbuf);
        s21_strcat(sbuffer, dbuf);
        s21_struct_init();
        break;
      case 'u':
        p.spec = 'u';
        uspec = va_arg(p.args, s21_size_t);
        s21_itoa(uspec, BASE, dbuf);
        i += s21_strlen(dbuf);
        s21_strcat(sbuffer, dbuf);
        s21_struct_init();
        break;
      case 's':
        p.spec = 's';
        bufs = va_arg(p.args, char *);
        len_s = s21_swrite(sbuffer, bufs, i);
        i += len_s;
        j += 1;
        s21_struct_init();
        break;
      case '%':
        p.spec = '%';
        sbuffer[i++] = p.spec;
        j += 1;
        s21_struct_init();
        break;
      case 'e':
        p.spec = 'e';
        espec = va_arg(p.args, double);
        s21_etoa(ebuf, espec);
        len_e = s21_swrite(sbuffer, ebuf, i);
        i += len_e;
        j += 1;
        s21_struct_init();
        break;
      case 'E':
        p.spec = 'E';
        Espec = va_arg(p.args, double);
        s21_etoa(Ebuf, Espec);
        len_e = s21_swrite(sbuffer, Ebuf, i);
        i += len_e;
        j += 1;
        s21_struct_init();
        break;
      case 'f':
        s21_case_f(sbuffer, fbuf);
        s21_strcat(sbuffer, fbuf);
        len_f = s21_strlen(sbuffer);
        i = len_f;
        break;
      case 'g':
        p.spec = 'g';
        espec = va_arg(p.args, double);
        s21_gtoa(ebuf, espec);
        len_e = s21_swrite(sbuffer, ebuf, i);
        i += len_e;
        j += 1;
        s21_struct_init();
        break;
      case 'G':
        p.spec = 'G';
        Espec = va_arg(p.args, double);
        s21_gtoa(Ebuf, Espec);
        len_e = s21_swrite(sbuffer, Ebuf, i);
        i += len_e;
        j += 1;
        s21_struct_init();
        break;
      // case '-':

      //   break;
      default:
        sbuffer[i++] = buffer[j++];
        break;
    }
  }
  sbuffer[i] = '\0';
  // str = malloc(s21_strlen(sbuffer) + 100);
  s21_strcpy(str, sbuffer);
  va_end(p.args);
  return 0;
}

#include <stdarg.h>
#include <stdio.h>
#include <string.h>

#include "s21_string.h"

struct s_sprintf {
    va_list args;  //  argument dlya zapisi
    int wdt;       //  shirina
    int prc;       //  tochnost'
    int zero;      //  00123.1
    int pnt;       //  . tochka
    int min;       //  - minus
    int len;       //  poluchennaya dlina stroki
    int sign;      //  (+ ili -) polozhitel'noe ili otricatel'noe
    int perc;      // % procent
    int space;        // ' ' flag probela
    char spec;     // specificator (d, c, s, i)
} p;

int s21_atoi(char *ibuf, int i) {
    int digit = 0;
    for (; ibuf[i] >= 0x30 && ibuf[i] <= 0x39; i++) {
        digit = digit + (ibuf[i] & 0x0F);
        digit *= BASE;
    }
    digit /= BASE;
    return digit;
}

// void sign_itoa(int symb, char *str) {
//     char buf[50] = "";
//     int j = 0;
//     s21_size_t k = 0;
//     symb = va_arg(p.args, int);
//     s21_itoa(symb, BASE, buf);
//     // printf("%d\n", (int*)buf);
//     if (symb > 0) {
//         str[j] = '+';
//         j++;
//     }
//     do {
//         str[j] = buf[k];
//         j++;
//         k++;
//     } while (k < s21_strlen(buf));
// }

void p_flag(char input_char) {
    if (input_char != '.') p.pnt = 0;
    if (input_char != 'd') p.spec += 'd';
    if (input_char != 'c') p.spec += 'c';
    if (input_char != 'i') p.spec += 'i';
    if (input_char != 'f') p.spec += 'f';
    if (input_char != 'u') p.spec += 'u';
    if (input_char != 's') p.spec += 's';
    if (input_char != '-') p.space = 0;
    if (input_char != '+') p.sign = 0;
    if (input_char != '%') p.perc = 0;
}

void parser(char *str, const char *format) {
    // struct s_printf *p;
    p.wdt = 0;
    p.prc = 0;
    p.zero = 0;
    p.pnt = 0;
    p.min = 0;
    p.len = 0;
    p.sign = 0;
    p.perc = 0;
    p.space = 0;
    int i = 0, j = 0, symb = 0, digit = 0, tmp = 0, sp = 0;
    char buf[40];
    while (format[i] != '\0') {
        if (format[i] == '%') {
            // if (*format++ == '%' || *format++ == 'c' || *++format == 'd' ||
            //     *++format == 'i' || *++format == 'f' || *++format == 's' ||
            //     *++format == 'u' || *++format == '-' || *++format == '.' ||
            //     *++format == ' ' || *++format == 'h' || *++format == 'l') {
            if (format[i + 1] == 'c') {
                symb = va_arg(p.args, int);
                str[j] = symb;
                i++;
                j++;
            }
            if (format[i + 1] == 'd') {
                s21_size_t k = 0;
                symb = va_arg(p.args, int);
                s21_itoa(symb, BASE, buf);
                // printf("%d\n", (int*)buf);
                do {
                    str[j] = buf[k];
                    j++;
                    k++;
                } while (k < s21_strlen(buf));
                i++;
            }
            if (format[i + 1] == '+' && p.min != '-') {
                p.sign = '+';
                i++;
                while (format[i] == '+' || format[i] == '-') {
                    p_flag(format[i]);
                    i += 1;
                }
                if (format[i] == 'd') {
                    s21_size_t k = 0;
                    symb = va_arg(p.args, int);
                    // sign_itoa(symb, str);
                    s21_itoa(symb, BASE, buf);
                    // printf("%d\n", (int*)buf);
                    if (symb > 0) {
                        str[j] = '+';
                        j++;
                    }
                    do {
                        str[j] = buf[k];
                        j++;
                        k++;
                    } while (k < s21_strlen(buf));
                }
            }
            // if (*++format = 'i') {
            //     *str++ = va_arg(p.args, float);
            // }
            // if (*++format = 'f') {
            //     *str++ = va_arg(p.args, float);
            // }
            // if (*++format = 's') {
            //     *str++ = va_arg(p.args, char *);
            // }
            // if (*++format = 'u') {
            //     *str++ = va_arg(p.args, float);
            // }
            // CHECK '-' and FLAG '+'
            if (format[i + 1] == '-' && p.sign != '+') {
                p.min = '-';
                i++;
                // NOT INCLUDE ADDITINAL '-' or '+'
                while (format[i] == '-') {
                    p_flag(format[i]);
                    i += 1;
                }
                // ATOI
                for (; format[i] >= 0x30 && format[i] <= 0x39;) {
                    digit = digit + (format[i] & 0x0F);
                    digit *= BASE;
                    printf("%c\n%d\n", format[i], digit);
                    i += 1;
                }
                digit /= BASE;
                // tmp = digit;
                // symb = va_arg(p.args, int);
                printf("symb %d\n", symb);
                // SPACE COUNT
                while (symb > 0) {
                    sp += 1;
                    symb /= BASE;
                    // for (int m = digit; m > 0; m--) {
                    //     sp += 1;
                    printf("sp %d\n", sp);
                    //     // j--;
                    // }
                }
                p.space = digit - sp;
                sp = digit - sp;
                printf("p.space %d\n", p.space);
                // FIND SPEC 'd'
                if (format[i] == 'd' && p.space == 0) {
                    p.spec = 'd';
                    s21_size_t k = 0;
                    symb = va_arg(p.args, int);
                    s21_itoa(symb, BASE, buf);
                    // printf("buf %s\n", buf);
                    do {
                        str[j] = buf[k];
                        j++;
                        k++;
                    } while (k < s21_strlen(buf));
                }
                // FIND SPEC 'd' WITH SPACE
                if (format[i] == 'd' && p.space != 0) {
                    s21_size_t k = 0;
                    // int sp = p.space;
                    symb = va_arg(p.args, int);
                    s21_itoa(symb, BASE, buf);
                    printf("buf sp %s\n", buf);
                    do {
                        str[j] = buf[k];
                        j++;
                        k++;
                    } while (k < s21_strlen(buf));
                    while (sp--) {
                        str[j++] = ' ';
                        // printf("str %s\np.space %d\n", str, sp);
                    }
                }
            }
            // INIT NULL ALL STRUCT
            // struct s_sprintf init;
            p.wdt = 0;
            p.prc = 0;
            p.zero = 0;
            p.pnt = 0;
            p.min = 0;
            p.len = 0;
            p.sign = 0;
            p.perc = 0;
            p.space = 0;
            // if (++*format == '.') {
            //     p.pnt = 1;
            // }
            // if (++*format == ' ') {
            //     p.space = 1;
            // }
        } else {
            str[j] = format[i];
            j++;
        }
        i++;
    }
}

int s21_sprintf(char *str, const char *format, ...) {
    // struct s_sprintf init;
    va_start(p.args, format);
    parser(str, format);
    va_end(p.args);
    return 0;
}

int main(void) {
    char str0[100], str1[100];
    int num0 = 19;
    int num1 = -149;
    char test = 'Q';
    char format[50] = "CHAR: %-6d INT: %+dvgfd %c";
    s21_sprintf(str0, format, num0, num1, test);
    sprintf(str1, format, num0, num1, test);
    printf("STR0: %s\nSTR1: %s\nCHAR: %c\n", str0, str1, test);
    // printf(
    //     "\nSTRUCT:\nwdt = %d\nprc = %d\nzero = %d\npnt = %d\nmin = %d\nlen =
    //     "
    //     "%d\nsign = "
    //     "%d\nperc = %d\nsp = %d\n",
    //     p.wdt, p.prc, p.zero, p.pnt,
    //     p.min, p.len, p.sign, p.perc,
    //     p.space);
    return 0;
}

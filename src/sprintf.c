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
    int space;     // ' ' flag probela
    char spec;     // specificator (d, c, s, i)
} p;

int s21_swrite(char str[40], char buf[40], int j) {
    int k = 0;
    int len_d = s21_strlen(buf);
    do {
        str[j] = buf[k];
        j++;
        k++;
    } while (k < len_d);
    return k;
}

int s21_atoi(const char *buf, int i) {
    int digit = 0;
    for (; buf[i] >= 0x30 && buf[i] <= 0x39; i++) {
        digit = digit + (buf[i] & 0x0F);
        digit *= BASE;
    }
    digit /= BASE;
    return digit;
}

int s21_valist(char buf[40]) {
    int symb = va_arg(p.args, int);
    s21_itoa(symb, BASE, buf);
    // printf("VALIST %s\n", buf);
    return symb;
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
    int i = 0, j = 0, symb = 0, digit = 0, sp = 0, len_d = 0;
    char buf[40];
    // symb = va_arg(p.args, int);
    // s21_itoa(symb, BASE, buf);
    // len_d = strlen(buf);
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
                int k = 0;
                symb = s21_valist(buf);
                len_d = s21_strlen(buf);
                // printf("HUY %s\n%d\n", buf, len_d);
                do {
                    str[j] = buf[k];
                    j++;
                    k++;
                } while (k < len_d);
                i++;
            }
            if (format[i + 1] == '0' || (format[i + 1] == '0' && p.sign != 0)) {
                // int k = 0;
                symb = s21_valist(buf);
                len_d = s21_strlen(buf);
                digit = s21_atoi(format, ++i);
                p.zero = digit - len_d;
                sp = digit - len_d;
                printf("p.zero %d\nlen_d %d\ndigit %d\n", p.zero, len_d, digit);
                while (sp--) {
                    str[j++] = '0';
                    // printf("str %s\np.space %d\n", str, sp);
                }
                s21_swrite(str, buf, j);
                j += digit;
                // do {
                //     str[j] = buf[k];
                //     j++;
                //     k++;
                // } while (k < len_d);
                i += 1;
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
            if (format[i + 1] == '-' || format[i + 1] == '+') {
                i += 1;
                // IF '0'-----------------------------!!!!!!!
                // if (format[i + 1] == '0' ||
                //     (format[i + 1] == '0' && p.sign != 0)) {
                //     // int k = 0;
                //     symb = s21_valist(buf);
                //     len_d = s21_strlen(buf);
                //     digit = s21_atoi(format, ++i);
                //     p.zero = digit - len_d;
                //     sp = digit - len_d;
                //     printf("p.zero %d\nlen_d %d\ndigit %d\n", p.zero, len_d,
                //            digit);
                //     while (sp--) {
                //         str[j++] = '0';
                //         // printf("str %s\np.space %d\n", str, sp);
                //     }
                //     s21_swrite(str, buf, j);
                //     j += digit;
                //     // do {
                //     //     str[j] = buf[k];
                //     //     j++;
                //     //     k++;
                //     // } while (k < len_d);
                //     i += 1;
                // }
                // IF '+'
                if (format[i] == '+') {
                    p.sign = '+';
                    i++;
                    while (format[i] == '+' || format[i] == '-') {
                        p_flag(format[i]);
                        i += 1;
                    }
                    for (; format[i] >= 0x30 && format[i] <= 0x39;) {
                        digit = digit + (format[i] & 0x0F);
                        printf("digit after %d\n", digit);
                        digit *= BASE;
                        // printf("format %c\ndigit %d\n", format[i], digit);
                        i += 1;
                    }
                    digit /= BASE;
                    p.space = digit - len_d;
                    // + FIND SPEC 'd'
                    if (format[i] == 'd' && p.space == 0) {
                        int k = 0;
                        p.spec = 'd';
                        symb = s21_valist(buf);
                        len_d = s21_strlen(buf);
                        if (symb > 0) {
                            str[j] = '+';
                            j++;
                        }
                        do {
                            str[j] = buf[k];
                            j++;
                            k++;
                        } while (k < len_d);
                    }
                    // + FIND SPEC 'd' WITH SPACE
                    if (format[i] == 'd' && p.space != 0) {
                        int k = 0;
                        p.spec = 'd';
                        symb = s21_valist(buf);
                        len_d = s21_strlen(buf);
                        sp = digit - len_d - 1;
                        printf("buf sp %s\nlen_d %d\n", buf, len_d);
                        while (sp--) {
                            str[j++] = ' ';
                            // printf("str %s\np.space %d\n", str, sp);
                        }
                        if (symb > 0) {
                            str[j] = '+';
                            j++;
                        }
                        // sp -= 1;
                        do {
                            str[j] = buf[k];
                            j++;
                            k++;
                        } while (k < len_d);
                    }
                }
                // IF '-'
                if (format[i] == '-') {
                    p.min = '-';
                    // NOT INCLUDE ADDITINAL '-' or '+'
                    while (format[i] == '-' || format[i] == '+') {
                        p_flag(format[i]);
                        i += 1;
                    }
                    // ATOI
                    for (; format[i] >= 0x30 && format[i] <= 0x39;) {
                        digit = digit + (format[i] & 0x0F);
                        digit *= BASE;
                        // printf("format %c\ndigit %d\n", format[i], digit);
                        i += 1;
                    }
                    digit /= BASE;
                    p.space = digit - len_d;
                    // printf("digit %d\n%d\n", digit, p.space);
                    // SPACE COUNT
                    // while (symb > 0) {
                    //     sp += 1;
                    //     symb /= BASE;
                    //     // for (int m = digit; m > 0; m--) {
                    //     //     sp += 1;
                    //     printf("sp %d\n", sp);
                    //     //     // j--;
                    //     // }
                    // }
                    // printf("p.space %d\nlen_d %d\n", p.space, len_d);

                    // FIND SPEC 'd'
                    if (format[i] == 'd' && p.space == 0) {
                        // int k = 0;
                        p.spec = 'd';
                        symb = s21_valist(buf);
                        len_d = s21_strlen(buf);
                        printf("str1 %s\n j1 %d\n", str, j);
                        s21_swrite(str, buf, j);
                        // printf("str2 %s\n j2 %d\n", str, j);
                        j += len_d;
                        //     do {
                        //         str[j] = buf[k];
                        //         j++;
                        //         k++;
                        //     } while (k < len_d);
                    }

                    // FIND SPEC 'd' WITH SPACE
                    if (format[i] == 'd' && p.space != 0) {
                        // int k = 0;
                        p.spec = 'd';
                        symb = s21_valist(buf);
                        len_d = s21_strlen(buf);
                        sp = digit - len_d;
                        printf("buf sp %s\nlen_d %d\n", buf, len_d);
                        s21_swrite(str, buf, j);
                        // printf("str2 %s\n j2 %d\n", str, j);
                        j += len_d;
                        while (sp--) {
                            str[j++] = ' ';
                            // printf("str %s\np.space %d\n", str, sp);
                        }
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
    // str[j] = '\0';
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
    char format[50] = "CHAR: %+06d INT: %dvgfd %c";
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

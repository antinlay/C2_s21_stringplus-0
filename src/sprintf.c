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
    int sp;        // ' ' flag probela
};

void parser(char *str, const char *format, struct s_sprintf init) {
    int i = 0, j = 0, symb = 0;
    char buf[40];
    while (format[i++]) {
        if (format[i] == '%') {
            // if (*format++ == '%' || *format++ == 'c' || *++format == 'd' ||
            //     *++format == 'i' || *++format == 'f' || *++format == 's' ||
            //     *++format == 'u' || *++format == '-' || *++format == '.' ||
            //     *++format == ' ' || *++format == 'h' || *++format == 'l') {
            if (format[i + 1] == 'c') {
                symb = va_arg(init.args, int);
                str[j] = symb;
                i++;
                j++;
            }
            if (format[i + 1] == 'd') {
                s21_size_t k = 0;
                symb = va_arg(init.args, int);
                s21_itoa(symb, BASE, buf);
                printf("%s\n", buf);
                do {
                    str[j] = buf[k];
                    j++;
                    k++;
                } while (k < s21_strlen(buf));
                i++;
            }
            // if (*++format = 'i') {
            //     *str++ = va_arg(init.args, float);
            // }
            // if (*++format = 'f') {
            //     *str++ = va_arg(init.args, float);
            // }
            // if (*++format = 's') {
            //     *str++ = va_arg(init.args, char *);
            // }
            // if (*++format = 'u') {
            //     *str++ = va_arg(init.args, float);
            // }
            // if (format[i + 1] == '-') {
            //     if (format[i + 1] != ) {

            //     }
            // }
            // if (++*format == '.') {
            //     init.pnt = 1;
            // }
            // if (++*format == ' ') {
            //     init.sp = 1;
            // }
        } else {
            str[j] = format[i];
            j++;
        }
    }
}

int s21_sprintf(char *str, const char *format, ...) {
    struct s_sprintf init;
    va_start(init.args, format);
    parser(str, format, init);
    va_end(init.args);
    return strlen(str);
}

int main(void) {
    char str[100];
    char format[50] = "%c\n%-5igfd";
    // char *l = "1231";
    struct s_sprintf init;
    init.wdt = 0;
    init.prc = 0;
    init.zero = 0;
    init.pnt = 0;
    init.min = 0;
    init.len = 0;
    init.sign = 0;
    init.perc = 0;
    init.sp = 0;
    // printf("%lu\n", strcspn(str1, "-1234567890"));
    // printf("%lu\n", strspn("1616gdfg", "-1234567890"));
    // parser(str, format, init);
    sprintf(str, format, 'H', -1);
    printf("%s\n", str);
    printf(
        "wdt = %d\tprc = %d\tzero = %d\tpnt = %d\tmin = %d\tlen = %d\tsign = "
        "%d\tperc = %d\tsp = %d\n",
        init.wdt, init.prc, init.zero, init.pnt, init.min, init.len, init.sign,
        init.perc, init.sp);
    return 0;
}

#include <stdarg.h>
#include <stdio.h>
#include <string.h>

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

char *s21_itoa(int n, char *str) {
    int num = 0, i = 0;
    // num - temp chisla, i - kolichestvo celyh desyatkov
    if (n < 0) {
        num = (n = -n);
        for (i = 1; num >= 10; num /= 10) {
            i *= 10;
        }
        *str++ = '-';
        for (; i > 0; i /= 10) {
            *str++ = 48 + n / i;  // esli i < 10 togda i = 1
            n %= i;
        }
        *str = '\0';
    } else {
        num = n;
        for (i = 1; num >= 10; num /= 10) {
            i *= 10;
        }
        for (; i > 0; i /= 10) {
            *str++ = 48 + n / i;  // esli i < 10 togda i = 1
            n %= i;
        }
        *str = '\0';
    }
    return str;
}

void parser(char *str, const char *format, struct s_sprintf init) {
    int i = -1, j = 0, symb = 0;
    // char *buf, *s;
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
                // if (format[i + 1] == 'd') {
                //     symb = va_arg(init.args, int);
                //     s = s21_itoa(symb, buf);
                //     str[j] = s;
                //     i++;
                //     j++;
                // }
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
                // if (++*format == '-') {
                //     init.min = 1;
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
    char *format = "gbkjgkjdsgh c %c %d";
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
    s21_sprintf(str, format, 'b', 5);
    printf("%s\n", str);
    printf("%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", init.wdt, init.prc,
           init.zero, init.pnt, init.min, init.len, init.sign, init.perc,
           init.sp);
    return 0;
}

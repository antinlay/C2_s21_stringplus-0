#include <stdio.h>
#include <string.h>
#include <stdarg.h>

int s21_sprintf(char *str, char *format, ...)
{
    int out = 0;
    va_list p_arg;         //указатель va_list
    va_start(p_arg, format);    // устанавливаем указатель
    printf("%s\t", format);
    for (char *p = format;*p; p++) {
        if (*p != '%') {
            out += 1;
            str[strlen(str)] = *p;
        }
    }
    va_end(p_arg); // завершаем обработку параметров
    return out;
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

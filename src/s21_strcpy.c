// #include <string.h>
#include "s21_string.h"

// int main(void) {
//     char src[] = "ghjldfhkjgdkgjhfd\0";
//     char dest[] = "hjldf\0";
//     puts(s21_strcpy(dest, src));
//     puts(strcpy(dest, src));
// }

char *s21_strcpy(char *dest, const char *src) {
    const s21_size_t n = s21_strlen(src);  // Вычисляет длину строки str, не включая завершающий нулевой символ
    s21_memcpy(dest, src, n+1);  // Копирует n + 1 символов из src в dest
    return dest;
}
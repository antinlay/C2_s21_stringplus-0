#include "s21_string.h"
#include <stdlib.h>

void *s21_trim(const char *src, const char *trim_chars) {
    if (trim_chars == s21_NULL || s21_strlen(trim_chars) == 0) trim_chars = " ";

    int ok = 0;
    if (src == s21_NULL) ok = 1;

    s21_size_t len_src = 0;
    char* out;
    char* res = s21_NULL;
  //  esli src != NULL
    if (ok == 0) {
        int start_index = 0, end_index = 0, new_index = 0;
        s21_size_t len_trim = 0;
        len_src = s21_strlen(src);
        len_trim = s21_strlen(trim_chars);

        out = (char*)src;  //  prisvaivaem znachenie stroki v peremennuyu
  //  nahodim index pervogo vhozhdeniya
        for (int i = 0; i <= (int)len_src; i++) {
            for (int j = 0; j <= (int)len_trim; j++) {
                if (out[i] == trim_chars[j]) {
                    start_index++;
                    break;
                }
        }
            if (new_index == start_index) break;
            new_index++;
        }

        new_index = 0;
  //  nahodim index poslednego vhozhdeniya
        for (int i = len_src - new_index - 1; i >= 0; i--) {
            for (int j = 0; j < (int)len_trim; j++) {
                if (out[i] == trim_chars[j]) {
                    new_index++;
                    break;
                }
        }
            if (end_index == new_index) break;
            end_index++;
        }

        res = (char*)malloc((len_src - start_index - end_index + 1) * sizeof(char));

        for (int i = 0; i + start_index < (int)len_src - end_index; i++) {
            res[i] = out[i + start_index];
        }
    }
    return len_src != 0 ? (void*)res : s21_NULL; 
}
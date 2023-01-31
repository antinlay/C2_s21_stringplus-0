#include <stdio.h>
#include <stdlib.h>

char *ft_strjoin(int size, char **strs, char *sep) {
  char *tmp_str = malloc(sizeof(*strs) * size + sizeof(*sep) * (size - 1) + 1);
  int i = 0, j = 0, char_str = 0;
  if (NULL == tmp_str) {
    return "Memmory error";
  }
  while (i < size) {
    j = 0;
    while (strs[i][j] != '\0') {
      tmp_str[char_str++] = strs[i][j++];
    }
    j = 0;
    while (sep[j] != '\0' && i != size - 1) {
      tmp_str[char_str++] = sep[j++];
    }
    i++;
  }
  tmp_str[char_str] = '\0';
  return tmp_str;
}

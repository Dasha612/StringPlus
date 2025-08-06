#include "s21_string.h"

char *s21_strchr(const char *str, int c) {
  char *res = S21_NULL;

  do {
    if (*str == (char)c) {
      res = (char *)str;
      break;
    }
  } while (*str++ != '\0');

  return res;
}
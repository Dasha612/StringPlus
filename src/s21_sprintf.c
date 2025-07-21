#include "s21_sprintf.h"

int s21_sprintf(char *str, const char *format, ...) {
  int count = 0;
  int error = 0;
  while (!error && *format) {
    if (*format != '%') {
      *str++ = *format++;
      count++;
    } else {
      //обработка спецификаторов
    }
  }
  str = '\0';
  return count;
}
#include "s21_sprintf.h"

int s21_sprintf(char *str, const char *format, ...) {
  char *str_start = str;
  va_list args;
  va_start(args, format);
  while (*format) {
    if (*format != '%') {
      *str++ = *format++;
    } else {
      format++;
      process_specificator(&format, &str, args);
    }
  }
  *str = '\0';
  va_end(args);
  return str - str_start;
}

void process_specificator(const char **format, char **str, va_list args) {
  switch(**format) {
    case 'c': write_char(str, args); break;
    // case 'd': write_decimal(); break;
    // case 'f': write_float(); break;
    // case 's': write_string(); break;
    // case 'u': write_unsined(); break;
    // case '%': write_percent(); break;
    default: ; // 
  }
  (*format)++;
}

void write_char(char **str, va_list args) {
  char c = (char)va_arg(args, int);
  *(*str)++ = c;
}
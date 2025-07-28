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
    case 'd': write_decimal(str, args); break;
    // case 'f': write_float(); break;
    case 's': write_string(str, args); break;
    // case 'u': write_unsined(); break;
    case '%': write_percent(str); break;
    default: ; // 
  }
  (*format)++;
}

void write_char(char **str, va_list args) {
  char c = (char)va_arg(args, int);
  *(*str)++ = c;
}

void write_decimal(char **str, va_list args) {
  int decimal = (int)va_arg(args, int);
  char buf[24] = {0};
  int i = 0;
 
  if (decimal < 0) {
    *(*str)++ = '-';
    decimal = -decimal;
  }

  if (decimal == 0) {
    *(*str)++ = '0';
  }

  while (decimal > 0) {
    buf[i++] = decimal % 10 + '0';
    decimal /= 10;
  }

  while (i > 0) {
    *(*str)++ = buf[--i];
  }
}

void write_string(char **str, va_list args) {
  char* string = (char*)va_arg(args, char*);
  while (*string) {
    *(*str)++ = *string++;
  }
}

void write_percent(char **str) {
  *(*str)++ = '%';
}
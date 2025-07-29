#include "s21_sprintf.h"

int s21_sprintf(char *str, const char *format, ...) {
  int status = 0;
  char *str_start = str;
  va_list args;
  va_start(args, format);
  while (*format) {
    if (*format != '%') {
      *str++ = *format++;
    } else {
      format++;
      const char *format_save = format;
      FormatFlags flags = {0};
      parse_flags(&format, &flags);
      parse_width(&format, &flags);
      status = process_specificator(&format, &str, args, &flags);
      if (status) {
        *str++ = '%';
        format = format_save;
      }
    }
  }
  *str = '\0';
  va_end(args);
  return str - str_start;
}

void parse_flags(const char **format, FormatFlags *flags) {
  char *flags_str = "+- ";
  while (s21_strchr(flags_str, **format)) {
    switch (**format) {
      case '+': flags->plus = 1; break;
      case '-': flags->minus = 1; break;
      case ' ': flags->space = 1; break;
      default: break;
    }
    (*format)++;
  }
}

void parse_width(const char **format, FormatFlags *flags) {
  char *flags_str = "0123456789";
  while (s21_strchr(flags_str, **format)) {
    flags->width = flags->width * 10 + (**format - '0');
    (*format)++;
  }
}

int process_specificator(const char **format, char **str, va_list args, FormatFlags *flags) {
  int status = 0;
  switch(**format) {
    case 'c': write_char(str, args); break;
    case 'd': write_decimal(str, args, flags); break;
    // case 'f': write_float(); break;
    case 's': write_string(str, args); break;
    // case 'u': write_unsined(); break;
    case '%': write_percent(str); break;
    default: status = 1; break;
  }
  (*format)++;
  return status;
}

void write_char(char **str, va_list args) {
  char c = (char)va_arg(args, int);
  *(*str)++ = c;
}

void write_decimal(char **str, va_list args, FormatFlags *flags) {
  int decimal = (int)va_arg(args, int);
  char buf[24] = {0};
  int dec_len = 0;
 
  if (decimal < 0) {
    flags->is_negative = 1;
    decimal = -decimal;
  }

  if (decimal == 0) {
    procces_zero_num(str, flags);
  } else {
    while (decimal > 0) {
      buf[dec_len++] = decimal % 10 + '0';
      decimal /= 10;
    }

    int padding_width = flags->width - dec_len;
    if (flags->is_negative || flags->plus || flags->space) {
      padding_width--;
    }

    if (!flags->minus && padding_width > 0) {
      write_padding(padding_width, str);
    }

    write_sign(str, flags);
    while (dec_len > 0) {
      *(*str)++ = buf[--dec_len];
    }

    if (flags->minus && padding_width > 0) {
      write_padding(padding_width, str);
    }
  }
}

void procces_zero_num(char **str, FormatFlags *flags) {
  int padding_width = flags->width - 1;
  if (flags->is_negative || flags->plus || flags->space) {
    padding_width--;
  }
  if (!flags->minus && padding_width > 0) {
    write_padding(padding_width, str);
  }

  write_sign(str, flags);
  *(*str)++ = '0';

  if (flags->minus && padding_width > 0) {
    write_padding(padding_width, str);
  }
}

void write_sign(char **str, FormatFlags *flags) {
  if (flags->is_negative) {
    *(*str)++ = '-';
  } else {
    if (flags->plus) {
      *(*str)++ = '+';
    } else if (flags->space) {
      *(*str)++ = ' ';
    }
  }
}

void write_padding(int padding_width, char **str) {
  while (padding_width > 0) {
    *(*str)++ = ' ';
    padding_width--;
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
#include "s21_string.h"

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
      parse_percise(&format, &flags);
      parse_length(&format, &flags);
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

void parse_percise(const char **format, FormatFlags *flags) {
  char *flags_str = "0123456789";
  if (**format == '.') {
    flags->has_percise = 1;
    (*format)++;
    while (s21_strchr(flags_str, **format)) {
      flags->percise = flags->percise * 10 + (**format - '0');
      (*format)++;
    }
  }
}

void parse_length(const char **format, FormatFlags *flags) {
  switch (**format) {
    case 'h': 
      flags->length = 'h'; 
    (*format)++;
    break;
      case 'l': flags->length = 'l'; 
    (*format)++;
    break;
    default: break;
  }
}

int process_specificator(const char **format, char **str, va_list args, FormatFlags *flags) {
  int status = 0;
  switch(**format) {
    case 'c': write_char(str, args, flags); break;
    case 'd': process_decimal(str, args, flags); break;
    case 'f': process_float(str, args, flags); break;
    case 's': write_string(str, args, flags); break;
    case 'u':
      flags->is_unsigned = 1;
      process_decimal(str, args, flags);
      break;
    case '%': write_percent(str); break;
    default: status = 1; break;
  }
  (*format)++;
  return status;
}

void write_char(char **str, va_list args, FormatFlags *flags) {
  char c = (char)va_arg(args, int);
  int padding_width = flags->width - 1;

  if (!flags->minus && padding_width > 0) {
    write_padding(padding_width, str);
  }

  *(*str)++ = c;

  if (flags->minus && padding_width > 0) {
    write_padding(padding_width, str);
  }
}

void process_decimal(char **str, va_list args, FormatFlags *flags) {
  long long int decimal = 0;
  unsigned long long unsigned_decimal = 0;
  extract_decimal_arg(&decimal, &unsigned_decimal, args, flags);
  
  if (!flags->is_unsigned) {
    if (decimal < 0) {
      flags->is_negative = 1;
      unsigned_decimal = (unsigned long long)(-(decimal + 1)) + 1;
    } else {
      unsigned_decimal = (unsigned long long)decimal;
    }
  }

  if (unsigned_decimal == 0) {
    procces_zero_num(str, flags);
  } else {
    write_decimal(str, flags, unsigned_decimal);
  }
}

void extract_decimal_arg(long long *decimal, unsigned long long *unsigned_decimal, va_list args, FormatFlags *flags) {
  if (flags->is_unsigned) {
    switch (flags->length) {
      case 'h':
        *unsigned_decimal = (unsigned short)va_arg(args, unsigned int);
        break;
      case 'l':
        *unsigned_decimal = (unsigned long int)va_arg(args, unsigned long int);
        break;
      default: 
        *unsigned_decimal = (unsigned int)va_arg(args, unsigned int);
        break;
    }
  } else {
    switch (flags->length) {
      case 'h':
        *decimal = (short)va_arg(args, int);
        break;
      case 'l':
        *decimal = (long int)va_arg(args, long int);
        break;
      default: 
        *decimal = (int)va_arg(args, int);
        break;
    }
  }
}

void write_decimal(char **str, FormatFlags *flags, unsigned long long unsigned_decimal) {
  char buf[24] = {0};
  int dec_len = 0;
  int percise_padding = 0;
  int padding_width = 0;

  while (unsigned_decimal > 0) {
    buf[dec_len++] = unsigned_decimal % 10 + '0';
    unsigned_decimal /= 10;
  }
  if (dec_len < flags->percise) {
    percise_padding = flags->percise - dec_len;
  }

  padding_width = flags->width - (dec_len + percise_padding);
  if ((flags->is_negative || flags->plus || flags->space) && !flags->is_unsigned) {
    padding_width--;
  }

  if (!flags->minus && padding_width > 0) {
    write_padding(padding_width, str);
  }

  if (!flags->is_unsigned) {
    write_sign(str, flags);
  }
  while (percise_padding > 0) {
    *(*str)++ = '0';
    percise_padding--;
  }
  while (dec_len > 0) {
    *(*str)++ = buf[--dec_len];
  }

  if (flags->minus && padding_width > 0) {
    write_padding(padding_width, str);
  }
}

void procces_zero_num(char **str, FormatFlags *flags) {
  int percise_padding = 0;
  int dec_len = 1;

  if (flags->percise) {
    percise_padding = flags->percise - dec_len;
  } else if (flags->has_percise) {
    dec_len = 0;
  }
  int padding_width = flags->width - (dec_len + percise_padding);
  if (flags->is_negative || flags->plus || flags->space) {
    padding_width--;
  }
  if (!flags->minus && padding_width > 0) {
    write_padding(padding_width, str);
  }

  write_sign(str, flags);
  while (percise_padding > 0) {
    *(*str)++ = '0';
    percise_padding--;
  }
  while (dec_len > 0) {
    *(*str)++ = '0';
    dec_len--;
  }

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

void write_string(char **str, va_list args, FormatFlags *flags) {
  char* string = (char*)va_arg(args, char*);
  int str_len = s21_strlen(string);

  if (flags->has_percise) {
    if (flags->percise < str_len) {
      str_len = flags->percise;
    }
  }

  int padding_width = flags->width - str_len;

  if (!flags->minus && padding_width > 0) {
    write_padding(padding_width, str);
  }

  while (str_len-- > 0) {
    *(*str)++ = *string++;
  }

  if (flags->minus && padding_width > 0) {
    write_padding(padding_width, str);
  }
}

void write_percent(char **str) {
  *(*str)++ = '%';
}

void process_float(char **str, va_list args, FormatFlags *flags) {
  Buffer int_buf = {0};
  Buffer frac_buf = {0};
  double value = va_arg(args, double);
  char *str_nan = "nan";
  char *str_inf = "fni";

  flags->is_negative = signbit(value);
  if (isnan(value)) {
    int_buf.length = 3;
    s21_strncpy(int_buf.buffer, str_nan, 3);
  } else if (isinf(value)) {
    int_buf.length = 3;
    s21_strncpy(int_buf.buffer, str_inf, 3);
  } else {
    if(!flags->has_percise) {
      flags->percise = 6;
    }
    value = fabs(value);

    double rounder = 0.5;
    for (int i = 0; i < flags->percise; i++) {
      rounder /= 10.0;
    }
    value += rounder;

    long long integer = (long long)value;
    double fractional = value - integer;
    if (integer == 0) {
      int_buf.buffer[int_buf.length++] = '0';
    }
    while (integer > 0) {
      int_buf.buffer[int_buf.length++] = integer % 10 + '0';
      integer /= 10;
    }
    for (int i = 0; i < flags->percise; i++) {
      fractional *= 10L;
      int digit = (int)fractional;
      frac_buf.buffer[frac_buf.length++] = '0' + digit;
      fractional -= digit;
    }
  }
  write_float(str, flags, &int_buf, &frac_buf);
}

void write_float(char **str, FormatFlags *flags, Buffer *int_buf, Buffer *frac_buf) {
  int padding_width = flags->width - (int_buf->length + frac_buf->length);
  if (flags->is_negative || flags->plus || flags->space) {
    padding_width--;
  }
  if (flags->percise > 0) {
    padding_width--;
  }
  if (!flags->minus && padding_width > 0) {
    write_padding(padding_width, str);
  }

  write_sign(str, flags);
  while (int_buf->length > 0) {
    *(*str)++ = int_buf->buffer[--int_buf->length];
  }

  if (flags->percise > 0) {
    *(*str)++ = '.';
    for (int i = 0; i < frac_buf->length; i++) {
      *(*str)++ = frac_buf->buffer[i];
    }
  }

  if (flags->minus && padding_width > 0) {
    write_padding(padding_width, str);
  }
}
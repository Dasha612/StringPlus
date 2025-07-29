#include <stdarg.h>
#include <stdio.h> //temp
#include "s21_strchr.h" //temp

typedef struct {
  int plus;
  int minus;
  int space;
  int width;
  int is_negative;
} FormatFlags;

int s21_sprintf(char *str, const char *format, ...);
void parse_flags(const char **format, FormatFlags *flags);
void parse_width(const char **format, FormatFlags *flags);
void procces_zero_num(char **str, FormatFlags *flags);
void write_sign(char **str, FormatFlags *flags);
void write_padding(int padding_width, char **str);
void write_char(char **str, va_list args);
int process_specificator(const char **format, char **str, va_list args, FormatFlags *flags);
void write_string(char **str, va_list args);
void write_decimal(char **str, va_list args, FormatFlags *flags);
void write_percent(char **str);


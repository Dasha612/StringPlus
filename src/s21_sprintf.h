#include <stdarg.h>
#include <stdio.h> //temp
#include "s21_strchr.h" //temp

typedef struct {
  int plus;
  int minus;
  int space;
} FormatFlags;

int s21_sprintf(char *str, const char *format, ...);
void parse_flags(const char **format, FormatFlags *flags);
void write_char(char **str, va_list args);
int process_specificator(const char **format, char **str, va_list args, FormatFlags flags);
void write_string(char **str, va_list args);
void write_decimal(char **str, va_list args, FormatFlags flags);
void write_percent(char **str);


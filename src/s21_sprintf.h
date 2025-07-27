#include <stdarg.h>
#include <stdio.h> //temp

int s21_sprintf(char *str, const char *format, ...);
void process_specificator(const char **format, char **str, va_list args);
void write_char(char **str, va_list args);void process_specificator(const char **format, char **str, va_list args);
void write_string(char **str, va_list args);
void write_percent(char **str);



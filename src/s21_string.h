#ifndef S21_STRING_H
#define S21_STRING_H

typedef unsigned long int s21_size_t;
#define S21_NULL ((void *)0)


#include <stdlib.h>
#include <stdarg.h>
#include <math.h>
#include <stdio.h> // TO DO убрать после удаления sprintf из sterror



void *s21_memchr(const void *str, int c, s21_size_t n);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
char *s21_strchr(const char *str, int c);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
s21_size_t s21_strcspn(const char *str1, const char *str2);
char *s21_strerror(int errnum);
s21_size_t s21_strlen(const char *str);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int c);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strtok(char *str, const char *delim);
int s21_sprintf(char *str, const char *format, ...);
void *s21_to_lower(const char *str);
void *s21_to_upper(const char *str);
void *s21_insert(const char *src, const char *str, s21_size_t start_index);
void *s21_trim(const char *src, const char *trim_chars);



int s21_sprintf(char *str, const char *format, ...);

typedef struct {
  int plus;
  int minus;
  int space;
  int width;
  int percise;
  int has_percise;
  int is_negative;
  int is_unsigned;
  int length;
} FormatFlags;

typedef struct {
  char buffer[1024];
  int length;
} Buffer;

void parse_flags(const char **format, FormatFlags *flags);
void parse_width(const char **format, FormatFlags *flags);
void parse_percise(const char **format, FormatFlags *flags);
void parse_length(const char **format, FormatFlags *flags);
void procces_zero_num(char **str, FormatFlags *flags);
void write_sign(char **str, FormatFlags *flags);
void write_padding(int padding_width, char **str);
void write_char(char **str, va_list args, FormatFlags *flags);
int process_specificator(const char **format, char **str, va_list args, FormatFlags *flags);
void write_string(char **str, va_list args, FormatFlags *flags);
void process_decimal(char **str, va_list args, FormatFlags *flags);
void write_decimal(char **str, FormatFlags *flags, unsigned long long unsigned_decimal);
void extract_decimal_arg(long long *decimal, unsigned long long *unsigned_decimal, va_list args, FormatFlags *flags);
void write_percent(char **str);
void process_float(char **str, va_list args, FormatFlags *flags);
void write_float(char **str, FormatFlags *flags, Buffer *int_buf, Buffer *frac_buf);

#endif  // S21_STRING_H

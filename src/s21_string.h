#ifndef S21_STRING_H
#define S21_STRING_H

#define s21_size_t unsigned long int
#define S21_NULL ((void *)0)


#include <stdlib.h>
#include <stdio.h>



void *s21_memchr(const void *str, int c, size_t n);
//int s21_memcmp(const void *str1, const void *str2, size_t n);

int main();

#endif  // S21_STRING_H

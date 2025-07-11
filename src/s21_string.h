#ifndef S21_STRING_H
#define S21_STRING_H

typedef unsigned long int s21_size_t;
#define S21_NULL ((void *)0)


#include <stdlib.h>
#include <stdio.h>



void *s21_memchr(const void *str, int c, s21_size_t n);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);

int main();

#endif  // S21_STRING_H


#include <stdlib.h>
#include <stdio.h>
#include "string.h"

typedef unsigned long int s21_size_t;
#define S21_NULL ((void *)0)
void *s21_memcpy(void *dest, const void *src, s21_size_t n){
    const unsigned char *source = (const unsigned char *)src;
    unsigned char *destination = (unsigned char *)dest;
    for (s21_size_t i = 0; i < n; i++) {
        destination[i] = source[i];
    }
    return dest;
}

int main() {
    char src[] = "Hello, world!";
    char dest[30];
    s21_memcpy(dest, src, strlen(src) + 1); // +1 для копирования '\0'
    printf("%s\n", dest);
    return 0;
}
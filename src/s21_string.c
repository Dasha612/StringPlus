
#include <stdlib.h>
#include <stdio.h>
#include "string.h"


typedef unsigned long int s21_size_t;
#define S21_NULL ((void *)0)
char *s21_strchr(const char *str, int c) {
    char *res = S21_NULL;
    
    do {
        if (*str == (char)c) {
            res = (char *)str;
            break;
        }
    } while (*str++ != '\0');
    
    return res;
}

s21_size_t s21_strcspn(const char *str1, const char *str2){
    s21_size_t count = 0;
    while (*str1 != '\0'){
        if (s21_strchr(str2, *str1)) break;
        str1++;
        count++;
    }
    return count;

}
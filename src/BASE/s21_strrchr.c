#include "../s21_string.h"

char *s21_strrchr(const char *str, int c) {
    char *res = S21_NULL;
    
    do {
        if (*str == (char)c) {
            res = (char *)str;
        }
    } while (*str++ != '\0');
    
    return res;
}
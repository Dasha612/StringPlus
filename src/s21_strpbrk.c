#include "s21_string.h"


char *s21_strpbrk(const char *str1, const char *str2){
    const char *found = S21_NULL;
    while (*str1 != '\0'){
        const char * ptr = str2;
        while (*ptr != '\0'){
            if (*str1 == *ptr){
                found = str1;
                break;
            } 
            ptr++;
        }
        if (found != S21_NULL) break;
        str1++;
    }
    return (char*)found;
}
#include "../s21_string.h"


char *s21_strtok(char *str, const char *delim) {
    static char * buffer = s21_NULL;
    char * token_start = s21_NULL;

    if (str != S21_NULL) {
        buffer = str;
    }
    while (*buffer != '\0' && s21_strchr(delim, *buffer) != S21_NULL) {
        buffer++;
    }
    
  
    if (*buffer == '\0') {
        return S21_NULL;
    }
    

    token_start = buffer;
    

    while (*buffer != '\0' && s21_strchr(delim, *buffer) == S21_NULL) {
        buffer++;
    }

    if (*buffer != '\0') {
        *buffer = '\0';
        buffer++;
    }
    
    return token_start;




}
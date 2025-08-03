#include "s21_string.h"


char *s21_strtok(char *str, const char *delim) {
    static char *buffer = S21_NULL;
    char *token_start = S21_NULL;
    int found = 0;


    if (str != S21_NULL) {
        buffer = str;
    }

    while (*buffer != '\0' && s21_strchr(delim, *buffer) != S21_NULL) {
        buffer++;
    }


    if (*buffer != '\0') {
        token_start = buffer;
        found = 1;
        

        while (*buffer != '\0' && s21_strchr(delim, *buffer) == S21_NULL) {
            buffer++;
        }

        if (*buffer != '\0') {
            *buffer = '\0';
            buffer++;
        }
    }

    return found ? token_start : S21_NULL;
}
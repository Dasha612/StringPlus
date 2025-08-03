#include "s21_string.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
    char *new_str = S21_NULL; 
    int success = 1;       

    if (src == S21_NULL || str == S21_NULL) {
        success = 0;
    }

    s21_size_t src_len = 0;
    s21_size_t str_len = 0;

    if (success) {
        src_len = s21_strlen(src);
        str_len = s21_strlen(str);

    
        if ((src_len == 0 && start_index != 0) || start_index > src_len) {
            success = 0;
        }
    }

    if (success) {
        new_str = (char *)malloc(src_len + str_len + 1);
        if (new_str == S21_NULL) {
            success = 0;
        }
    }

    if (success) {
        s21_size_t i = 0;

   
        for (; i < start_index; i++) {
            new_str[i] = src[i];
        }

   
        for (s21_size_t j = 0; j < str_len; j++, i++) {
            new_str[i] = str[j];
        }

        for (s21_size_t j = start_index; j < src_len; j++, i++) {
            new_str[i] = src[j];
        }

        new_str[src_len + str_len] = '\0';
    }

    return new_str;  
}

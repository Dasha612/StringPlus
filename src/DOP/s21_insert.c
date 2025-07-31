#include "../s21_string.h"


void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
    char * new_str = S21_NULL;
    char * res = new_str;
    s21_size_t src_len = s21_strlen(src);
    s21_size_t str_len = s21_strlen(str);
    if (start_index > src_len) {
        start_index = src_len;
    }



    if (str != S21_NULL&&src != S21_NULL) {
        new_str = malloc(src_len + str_len + 1);
        res = new_str;
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
    return (void *) res;

}
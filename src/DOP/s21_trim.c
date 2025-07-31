#include "../s21_string.h"


void *s21_trim(const char *src, const char *trim_chars) {
    char *result = S21_NULL;  

    if (src != S21_NULL) {
     
        if (!trim_chars || trim_chars[0] == '\0') {
            trim_chars = " \t\n";
        }

        const char *start = src;
        while (*start && s21_strchr(trim_chars, *start)) {
            start++;
        }

     
        const char *end = src + s21_strlen(src) - 1;
        while (end >= start && s21_strchr(trim_chars, *end)) {
            end--;
        }

    
        s21_size_t new_len = end >= start ? (end - start + 1) : 0;

        result = malloc(new_len + 1);
        if (result) {
         
            if (new_len > 0) {
                s21_memcpy(result, start, new_len);
            }
            result[new_len] = '\0';
        }
    }

    return result;  
}
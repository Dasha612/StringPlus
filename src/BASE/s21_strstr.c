#include "../s21_string.h"


char *s21_strstr(const char *haystack, const char *needle) {
    char *found = S21_NULL;
    if (*needle != '\0'){
        while (*haystack != '\0'){
            const char *h = haystack;
            const char * n = needle;
            while (*h != '\0' && *n != '\0' && *h == *n) {
                h++;
                n++;
            }
            if (*n == '\0') {
                found = haystack;
                break;
            }
            
            haystack++;
        }


    }
    
    return found;
    
}
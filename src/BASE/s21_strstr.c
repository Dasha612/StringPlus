#include "../s21_string.h"


char *s21_strstr(const char *haystack, const char *needle) {
    const char *found = S21_NULL;
    int searching = 1;

    if (*needle == '\0') {
        found = haystack;
        searching = 0;
    }

    while (searching && *haystack != '\0') {
        const char *h = haystack;
        const char *n = needle;
        
        while (*h != '\0' && *n != '\0' && *h == *n) {
            h++;
            n++;
        }
        
        if (*n == '\0') {
            found = haystack;
            searching = 0;
        } else {
            haystack++;
        }
    }
    
    return (char *)found;
}

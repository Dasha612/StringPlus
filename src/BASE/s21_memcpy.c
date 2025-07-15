#include "../s21_string.h"


void *s21_memcpy(void *dest, const void *src, s21_size_t n){
    const unsigned char *source = (const unsigned char *)src;
    unsigned char *destination = (unsigned char *)dest;
    for (s21_size_t i = 0; i < n; i++) {
        destination[i] = source[i];
    }
    return dest;
}

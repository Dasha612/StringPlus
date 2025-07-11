#include "s21_string.h"


void *s21_memchr(const void *str, int c, size_t n) {
    const unsigned char *buffer = (const unsigned char *)str;
    void *result = S21_NULL;  

    for (size_t i = 0; i < n; i++) {
        if (buffer[i] == (unsigned char)c) {
            result = (void *)(buffer + i);
            break;
        }
    }
    return result;
}

//int s21_memcmp(const void *str1, const void *str2, size_t n){}




int main() {
    char test[] = "Hello, world!";
    void *found = s21_memchr(test, 'o', sizeof(test));
    if (found) {
        printf("Найден 'o' по позиции: %ld\n", (char*)found - test);
        printf("Значение: %c\n", *(char*)found);
    } else {
        printf("Не найден\n");
    }
    
    found = s21_memchr(test, 'z', sizeof(test));
    printf("Поиск 'z': %s\n", found ? "найден" : "не найден");
    return 0;
}
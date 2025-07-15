
#include <stdlib.h>
#include <stdio.h>
#include "string.h"


typedef unsigned long int s21_size_t;
#define S21_NULL ((void *)0)
char *s21_strchr(const char *str, int c) {
    char *res = S21_NULL;
    
    do {
        if (*str == (char)c) {
            res = (char *)str;
            break;
        }
    } while (*str++ != '\0');
    
    return res;
}

s21_size_t s21_strcspn(const char *str1, const char *str2){
    s21_size_t count = 0;
    while (*str1 != '\0'){
        if (s21_strchr(str2, *str1)) break;
        str1++;
        count++;
    }
    return count;

}


int main() {
    // Тестовые примеры
    const char *test_cases[] = {
        "Hello123", "0123456789",
        "Hello123", "",
        "apple", "a",
        "banana", "xyz",
        "test@email.com", "@.",
        "12345", "54321",
        NULL
    };
    
    printf("%-30s | %-10s | %-10s\n", "Test Case", "s21_strcspn", "strcspn");
    printf("---------------------------------+------------+------------\n");
    
    for (int i = 0; test_cases[i] != NULL; i += 2) {
        const char *str = test_cases[i];
        const char *reject = test_cases[i+1];
        
        s21_size_t s21_result = s21_strcspn(str, reject);
        size_t std_result = strcspn(str, reject);
        
        printf("%-15s + %-10s | %-10lu | %-10lu\n", 
               str, reject, s21_result, std_result);
    }
    
    return 0;
}
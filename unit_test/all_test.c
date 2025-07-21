#include <stdio.h>
#include <string.h>
#include "../src/s21_string.h"

void test_memchr();
void test_memcmp();
void test_memcpy();
void test_memset();
void test_strchr();
void test_strcspn();
void test_strerror();
void test_strlen();
void test_strncat();
void test_strncmp();
void test_strncpy();
void test_strpbrk();
void test_strrchr();
void test_strstr();
void test_strtok();

int main() {
    test_memchr();
    // test_memcmp();
    // test_memcpy();
    // test_memset();
    // test_strchr();
    // test_strcspn();
    // test_strerror();
    // test_strlen();
    // test_strncat();
    // test_strncmp();
    // test_strncpy();
    // test_strpbrk();
    // test_strrchr();
    // test_strstr();
    // test_strtok();
    return 0;
}

void test_memchr() {
    char *str = "Hello, World!";
    void *s21_res = s21_memchr(str, 'W', 13);
    void *res = memchr(str, 'W', 13);
    printf("s21: %p\n", s21_res);
    printf("res: %p\n", res);

    char *str2 = "";
    void *s21_res2 = s21_memchr(str2, 'W', 13);
    void *res2 = memchr(str2, 'W', 13);
    printf("s21: %p\n", s21_res2);
    printf("res: %p\n", res2);

    char *str3 = "Hello, World!";
    void *s21_res3 = s21_memchr(str3, 'W', 0);
    void *res3 = memchr(str3, 'W', 0);
    printf("s21: %p\n", s21_res3);
    printf("res: %p\n", res3);

    char *str4 = "Hello, World!";
    void *s21_res4 = s21_memchr(str4, 'f', 1000);
    void *res4 = memchr(str4, 'f', 1000);
    printf("s21: %p\n", s21_res4);
    printf("res: %p\n", res4);

    // char *str5 = "Hello, World!";
} 
void test_memcmp() {
    // code here
}
void test_memcpy() {
    // code here
}
void test_memset() {
    // code here
}
void test_strchr() {
    // code here
}
void test_strcspn() {
    // code here
}
void test_strerror() {
    // code here
}
void test_strlen() {
    // code here
}
void test_strncat() {
    // code here
}
void test_strncmp() {
    // code here
}
void test_strncpy() {
    // code here
}
void test_strpbrk() {
    // code here
}
void test_strrchr() {
    // code here
}
void test_strstr() {
    // code here
}
#include <string.h>
#include <check.h>
#include "../src/s21_string.h"
// size_t strlen(const char *s)
// Сравнение strlen и s21_strlen
START_TEST(test1_s21_strlen_empty) {
    const char str[] = "";
    size_t s21_result = s21_strlen(str);
    size_t result = strlen(str);
    ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(test2_s21_strlen_one_char) {
    const char str[] = "a";
    size_t s21_result = s21_strlen(str);
    size_t result = strlen(str);
    ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(test3_s21_strlen_normal) {
    const char str[] = "Hello, world!";
    size_t s21_result = s21_strlen(str);
    size_t result = strlen(str);
    ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(test4_s21_strlen_spaces) {
    const char str[] = "   ";
    size_t s21_result = s21_strlen(str);
    size_t result = strlen(str);
    ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(test5_s21_strlen_embedded_null) {
    const char str[] = "abc\0def";
    size_t s21_result = s21_strlen(str);
    size_t result = strlen(str);
    ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(test6_s21_strlen_long_string) {
    char long_str[1001];
    for (int i = 0; i < 1000; i++) long_str[i] = 'a';
    long_str[1000] = '\0';
    size_t s21_result = s21_strlen(long_str);
    size_t result = strlen(long_str);
    ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(test7_s21_strlen_unicode) {
    const char str[] = "привет"; // UTF-8
    size_t s21_result = s21_strlen(str);
    size_t result = strlen(str);
    ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(test8_s21_strlen_null_pointer) {
    size_t s21_result = s21_strlen(NULL);
    size_t result = strlen(NULL);
    ck_assert_int_eq(s21_result, result);
}
END_TEST
*s21_strlen_suite(void) {
    Suite *s = suite_create("s21_strlen");
    TCase *tc = tcase_create("s21_strlen_core");
    tcase_add_test(tc, test1_s21_strlen_empty);
    tcase_add_test(tc, test2_s21_strlen_one_char);
    tcase_add_test(tc, test3_s21_strlen_normal);
    tcase_add_test(tc, test4_s21_strlen_spaces);
    tcase_add_test(tc, test5_s21_strlen_embedded_null);
    tcase_add_test(tc, test6_s21_strlen_long_string);
    tcase_add_test(tc, test7_s21_strlen_unicode);
    tcase_add_test(tc, test8_s21_strlen_null_pointer);
    suite_add_tcase(s, tc);
    return s;
}

int main() {
    int failed;
    SRunner *runner = srunner_create(s21_strlen_suite());
    srunner_run_all(runner, CK_NORMAL);
    failed = srunner_ntests_failed(runner);
    srunner_free(runner);
    return (failed == 0) ? 0 : 1;
}
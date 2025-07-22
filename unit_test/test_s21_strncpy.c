#include <string.h>
#include <check.h>
#include "../src/s21_string.h"
// char *strncpy(char *dest, const char *src, size_t n)
// Сравнение strncpy и s21_strncpy
START_TEST(test1_s21_strncpy_simple_copy) {
    size_t n = 5;
    s21_size_t s21_n = 5;
    char a[10] = {0};
    char s21_a[10] = {0};
    const char b[] = "hello";
    const char s21_b[] = "hello";
    char *result = strncpy(a, b, n);
    char *s21_result = s21_strncpy(s21_a, s21_b, s21_n);
    ck_assert_str_eq(s21_result, result);
    ck_assert_str_eq(s21_a, a);
}
END_TEST

START_TEST(test2_s21_strncpy_full_copy) {
    size_t n = 7;
    s21_size_t s21_n = 7;
    char a[10] = {0};
    char s21_a[10] = {0};
    const char b[] = "abcdefg";
    const char s21_b[] = "abcdefg";
    char *result = strncpy(a, b, n);
    char *s21_result = s21_strncpy(s21_a, s21_b, s21_n);
    ck_assert_str_eq(s21_result, result);
    ck_assert_str_eq(a, "abcdefg");
}
END_TEST

START_TEST(test3_s21_strncpy_n_zero) {
    size_t n = 0;
    s21_size_t s21_n = 0;
    char a[10] = "abcdefghi";
    char s21_a[10] = "abcdefghi";
    const char b[] = "xyz";
    const char s21_b[] = "xyz";
    char *result = strncpy(a, b, n);
    char *s21_result = s21_strncpy(s21_a, s21_b, s21_n);
    ck_assert_str_eq(s21_result, result);
    ck_assert_str_eq(s21_a, a);
}
END_TEST

START_TEST(test4_s21_strncpy_n_bigger_than_src) {
    size_t n = 8;
    s21_size_t s21_n = 8;
    char a[10] = {0};
    char s21_a[10] = {0};
    const char b[] = "abc";
    const char s21_b[] = "abc";
    char *result = strncpy(a, b, n);
    char *s21_result = s21_strncpy(s21_a, s21_b, s21_n);
    ck_assert_str_eq(s21_result, result);
    ck_assert_str_eq(s21_a, a);
}
END_TEST

START_TEST(test5_s21_strncpy_embedded_null_in_src) {
    size_t n = 5;
    s21_size_t s21_n = 5;
    char a[10] = {0};
    char s21_a[10] = {0};
    const char b[] = "12\0345";
    const char s21_b[] = "12\0345";
    char *result = strncpy(a, b, n);
    char *s21_result = s21_strncpy(s21_a, s21_b, s21_n);
    ck_assert_str_eq(s21_result, result);
    ck_assert_str_eq(s21_a, a);
}
END_TEST

START_TEST(test6_s21_strncpy_overlap) {
    size_t n = 5;
    s21_size_t s21_n = 5;
    char a[10] = "123456789";
    char s21_a[10] = "123456789";
    char *result = strncpy(a + 5, a, n);
    char *s21_result = s21_strncpy(s21_a + 5, s21_a, s21_n);
    ck_assert_str_eq(s21_result, result);
    ck_assert_str_eq(s21_a, a);
}
END_TEST

START_TEST(test7_s21_strncpy_empty_src) {
    size_t n = 5;
    s21_size_t s21_n = 5;
    char a[10] = {0};
    char s21_a[10] = {0};
    const char b[] = "";
    const char s21_b[] = "";
    char *result = strncpy(a, b, n);
    char *s21_result = s21_strncpy(s21_a, s21_b, s21_n);
    ck_assert_str_eq(s21_result, result);
    ck_assert_str_eq(s21_a, a);
}
END_TEST

START_TEST(test8_s21_strncpy_empty_dest) {
    size_t n = 3;
    s21_size_t s21_n = 3;
    char a[10] = {0};
    char s21_a[10] = {0};
    const char b[] = "abc";
    const char s21_b[] = "abc";
    char *result = strncpy(a, b, n);
    char *s21_result = s21_strncpy(s21_a, s21_b, s21_n);
    ck_assert_str_eq(s21_result, result);
    ck_assert_str_eq(s21_a, a);
}
END_TEST

START_TEST(test9_s21_strncpy_partial_copy) {
    size_t n = 3;
    s21_size_t s21_n = 3;
    char a[10] = {0};
    char s21_a[10] = {0};
    const char b[] = "abcdef";
    const char s21_b[] = "abcdef";
    char *result = strncpy(a, b, n);
    char *s21_result = s21_strncpy(s21_a, s21_b, s21_n);
    ck_assert_str_eq(s21_result, result);
    ck_assert_str_eq(s21_a, a);
}
END_TEST

Suite *s21_strncpy_suite(void) {
    Suite *s = suite_create("s21_strncpy");
    TCase *tc = tcase_create("s21_strncpy_core");
    tcase_add_test(tc, test1_s21_strncpy_simple_copy);
    tcase_add_test(tc, test2_s21_strncpy_full_copy);
    tcase_add_test(tc, test3_s21_strncpy_n_zero);
    tcase_add_test(tc, test4_s21_strncpy_n_bigger_than_src);
    tcase_add_test(tc, test5_s21_strncpy_embedded_null_in_src);
    tcase_add_test(tc, test6_s21_strncpy_overlap);
    tcase_add_test(tc, test7_s21_strncpy_empty_src);
    tcase_add_test(tc, test8_s21_strncpy_empty_dest);
    tcase_add_test(tc, test9_s21_strncpy_partial_copy);
    suite_add_tcase(s, tc);
    return s;
}

int s21_strncpy_main() {
    int failed;
    SRunner *runner = srunner_create(s21_strncpy_suite());
    srunner_run_all(runner, CK_NORMAL);
    failed = srunner_ntests_failed(runner);
    srunner_free(runner);
    return (failed == 0) ? 0 : 1;
}
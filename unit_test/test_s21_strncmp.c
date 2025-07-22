#include <string.h>
#include <check.h>
#include "../src/s21_string.h"
// int strncmp(const char *s1, const char *s2, size_t n)
// Сравнение strncmp и s21_strncmp
START_TEST(test1_s21_strncmp_equal_strings) {
    size_t n = 5;
    s21_size_t s21_n = 5;
    const char a[] = "hello";
    const char b[] = "hello";
    int res = strncmp(a, b, n);
    int s21_res = s21_strncmp(a, b, s21_n);
    ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(test2_s21_strncmp_different_first_char) {
    size_t n = 5;
    s21_size_t s21_n = 5;
    const char a[] = "apple";
    const char b[] = "apply";
    int res = strncmp(a, b, n);
    int s21_res = s21_strncmp(a, b, s21_n);
    ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(test3_s21_strncmp_last_char_diff) {
    size_t n = 5;
    s21_size_t s21_n = 5;
    const char a[] = "abcde";
    const char b[] = "abcdf";
    int res = strncmp(a, b, n);
    int s21_res = s21_strncmp(a, b, s21_n);
    ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(test4_s21_strncmp_embedded_null) {
    size_t n = 6;
    s21_size_t s21_n = 6;
    const char a[] = "abc\0def";
    const char b[] = "abc\0ghi";
    int res = strncmp(a, b, n);
    int s21_res = s21_strncmp(a, b, s21_n);
    ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(test5_s21_strncmp_zero_length) {
    size_t n = 0;
    s21_size_t s21_n = 0;
    const char a[] = "test";
    const char b[] = "test123";
    int res = strncmp(a, b, n);
    int s21_res = s21_strncmp(a, b, s21_n);
    ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(test6_s21_strncmp_same_prefix_longer_string) {
    size_t n = 5;
    s21_size_t s21_n = 5;
    const char a[] = "hello";
    const char b[] = "hellolonger";
    int res = strncmp(a, b, n);
    int s21_res = s21_strncmp(a, b, s21_n);
    ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(test7_s21_strncmp_high_ascii_values) {
    size_t n = 2;
    s21_size_t s21_n = 2;
    const char a[] = "\xff\xfe";
    const char b[] = "\xfe\xff";
    int res = strncmp(a, b, n);
    int s21_res = s21_strncmp(a, b, s21_n);
    ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(test8_s21_strncmp_buffer_overflow) {
    size_t n = 100;
    s21_size_t s21_n = 100;
    const char a[] = "abcdefghij";
    const char b[] = "abcdexxxxxx";
    int res = strncmp(a, b, n);
    int s21_res = s21_strncmp(a, b, s21_n); // Больше, чем длина обеих строк
    ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(test9_s21_strncmp_empty_strings) {
    size_t n = 1;
    s21_size_t s21_n = 1;
    const char a[] = "";
    const char b[] = "";
    int res = strncmp(a, b, n);
    int s21_res = s21_strncmp(a, b, s21_n);
    ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(test10_s21_strncmp_partial_compare) {
    size_t n = 3;
    s21_size_t s21_n = 3;
    const char a[] = "abcdef";
    const char b[] = "abcxyz";
    int res = strncmp(a, b, n);
    int s21_res = s21_strncmp(a, b, s21_n);
    ck_assert_int_eq(s21_res, res);
}
END_TEST

Suite *s21_strncmp_suite(void) {
    Suite *s = suite_create("s21_strncmp");
    TCase *tc = tcase_create("s21_strncmp_core");
    tcase_add_test(tc, test1_s21_strncmp_equal_strings);
    tcase_add_test(tc, test2_s21_strncmp_different_first_char);
    tcase_add_test(tc, test3_s21_strncmp_last_char_diff);
    tcase_add_test(tc, test4_s21_strncmp_embedded_null);
    tcase_add_test(tc, test5_s21_strncmp_zero_length);
    tcase_add_test(tc, test6_s21_strncmp_same_prefix_longer_string);
    tcase_add_test(tc, test7_s21_strncmp_high_ascii_values);
    tcase_add_test(tc, test8_s21_strncmp_buffer_overflow);
    tcase_add_test(tc, test9_s21_strncmp_empty_strings);
    tcase_add_test(tc, test10_s21_strncmp_partial_compare);
    suite_add_tcase(s, tc);
    return s;
}

int s21_strncmp_main() {
    int failed;
    SRunner *runner = srunner_create(s21_strncmp_suite());
    srunner_run_all(runner, CK_NORMAL);
    failed = srunner_ntests_failed(runner);
    srunner_free(runner);
    return (failed == 0) ? 0 : 1;
}
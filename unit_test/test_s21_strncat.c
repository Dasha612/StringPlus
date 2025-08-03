#include <string.h>
#include <check.h>
#include "../src/s21_string.h"
// char* strncat(char *dest, const char *src, size_t n)
START_TEST(test1_s21_strncat_simple_case) {
    size_t n = 3;
    s21_size_t s21_n = 3;
    char a[10] = "abc";
    char s21_a[10] = "abc";
    const char b[] = "def";
    const char s21_b[] = "def";
    char *res = strncat(a, b, n);
    char *s21_res = s21_strncat(s21_a, s21_b, s21_n);
    ck_assert_str_eq(s21_res, res);
    ck_assert_str_eq(s21_a, a);
}
END_TEST

START_TEST(test2_s21_strncat_full_copy) {
    size_t n = 6;
    s21_size_t s21_n = 6;
    char a[10] = "abc";
    char s21_a[10] = "abc";
    const char b[] = "123456789";
    const char s21_b[] = "123456789";
    char *res = strncat(a, b, n);
    char *s21_res = s21_strncat(s21_a, s21_b, s21_n);
    ck_assert_str_eq(s21_res, res);
    ck_assert_str_eq(s21_a, a);
}
END_TEST

START_TEST(test3_s21_strncat_n_zero) {
    size_t n = 0;
    s21_size_t s21_n = 0;
    char a[10] = "abc";
    char s21_a[10] = "abc";
    const char b[] = "def";
    const char s21_b[] = "def";
    char *res = strncat(a, b, n);
    char *s21_res = s21_strncat(s21_a, s21_b, s21_n);
    ck_assert_str_eq(s21_res, res);
    ck_assert_str_eq(s21_a, a);
}
END_TEST

START_TEST(test4_s21_strncat_n_bigger_than_src) {
    size_t n = 10;
    s21_size_t s21_n = 10;
    char a[15] = "abc";
    char s21_a[15] = "abc";
    const char b[] = "def";
    const char s21_b[] = "def";
    char *res = strncat(a, b, n);
    char *s21_res = s21_strncat(s21_a, s21_b, s21_n);
    ck_assert_str_eq(s21_res, res);
    ck_assert_str_eq(s21_a, a);
}
END_TEST

START_TEST(test5_s21_strncat_embedded_null_in_src) {
    size_t n = 5;
    s21_size_t s21_n = 5;
    char a[10] = "abc";
    char s21_a[10] = "abc";
    const char b[] = "12\0345";
    const char s21_b[] = "12\0345";
    char *res = strncat(a, b, n);
    char *s21_res = s21_strncat(s21_a, s21_b, s21_n);
    ck_assert_str_eq(s21_res, res);
    ck_assert_str_eq(s21_a, a);
}
END_TEST

START_TEST(test6_s21_strncat_overlap) {
    size_t n = 5;
    s21_size_t s21_n = 5;
    char a[10] = "123456789";
    char s21_a[10] = "123456789";
    char res[10] = "";
    char s21_res[10] = "";
    strncat(res, a + 5, n);
    s21_strncat(s21_res, s21_a + 5, s21_n);
    ck_assert_str_eq(s21_res, res);
    ck_assert_str_eq(s21_a, a);
}
END_TEST

START_TEST(test7_s21_strncat_zero_length) {
    size_t n = 0;
    s21_size_t s21_n = 0;
    char a[10] = "abc";
    char s21_a[10] = "abc";
    const char b[] = "123";
    const char s21_b[] = "123";
    char *res = strncat(a, b, n);
    char *s21_res = s21_strncat(s21_a, s21_b, s21_n);
    ck_assert_str_eq(s21_res, res);
    ck_assert_str_eq(s21_a, a);
}
END_TEST

START_TEST(test8_s21_strncat_empty_src) {
    size_t n = 2;
    s21_size_t s21_n = 2;
    char a[10] = "abc";
    char s21_a[10] = "abc";
    const char b[] = "";
    const char s21_b[] = "";
    char *res = strncat(a, b, n);
    char *s21_res = s21_strncat(s21_a, s21_b, s21_n);
    ck_assert_str_eq(s21_res, res);
    ck_assert_str_eq(s21_a, a);
}
END_TEST

START_TEST(test9_s21_strncat_empty_dest) {
    size_t n = 3;
    s21_size_t s21_n = 3;
    char s21_a[10] = "";
    char a[10] = "";
    const char s21_b[] = "abc";
    const char b[] = "abc";
    char *res = strncat(a, b, n);
    char *s21_res = s21_strncat(s21_a, s21_b, s21_n);
    ck_assert_str_eq(s21_res, res);
    ck_assert_str_eq(s21_a, a);
}
END_TEST

START_TEST(test10_s21_strncat_partial_copy) {
    size_t n = 2;
    s21_size_t s21_n = 2;
    char a[10] = "abc";
    char s21_a[10] = "abc";
    const char b[] = "defgh";
    const char s21_b[] = "defgh";
    char *res = strncat(a, b, n);
    char *s21_res = s21_strncat(s21_a, s21_b, s21_n);
    ck_assert_str_eq(s21_res, res);
    ck_assert_str_eq(s21_a, a);
}
END_TEST

Suite *s21_strncat_suite(void) {
    Suite *s = suite_create("s21_strncat");
    TCase *tc = tcase_create("s21_strncat_core");
    tcase_add_test(tc, test1_s21_strncat_simple_case);
    tcase_add_test(tc, test2_s21_strncat_full_copy);
    tcase_add_test(tc, test3_s21_strncat_n_zero);
    tcase_add_test(tc, test4_s21_strncat_n_bigger_than_src);
    tcase_add_test(tc, test5_s21_strncat_embedded_null_in_src);
    tcase_add_test(tc, test6_s21_strncat_overlap);
    tcase_add_test(tc, test7_s21_strncat_zero_length);
    tcase_add_test(tc, test8_s21_strncat_empty_src);
    tcase_add_test(tc, test9_s21_strncat_empty_dest);
    tcase_add_test(tc, test10_s21_strncat_partial_copy);
    suite_add_tcase(s, tc);
    return s;
}

int s21_strncat_main() {
    int failed;
    SRunner *runner = srunner_create(s21_strncat_suite());
    srunner_run_all(runner, CK_NORMAL);
    failed = srunner_ntests_failed(runner);
    srunner_free(runner);
    return (failed == 0) ? 0 : failed;
}
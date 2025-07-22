#include <string.h>
#include <check.h>
#include "../src/s21_string.h"
// char *strstr(const char *haystack, const char *needle)
// Сравнение strstr и s21_strstr
START_TEST(test1_s21_strstr_empty_needle) {
    const char a[] = "hello";
    const char b[] = "";
    char *res = strstr(a, b);
    char *s21_res = s21_strstr(a, b);
    ck_assert_ptr_eq(s21_res, res);
}
END_TEST

START_TEST(test2_s21_strstr_match_at_beginning) {
    const char a[] = "apple";
    const char b[] = "app";
    char *res = strstr(a, b);
    char *s21_res = s21_strstr(a, b);
    ck_assert_ptr_eq(s21_res, res);
}
END_TEST

START_TEST(test3_s21_strstr_match_in_middle) {
    const char a[] = "banana";
    const char b[] = "nan";
    char *res = strstr(a, b);
    char *s21_res = s21_strstr(a, b);
    ck_assert_ptr_eq(s21_res, res);
}
END_TEST

START_TEST(test4_s21_strstr_match_at_end) {
    const char a[] = "orange";
    const char b[] = "ange";
    char *res = strstr(a, b);
    char *s21_res = s21_strstr(a, b);
    ck_assert_ptr_eq(s21_res, res);
}
END_TEST

START_TEST(test5_s21_strstr_no_match) {
    const char a[] = "abcdef";
    const char b[] = "xyz";
    char *res = strstr(a, b);
    char *s21_res = s21_strstr(a, b);
    ck_assert_ptr_eq(s21_res, res);
}
END_TEST

START_TEST(test6_s21_strstr_multiple_matches) {
    const char a[] = "abcdeffghi";
    const char b[] = "f";
    char *res = strstr(a, b);
    char *s21_res = s21_strstr(a, b);
    ck_assert_ptr_eq(s21_res, res);
}
END_TEST

START_TEST(test7_s21_strstr_needle_longer_than_haystack) {
    const char a[] = "abc";
    const char b[] = "abcdef";
    char *res = strstr(a, b);
    char *s21_res = s21_strstr(a, b);
    ck_assert_ptr_eq(s21_res, res);
}
END_TEST

START_TEST(test8_s21_strstr_one_char_not_found) {
    const char a[] = "abcdef";
    const char b[] = "z";
    char *res = strstr(a, b);
    char *s21_res = s21_strstr(a, b);
    ck_assert_ptr_eq(s21_res, res);
}
END_TEST

START_TEST(test9_s21_strstr_needle_beyond_haystack) {
    const char a[] = "hello wor";
    const char b[] = "lo world";
    char *res = strstr(a, b);
    char *s21_res = s21_strstr(a, b);
    ck_assert_ptr_eq(s21_res, res);
}
END_TEST

START_TEST(test10_s21_strstr_empty_haystack) {
    const char a[] = "";
    const char b[] = "abc";
    char *res = strstr(a, b);
    char *s21_res = s21_strstr(a, b);
    ck_assert_ptr_eq(s21_res, res);
}
END_TEST

START_TEST(test11_s21_strstr_empty_needle_and_haystack) {
    const char a[] = "";
    const char b[] = "";
    char *res = strstr(a, b);
    char *s21_res = s21_strstr(a, b);
    ck_assert_ptr_eq(s21_res, res);
}
END_TEST

START_TEST(test12_s21_strstr_partial_match) {
    const char a[] = "abcdefg";
    const char b[] = "cde";
    char *res = strstr(a, b);
    char *s21_res = s21_strstr(a, b);
    ck_assert_ptr_eq(s21_res, res);
}
END_TEST

Suite *s21_strstr_suite(void) {
    Suite *s = suite_create("s21_strstr");
    TCase *tc = tcase_create("s21_strstr_core");
    tcase_add_test(tc, test1_s21_strstr_empty_needle);
    tcase_add_test(tc, test2_s21_strstr_match_at_beginning);
    tcase_add_test(tc, test3_s21_strstr_match_in_middle);
    tcase_add_test(tc, test4_s21_strstr_match_at_end);
    tcase_add_test(tc, test5_s21_strstr_no_match);
    tcase_add_test(tc, test6_s21_strstr_multiple_matches);
    tcase_add_test(tc, test7_s21_strstr_needle_longer_than_haystack);
    tcase_add_test(tc, test8_s21_strstr_one_char_not_found);
    tcase_add_test(tc, test9_s21_strstr_needle_beyond_haystack);
    tcase_add_test(tc, test10_s21_strstr_empty_haystack);
    tcase_add_test(tc, test11_s21_strstr_empty_needle_and_haystack);
    tcase_add_test(tc, test12_s21_strstr_partial_match);
    suite_add_tcase(s, tc);
    return s;
}

int s21_strstr_main() {
    int failed;
    SRunner *runner = srunner_create(s21_strstr_suite());
    srunner_run_all(runner, CK_NORMAL);
    failed = srunner_ntests_failed(runner);
    srunner_free(runner);
    return (failed == 0) ? 0 : 1;
}
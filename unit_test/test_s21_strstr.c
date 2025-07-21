#include <string.h>
#include <check.h>
#include "../src/s21_string.h"
// char *strstr(const char *haystack, const char *needle)
// Сравнение strstr и s21_strstr
START_TEST(test1_s21_strstr_empty_needle) {
    const char haystack[] = "hello";
    const char needle[] = "";
    char *s21_result = s21_strstr(haystack, needle);
    char *result = strstr(haystack, needle);
    ck_assert_ptr_eq(s21_result, result);
}
END_TEST

START_TEST(test2_s21_strstr_match_at_beginning) {
    const char haystack[] = "apple";
    const char needle[] = "app";
    char *s21_result = s21_strstr(haystack, needle);
    char *result = strstr(haystack, needle);
    ck_assert_ptr_eq(s21_result, result);
}
END_TEST

START_TEST(test3_s21_strstr_match_in_middle) {
    const char haystack[] = "banana";
    const char needle[] = "nan";
    char *s21_result = s21_strstr(haystack, needle);
    char *result = strstr(haystack, needle);
    ck_assert_ptr_eq(s21_result, result);
}
END_TEST

START_TEST(test4_s21_strstr_match_at_end) {
    const char haystack[] = "orange";
    const char needle[] = "ange";
    char *s21_result = s21_strstr(haystack, needle);
    char *result = strstr(haystack, needle);
    ck_assert_ptr_eq(s21_result, result);
}
END_TEST

START_TEST(test5_s21_strstr_no_match) {
    const char haystack[] = "abcdef";
    const char needle[] = "xyz";
    char *s21_result = s21_strstr(haystack, needle);
    char *result = strstr(haystack, needle);
    ck_assert_ptr_eq(s21_result, result);
}
END_TEST

START_TEST(test6_s21_strstr_multiple_matches) {
    const char haystack[] = "abcdeffghi";
    const char needle[] = "f";
    char *s21_result = s21_strstr(haystack, needle);
    char *result = strstr(haystack, needle);
    ck_assert_ptr_eq(s21_result, result);
}
END_TEST

START_TEST(test7_s21_strstr_high_ascii_values) {
    const char haystack[] = "abc\xffdef\xffghi";
    const char needle[] = "\xffdef";
    char *s21_result = s21_strstr(haystack, needle);
    char *result = strstr(haystack, needle);
    ck_assert_ptr_eq(s21_result, result);
}
END_TEST

START_TEST(test8_s21_strstr_null_pointer) {
    char *s21_result = s21_strstr(NULL, "abc");
    char *result = strstr(NULL, "abc");
    ck_assert_ptr_eq(s21_result, result);
}
END_TEST

START_TEST(test9_s21_strstr_needle_beyond_haystack) {
    const char haystack[] = "hello wor";
    const char needle[] = "lo world";
    char *s21_result = s21_strstr(haystack, needle);
    char *result = strstr(haystack, needle);
    ck_assert_ptr_eq(s21_result, result);
}
Suite *s21_strstr_suite(void) {
    Suite *s = suite_create("s21_strstr");
    TCase *tc = tcase_create("s21_strstr_core");
    tcase_add_test(tc, test1_s21_strstr_empty_needle);
    tcase_add_test(tc, test2_s21_strstr_match_at_beginning);
    tcase_add_test(tc, test3_s21_strstr_match_in_middle);
    tcase_add_test(tc, test4_s21_strstr_match_at_end);
    tcase_add_test(tc, test5_s21_strstr_no_match);
    tcase_add_test(tc, test6_s21_strstr_multiple_matches);
    tcase_add_test(tc, test7_s21_strstr_high_ascii_values);
    tcase_add_test(tc, test8_s21_strstr_null_pointer);
    tcase_add_test(tc, test9_s21_strstr_needle_beyond_haystack);
    suite_add_tcase(s, tc);
    return s;
}

int main() {
    int failed;
    SRunner *runner = srunner_create(s21_strstr_suite());
    srunner_run_all(runner, CK_NORMAL);
    failed = srunner_ntests_failed(runner);
    srunner_free(runner);
    return (failed == 0) ? 0 : 1;
}
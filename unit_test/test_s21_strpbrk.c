#include <string.h>
#include <check.h>
#include "../src/s21_string.h"
// char *strpbrk(const char *s, const char *accept)
// Сравнение strpbrk и s21_strpbrk
START_TEST(test1_s21_strpbrk_match_at_beginning) {
    const char str1[] = "apple";
    const char str2[] = "a";
    char *s21_result = s21_strpbrk(str1, str2);
    char *result = strpbrk(str1, str2);
    ck_assert_ptr_eq(s21_result, result);
}
END_TEST

START_TEST(test2_s21_strpbrk_match_in_middle) {
    const char str1[] = "banana";
    const char str2[] = "n";
    char *s21_result = s21_strpbrk(str1, str2);
    char *result = strpbrk(str1, str2);
    ck_assert_ptr_eq(s21_result, result);
}
END_TEST

START_TEST(test3_s21_strpbrk_match_at_end) {
    const char str1[] = "orange";
    const char str2[] = "e";
    char *s21_result = s21_strpbrk(str1, str2);
    char *result = strpbrk(str1, str2);
    ck_assert_ptr_eq(s21_result, result);
}
END_TEST

START_TEST(test4_s21_strpbrk_no_match) {
    const char str1[] = "abcdef";
    const char str2[] = "xyz";
    char *s21_result = s21_strpbrk(str1, str2);
    char *result = strpbrk(str1, str2);
    ck_assert_ptr_eq(s21_result, result);
}
END_TEST

START_TEST(test5_s21_strpbrk_multiple_matches) {
    const char str1[] = "abcdeffghi";
    const char str2[] = "fed";
    char *s21_result = s21_strpbrk(str1, str2);
    char *result = strpbrk(str1, str2);
    ck_assert_ptr_eq(s21_result, result);
}
END_TEST

START_TEST(test6_s21_strpbrk_empty_str2) {
    const char str1[] = "abcdef";
    const char str2[] = "";
    char *s21_result = s21_strpbrk(str1, str2);
    char *result = strpbrk(str1, str2);
    ck_assert_ptr_eq(s21_result, result);
}
END_TEST

START_TEST(test7_s21_strpbrk_high_ascii_value) {
    const char str1[] = "abc\xffdef";
    const char str2[] = "\xff";
    char *s21_result = s21_strpbrk(str1, str2);
    char *result = strpbrk(str1, str2);
    ck_assert_ptr_eq(s21_result, result);
}
END_TEST

START_TEST(test8_s21_strpbrk_null_pointer) {
    char *s21_result = s21_strpbrk(NULL, "abc");
    char *result = strpbrk(NULL, "abc");
    ck_assert_ptr_eq(s21_result, result);
}
END_TEST

Suite *s21_strpbrk_suite(void) {
    Suite *s = suite_create("s21_strpbrk");
    TCase *tc = tcase_create("s21_strpbrk_core");
    tcase_add_test(tc, test1_s21_strpbrk_match_at_beginning);
    tcase_add_test(tc, test2_s21_strpbrk_match_in_middle);
    tcase_add_test(tc, test3_s21_strpbrk_match_at_end);
    tcase_add_test(tc, test4_s21_strpbrk_no_match);
    tcase_add_test(tc, test5_s21_strpbrk_multiple_matches);
    tcase_add_test(tc, test6_s21_strpbrk_empty_str2);
    tcase_add_test(tc, test7_s21_strpbrk_high_ascii_value);
    tcase_add_test(tc, test8_s21_strpbrk_null_pointer);
    suite_add_tcase(s, tc);
    return s;
}

int main() {
    int failed;
    SRunner *runner = srunner_create(s21_strpbrk_suite());
    srunner_run_all(runner, CK_NORMAL);
    failed = srunner_ntests_failed(runner);
    srunner_free(runner);
    return (failed == 0) ? 0 : 1;
}
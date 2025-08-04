#include <string.h>
#include <check.h>
#include "../src/s21_string.h"
// size_t strcspn(const char *s1, const char *reject)
START_TEST(test1_s21_strcspn_no_match) {
    const char a[] = "abcdef";
    const char b[] = "xyz";
    size_t res = strcspn(a, b);
    s21_size_t s21_res = s21_strcspn(a, b);
    ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(test2_s21_strcspn_match_at_beginning) {
    const char a[] = "abcde";
    const char b[] = "a";
    size_t res = strcspn(a, b);
    s21_size_t s21_res = s21_strcspn(a, b);
    ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(test3_s21_strcspn_match_in_middle) {
    const char a[] = "hello world";
    const char b[] = "w";
    size_t res = strcspn(a, b);
    s21_size_t s21_res = s21_strcspn(a, b);
    ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(test4_s21_strcspn_match_at_end) {
    const char a[] = "test\0";
    const char b[] = "\0";
    size_t res = strcspn(a, b);
    s21_size_t s21_res = s21_strcspn(a, b);
    ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(test5_s21_strcspn_multiple_matches) {
    const char a[] = "abc123def";
    const char b[] = "123";
    size_t res = strcspn(a, b);
    s21_size_t s21_res = s21_strcspn(a, b);
    ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(test6_s21_strcspn_empty_reject) {
    const char a[] = "abcdef";
    const char b[] = "";
    size_t res = strcspn(a, b);
    s21_size_t s21_res = s21_strcspn(a, b);
    ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(test7_s21_strcspn_first_char_match) {
    const char a[] = "abcde";
    const char b[] = "a";
    size_t res = strcspn(a, b);
    s21_size_t s21_res = s21_strcspn(a, b);
    ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(test8_s21_strcspn_all_match) {
    const char a[] = "abc";
    const char b[] = "abc";
    size_t res = strcspn(a, b);
    s21_size_t s21_res = s21_strcspn(a, b);
    ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(test9_s21_strcspn_empty_s) {
    const char a[] = "";
    const char b[] = "abc";
    size_t res = strcspn(a, b);
    s21_size_t s21_res = s21_strcspn(a, b);
    ck_assert_int_eq(s21_res, res);
}
END_TEST

Suite *s21_strcspn_suite(void) {
    Suite *s = suite_create("s21_strcspn");
    TCase *tc = tcase_create("s21_strcspn_core");
    tcase_add_test(tc, test1_s21_strcspn_no_match);
    tcase_add_test(tc, test2_s21_strcspn_match_at_beginning);
    tcase_add_test(tc, test3_s21_strcspn_match_in_middle);
    tcase_add_test(tc, test4_s21_strcspn_match_at_end);
    tcase_add_test(tc, test5_s21_strcspn_multiple_matches);
    tcase_add_test(tc, test6_s21_strcspn_empty_reject);
    tcase_add_test(tc, test7_s21_strcspn_first_char_match);
    tcase_add_test(tc, test8_s21_strcspn_all_match);
    tcase_add_test(tc, test9_s21_strcspn_empty_s);
    suite_add_tcase(s, tc);
    return s;
}

int s21_strcspn_main() {
    int failed;
    SRunner *runner = srunner_create(s21_strcspn_suite());
    srunner_run_all(runner, CK_NORMAL);
    failed = srunner_ntests_failed(runner);
    srunner_free(runner);
    return (failed == 0) ? 0 : failed;
}
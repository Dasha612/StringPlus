#include <string.h>
#include <check.h>
#include "../src/s21_string.h"
// size_t strcspn(const char *s1, const char *reject)
// Сравнение strcspn и s21_strcspn
START_TEST(test1_s21_strcspn_no_match) {
    const char str1[] = "abcdef";
    const char str2[] = "xyz";
    size_t s21_result = s21_strcspn(str1, str2);
    size_t result = strcspn(str1, str2);
    ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(test2_s21_strcspn_match_at_beginning) {
    const char str1[] = "abcde";
    const char str2[] = "a";
    size_t s21_result = s21_strcspn(str1, str2);
    size_t result = strcspn(str1, str2);
    ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(test3_s21_strcspn_match_in_middle) {
    const char str1[] = "hello world";
    const char str2[] = "w";
    size_t s21_result = s21_strcspn(str1, str2);
    size_t result = strcspn(str1, str2);
    ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(test4_s21_strcspn_match_at_end) {
    const char str1[] = "test\0";
    const char str2[] = "\0";
    size_t s21_result = s21_strcspn(str1, str2);
    size_t result = strcspn(str1, str2);
    ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(test5_s21_strcspn_multiple_matches) {
    const char str1[] = "abc123def";
    const char str2[] = "123";
    size_t s21_result = s21_strcspn(str1, str2);
    size_t result = strcspn(str1, str2);
    ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(test6_s21_strcspn_empty_str2) {
    const char str1[] = "abcdef";
    const char str2[] = "";
    size_t s21_result = s21_strcspn(str1, str2);
    size_t result = strcspn(str1, str2);
    ck_assert_int_eq(s21_result, result);
}
END_TEST

// START_TEST(test7_s21_strcspn_high_ascii_value) {
//     const char str1[] = "abc\xffdef";
//     const char str2[] = "\xff";
//     size_t s21_result = s21_strcspn(str1, str2);
//     size_t result = strcspn(str1, str2);
//     ck_assert_int_eq(s21_result, result);
// }
// END_TEST

// START_TEST(test8_s21_strcspn_null_pointer) {
//     size_t s21_result = s21_strcspn(NULL, "abc");
//     size_t result = strcspn(NULL, "abc");
//     ck_assert_int_eq(s21_result, result);
// }
// END_TEST

Suite *s21_strcspn_suite(void) {
    Suite *s = suite_create("s21_strcspn");
    TCase *tc = tcase_create("s21_strcspn_core");
    tcase_add_test(tc, test1_s21_strcspn_no_match);
    tcase_add_test(tc, test2_s21_strcspn_match_at_beginning);
    tcase_add_test(tc, test3_s21_strcspn_match_in_middle);
    tcase_add_test(tc, test4_s21_strcspn_match_at_end);
    tcase_add_test(tc, test5_s21_strcspn_multiple_matches);
    tcase_add_test(tc, test6_s21_strcspn_empty_str2);
    // tcase_add_test(tc, test7_s21_strcspn_high_ascii_value);
    // tcase_add_test(tc, test8_s21_strcspn_null_pointer);
    suite_add_tcase(s, tc);
    return s;
}

int s21_strcspn_main() {
    int failed;
    SRunner *runner = srunner_create(s21_strcspn_suite());
    srunner_run_all(runner, CK_NORMAL);
    failed = srunner_ntests_failed(runner);
    srunner_free(runner);
    return (failed == 0) ? 0 : 1;
}
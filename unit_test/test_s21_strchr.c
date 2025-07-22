#include <string.h>
#include <check.h>
#include "../src/s21_string.h"
// char *strchr(const char *s, int c)
// Сравнение strchr и s21_strchr

START_TEST(test1_s21_strchr_not_found) {
    const char str[] = "hello";
    char *s21_result = s21_strchr(str, 'x');
    char *result = strchr(str, 'x');
    ck_assert_ptr_eq(s21_result, result);
}
END_TEST

START_TEST(test2_s21_strchr_at_beginning) {
    const char str[] = "apple";
    char *s21_result = s21_strchr(str, 'a');
    char *result = strchr(str, 'a');
    ck_assert_ptr_eq(s21_result, result);
}
END_TEST

START_TEST(test3_s21_strchr_in_middle) {
    const char str[] = "banana";
    char *s21_result = s21_strchr(str, 'n');
    char *result = strchr(str, 'n');
    ck_assert_ptr_eq(s21_result, result);
}
END_TEST

START_TEST(test4_s21_strchr_at_end) {
    const char str[] = "orange";
    char *s21_result = s21_strchr(str, 'e');
    char *result = strchr(str, 'e');
    ck_assert_ptr_eq(s21_result, result);
}
END_TEST

START_TEST(test5_s21_strchr_search_for_null) {
    const char str[] = "test\0end";
    char *s21_result = s21_strchr(str, '\0');
    char *result = strchr(str, '\0');
    ck_assert_ptr_eq(s21_result, result);
}
END_TEST

START_TEST(test6_s21_strchr_multiple_occurrences) {
    const char str[] = "abcdeffghi";
    char *s21_result = s21_strchr(str, 'f');
    char *result = strchr(str, 'f');
    ck_assert_ptr_eq(s21_result, result);
}
END_TEST

// START_TEST(test7_s21_strchr_high_ascii_value) {
//     const char str[] = "abc\xffdef";
//     char *s21_result = s21_strchr(str, -1); // -1 → 0xFF
//     char *result = strchr(str, -1);
//     ck_assert_ptr_eq(s21_result, result);
// }
// END_TEST

// START_TEST(test8_s21_strchr_null_pointer) {
//     char *s21_result = s21_strchr(NULL, 'x');
//     char *result = strchr(NULL, 'x');
//     ck_assert_ptr_eq(s21_result, result);
// }
// END_TEST

Suite *s21_strchr_suite(void) {
    Suite *s = suite_create("s21_strchr");
    TCase *tc = tcase_create("s21_strchr_core");
    tcase_add_test(tc, test1_s21_strchr_not_found);
    tcase_add_test(tc, test2_s21_strchr_at_beginning);
    tcase_add_test(tc, test3_s21_strchr_in_middle);
    tcase_add_test(tc, test4_s21_strchr_at_end);
    tcase_add_test(tc, test5_s21_strchr_search_for_null);
    tcase_add_test(tc, test6_s21_strchr_multiple_occurrences);
    // tcase_add_test(tc, test7_s21_strchr_high_ascii_value);
    // tcase_add_test(tc, test8_s21_strchr_null_pointer);
    suite_add_tcase(s, tc);
    return s;
}

int s21_strchr_main() {
    int failed;
    SRunner *runner = srunner_create(s21_strchr_suite());
    srunner_run_all(runner, CK_NORMAL);
    failed = srunner_ntests_failed(runner);
    srunner_free(runner);
    return (failed == 0) ? 0 : 1;
}
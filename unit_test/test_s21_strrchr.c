#include <string.h>
#include <check.h>
#include "../src/s21_string.h"
// char *strrchr(const char *s, int c)
// Сравнение strrchr и s21_strrchr
START_TEST(test1_s21_strrchr_not_found) {
    const char str[] = "hello";
    char *s21_result = s21_strrchr(str, 'x');
    char *result = strrchr(str, 'x');
    ck_assert_ptr_eq(s21_result, result);
}
END_TEST

START_TEST(test2_s21_strrchr_at_beginning) {
    const char str[] = "apple";
    char *s21_result = s21_strrchr(str, 'a');
    char *result = strrchr(str, 'a');
    ck_assert_ptr_eq(s21_result, result);
}
END_TEST

START_TEST(test3_s21_strrchr_in_middle) {
    const char str[] = "banana";
    char *s21_result = s21_strrchr(str, 'n');
    char *result = strrchr(str, 'n');
    ck_assert_ptr_eq(s21_result, result);
}
END_TEST

START_TEST(test4_s21_strrchr_at_end) {
    const char str[] = "orange";
    char *s21_result = s21_strrchr(str, 'e');
    char *result = strrchr(str, 'e');
    ck_assert_ptr_eq(s21_result, result);
}
END_TEST

START_TEST(test5_s21_strrchr_search_for_null) {
    const char str[] = "test\0end";
    char *s21_result = s21_strrchr(str, '\0');
    char *result = strrchr(str, '\0');
    ck_assert_ptr_eq(s21_result, result);
}
END_TEST

START_TEST(test6_s21_strrchr_multiple_occurrences) {
    const char str[] = "abcdeffghi";
    char *s21_result = s21_strrchr(str, 'f');
    char *result = strrchr(str, 'f');
    ck_assert_ptr_eq(s21_result, result);
}
END_TEST

// START_TEST(test7_s21_strrchr_high_ascii_value) {
//     const char str[] = "abc\xffdef\xffghi";
//     char *s21_result = s21_strrchr(str, '\xff');
//     char *result = strrchr(str, '\xff');
//     ck_assert_ptr_eq(s21_result, result);
// }
// END_TEST

// START_TEST(test8_s21_strrchr_null_pointer) {
//     char *s21_result = s21_strrchr(NULL, 'x');
//     char *result = strrchr(NULL, 'x');
//     ck_assert_ptr_eq(s21_result, result);
// }
// END_TEST

Suite *s21_strrchr_suite(void) {
    Suite *s = suite_create("s21_strrchr");
    TCase *tc = tcase_create("s21_strrchr_core");
    tcase_add_test(tc, test1_s21_strrchr_not_found);
    tcase_add_test(tc, test2_s21_strrchr_at_beginning);
    tcase_add_test(tc, test3_s21_strrchr_in_middle);
    tcase_add_test(tc, test4_s21_strrchr_at_end);
    tcase_add_test(tc, test5_s21_strrchr_search_for_null);
    tcase_add_test(tc, test6_s21_strrchr_multiple_occurrences);
    // tcase_add_test(tc, test7_s21_strrchr_high_ascii_value);
    // tcase_add_test(tc, test8_s21_strrchr_null_pointer);
    suite_add_tcase(s, tc);
    return s;
}

int s21_strrchr_main() {
    int failed;
    SRunner *runner = srunner_create(s21_strrchr_suite());
    srunner_run_all(runner, CK_NORMAL);
    failed = srunner_ntests_failed(runner);
    srunner_free(runner);
    return (failed == 0) ? 0 : 1;
}
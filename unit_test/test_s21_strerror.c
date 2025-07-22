#include <string.h>
#include <check.h>
#include "../src/s21_string.h"
// char *strerror(int errnum)
// Сравнение strerror и s21_strerror
START_TEST(test1_s21_strerror_zero_code) {
    char *s21_result = s21_strerror(0);
    char *result = strerror(0);
    ck_assert_str_eq(s21_result, result);
}
END_TEST

START_TEST(test2_s21_strerror_one_code) {
    char *s21_result = s21_strerror(1);
    char *result = strerror(1);
    ck_assert_str_eq(s21_result, result);
}
END_TEST

START_TEST(test3_s21_strerror_two_code) {
    char *s21_result = s21_strerror(1);
    char *result = strerror(1);
    ck_assert_str_eq(s21_result, result);
}

START_TEST(test4_s21_strerror_three_code) {
    char *s21_result = s21_strerror(2);
    char *result = strerror(2);
    ck_assert_str_eq(s21_result, result);
}
END_TEST

START_TEST(test5_s21_strerror_unknown_code) {
    char *s21_result = s21_strerror(999);
    char *result = strerror(999);
    ck_assert_str_eq(s21_result, result);
}
END_TEST

START_TEST(test6_s21_strerror_negative_code) {
    char *s21_result = s21_strerror(-1);
    char *result = strerror(-1);
    ck_assert_str_eq(s21_result, result);
}
END_TEST

START_TEST(test7_s21_strerror_four_code) {
    char *s21_result = s21_strerror(3);
    char *result = strerror(3);
    ck_assert_str_eq(s21_result, result);
}
END_TEST

START_TEST(test8_s21_strerror_five_code) {
    char *s21_result = s21_strerror(4);
    char *result = strerror(4);
    ck_assert_str_eq(s21_result, result);
}
END_TEST

Suite *s21_strerror_suite(void) {
    Suite *s = suite_create("s21_strerror");
    TCase *tc = tcase_create("s21_strerror_core");
    tcase_add_test(tc, test1_s21_strerror_zero_code);
    tcase_add_test(tc, test2_s21_strerror_one_code);
    tcase_add_test(tc, test3_s21_strerror_two_code);
    tcase_add_test(tc, test4_s21_strerror_three_code);
    tcase_add_test(tc, test5_s21_strerror_unknown_code);
    tcase_add_test(tc, test6_s21_strerror_negative_code);
    tcase_add_test(tc, test7_s21_strerror_four_code);
    tcase_add_test(tc, test8_s21_strerror_five_code);
    suite_add_tcase(s, tc);
    return s;
}

int s21_strerror_main() {
    int failed;
    SRunner *runner = srunner_create(s21_strerror_suite());
    srunner_run_all(runner, CK_NORMAL);
    failed = srunner_ntests_failed(runner);
    srunner_free(runner);
    return (failed == 0) ? 0 : 1;
}
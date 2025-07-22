#include <string.h>
#include <check.h>
#include "../src/s21_string.h"
// char *strerror(int errnum)
// Сравнение strerror и s21_strerror
START_TEST(test1_s21_strerror_zero_code) {
    int errnum = 0;
    char *s21_res = s21_strerror(errnum);
    char *res = strerror(errnum);
    ck_assert_str_eq(s21_res, res);
}
END_TEST

START_TEST(test2_s21_strerror_one_code) {
    int errnum = 1;
    char *s21_res = s21_strerror(errnum);
    char *res = strerror(errnum);
    ck_assert_str_eq(s21_res, res);
}
END_TEST

START_TEST(test3_s21_strerror_two_code) {
    int errnum = 2;
    char *s21_res = s21_strerror(errnum);
    char *res = strerror(errnum);
    ck_assert_str_eq(s21_res, res);
}

START_TEST(test4_s21_strerror_three_code) {
    int errnum = 3;
    char *s21_res = s21_strerror(errnum);
    char *res = strerror(errnum);
    ck_assert_str_eq(s21_res, res);
}
END_TEST

START_TEST(test5_s21_strerror_unknown_code) {
    int errnum = 999;
    char *s21_res = s21_strerror(errnum);
    char *res = strerror(errnum);
    ck_assert_str_eq(s21_res, res);
}
END_TEST

START_TEST(test6_s21_strerror_negative_code) {
    int errnum = -1;
    char *s21_res = s21_strerror(errnum);
    char *res = strerror(errnum);
    ck_assert_str_eq(s21_res, res);
}
END_TEST

START_TEST(test7_s21_strerror_four_code) {
    int errnum = 4;
    char *s21_res = s21_strerror(errnum);
    char *res = strerror(errnum);
    ck_assert_str_eq(s21_res, res);
}
END_TEST

START_TEST(test8_s21_strerror_five_code) {
    int errnum = 5;
    char *s21_res = s21_strerror(errnum);
    char *res = strerror(errnum);
    ck_assert_str_eq(s21_res, res);
}
END_TEST

START_TEST(test9_s21_strerror_large_positive) {
    int errnum = 10000;
    char *s21_res = s21_strerror(errnum);
    char *res = strerror(errnum);
    ck_assert_str_eq(s21_res, res);
}
END_TEST

START_TEST(test10_s21_strerror_large_negative) {
    int errnum = -10000;
    char *s21_res = s21_strerror(errnum);
    char *res = strerror(errnum);
    ck_assert_str_eq(s21_res, res);
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
    tcase_add_test(tc, test9_s21_strerror_large_positive);
    tcase_add_test(tc, test10_s21_strerror_large_negative);
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
#include <string.h>
#include <check.h>
#include "../src/s21_string.h"
// char *memchr(const char *s, int c, size_t n) {
// Сравнение memchr и s21_memchr
START_TEST(test1_s21_memchr) {
    char *s = "Hello, world!";
    char *result = memchr(s, 'w', 13);
    char *s21_result = s21_memchr(s, 'w', 13);
    ck_assert_ptr_eq(result, s21_result);
}
END_TEST
/*
START_TEST(test2_s21_memchr) {
    // s21_code here
    // code here
    ck_assert_ptr_eq(result, s21_result);
}
END_TEST

START_TEST(test3_s21_memchr) {
    // s21_code here
    // code here
    ck_assert_ptr_eq(result, s21_result);
}
END_TEST

START_TEST(test4_s21_memchr) {
    // s21_code here
    // code here
    ck_assert_ptr_eq(result, s21_result);
}
END_TEST

START_TEST(test5_s21_memchr) {
    // s21_code here
    // code here
    ck_assert_ptr_eq(result, s21_result);
}
END_TEST

START_TEST(test6_s21_memchr) {
    // s21_code here
    // code here
    ck_assert_ptr_eq(result, s21_result);
}
END_TEST

START_TEST(test7_s21_memchr) {
    // s21_code here
    // code here
    ck_assert_ptr_eq(result, s21_result);
}
END_TEST

START_TEST(test8_s21_memchr) {
    // s21_code here
    // code here
    ck_assert_ptr_eq(result, s21_result);
}
END_TEST
*/

Suite *s21_memchr_suite(void) {
    Suite *s = suite_create("s21_memchr");
    TCase *tc = tcase_create("s21_memchr_core");
    tcase_add_test(tc, test1_s21_memchr);
    // tcase_add_test(tc, test2_s21_memchr);
    // tcase_add_test(tc, test3_s21_memchr);
    // tcase_add_test(tc, test4_s21_memchr);
    // tcase_add_test(tc, test5_s21_memchr);
    // tcase_add_test(tc, test6_s21_memchr);
    // tcase_add_test(tc, test7_s21_memchr);
    // tcase_add_test(tc, test8_s21_memchr);
    suite_add_tcase(s, tc);
    return s;
}
int main() {
    int failed;
    SRunner *runner = srunner_create(s21_memchr_suite());
    srunner_run_all(runner, CK_NORMAL);
    failed = srunner_ntests_failed(runner);
    srunner_free(runner);
    return (failed == 0) ? 0 : 1;
}
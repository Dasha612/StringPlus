#include <string.h>
#include <check.h>
#include "../src/s21_string.h"
// size_t strlen(const char *s)
START_TEST(test1_s21_strlen_empty) {
    const char s[] = "";
    size_t res = strlen(s);
    s21_size_t s21_res = s21_strlen(s);
    ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(test2_s21_strlen_one_char) {
    const char s[] = "a";
    size_t res = strlen(s);
    s21_size_t s21_res = s21_strlen(s);
    ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(test3_s21_strlen_normal) {
    const char s[] = "Hello, world!";
    size_t res = strlen(s);
    s21_size_t s21_res = s21_strlen(s);
    ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(test4_s21_strlen_spaces) {
    const char s[] = "   ";
    size_t res = strlen(s);
    s21_size_t s21_res = s21_strlen(s);
    ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(test5_s21_strlen_embedded_null) {
    const char s[] = "abc\0def";
    size_t res = strlen(s);
    s21_size_t s21_res = s21_strlen(s);
    ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(test6_s21_strlen_long_string) {
    char s[1001];
    for (int i = 0; i < 1000; i++) {
        s[i] = 'a';
    }
    s[1000] = '\0';
    size_t res = strlen(s);
    s21_size_t s21_res = s21_strlen(s);
    ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(test7_s21_strlen_unicode) {
    const char s[] = "привет"; // UTF-8
    size_t res = strlen(s);
    s21_size_t s21_res = s21_strlen(s);
    ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(test8_s21_strlen_all_spaces) {
    const char s[] = "     ";
    size_t res = strlen(s);
    s21_size_t s21_res = s21_strlen(s);
    ck_assert_int_eq(s21_res, res);
}
END_TEST

START_TEST(test9_s21_strlen_all_same) {
    const char str[] = "aaaaaa";
    size_t res = strlen(str);
    s21_size_t s21_res = s21_strlen(str);
    ck_assert_int_eq(s21_res, res);
}
END_TEST

Suite* s21_strlen_suite(void) {
    Suite *s = suite_create("s21_strlen");
    TCase *tc = tcase_create("s21_strlen_core");
    tcase_add_test(tc, test1_s21_strlen_empty);
    tcase_add_test(tc, test2_s21_strlen_one_char);
    tcase_add_test(tc, test3_s21_strlen_normal);
    tcase_add_test(tc, test4_s21_strlen_spaces);
    tcase_add_test(tc, test5_s21_strlen_embedded_null);
    tcase_add_test(tc, test6_s21_strlen_long_string);
    tcase_add_test(tc, test7_s21_strlen_unicode);
    tcase_add_test(tc, test8_s21_strlen_all_spaces);
    tcase_add_test(tc, test9_s21_strlen_all_same);
    suite_add_tcase(s, tc);
    return s;
}

int s21_strlen_main() {
    int failed;
    SRunner *runner = srunner_create(s21_strlen_suite());
    srunner_run_all(runner, CK_NORMAL);
    failed = srunner_ntests_failed(runner);
    srunner_free(runner);
    return (failed == 0) ? 0 : failed;
}
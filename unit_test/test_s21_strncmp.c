#include <string.h>
#include <check.h>
#include "../src/s21_string.h"
// int strncmp(const char *s1, const char *s2, size_t n)
// Сравнение strncmp и s21_strncmp
START_TEST(test1_s21_strncmp_equal_strings) {
    const char str1[] = "hello";
    const char str2[] = "hello";
    int s21_result = s21_strncmp(str1, str2, 5);
    int result = strncmp(str1, str2, 5);
    ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(test2_s21_strncmp_different_first_char) {
    const char str1[] = "apple";
    const char str2[] = "apply";
    int s21_result = s21_strncmp(str1, str2, 5);
    int result = strncmp(str1, str2, 5);
    ck_assert_int_eq(s21_result, result);
}
END_TEST

// START_TEST(test3_s21_strncmp_null_pointer_in_one_string) {
//     const char str1[] = "test";
//     int s21_result = s21_strncmp(str1, NULL, 4);
//     int result = strncmp(str1, NULL, 4);
//     ck_assert_int_eq(s21_result, result);
// }
// END_TEST

START_TEST(test4_s21_strncmp_embedded_null) {
    const char str1[] = "abc\0def";
    const char str2[] = "abc\0ghi";
    int s21_result = s21_strncmp(str1, str2, 6);
    int result = strncmp(str1, str2, 6);
    ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(test5_s21_strncmp_zero_length) {
    const char str1[] = "test";
    const char str2[] = "test123";
    int s21_result = s21_strncmp(str1, str2, 0);
    int result = strncmp(str1, str2, 0);
    ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(test6_s21_strncmp_same_prefix_longer_string) {
    const char str1[] = "hello";
    const char str2[] = "hellolonger";
    int s21_result = s21_strncmp(str1, str2, 5);
    int result = strncmp(str1, str2, 5);
    ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(test7_s21_strncmp_high_ascii_values) {
    const char str1[] = "\xff\xfe";
    const char str2[] = "\xfe\xff";
    int s21_result = s21_strncmp(str1, str2, 2);
    int result = strncmp(str1, str2, 2);
    ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(test8_s21_strncmp_buffer_overflow) {
    const char str1[] = "abcdefghij";
    const char str2[] = "abcdexxxxxx";
    int s21_result = s21_strncmp(str1, str2, 100); // Больше, чем длина обеих строк
    int result = strncmp(str1, str2, 100);
    ck_assert_int_eq(s21_result, result);
}
END_TEST

Suite *s21_strncmp_suite(void) {
    Suite *s = suite_create("s21_strncmp");
    TCase *tc = tcase_create("s21_strncmp_core");
    tcase_add_test(tc, test1_s21_strncmp_equal_strings);
    tcase_add_test(tc, test2_s21_strncmp_different_first_char);
    // tcase_add_test(tc, test3_s21_strncmp_null_pointer_in_one_string);
    tcase_add_test(tc, test4_s21_strncmp_embedded_null);
    tcase_add_test(tc, test5_s21_strncmp_zero_length);
    tcase_add_test(tc, test6_s21_strncmp_same_prefix_longer_string);
    tcase_add_test(tc, test7_s21_strncmp_high_ascii_values);
    tcase_add_test(tc, test8_s21_strncmp_buffer_overflow);
    suite_add_tcase(s, tc);
    return s;
}

int s21_strncmp_main() {
    int failed;
    SRunner *runner = srunner_create(s21_strncmp_suite());
    srunner_run_all(runner, CK_NORMAL);
    failed = srunner_ntests_failed(runner);
    srunner_free(runner);
    return (failed == 0) ? 0 : 1;
}
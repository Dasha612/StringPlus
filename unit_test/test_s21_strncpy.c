#include <string.h>
#include <check.h>
#include "../src/s21_string.h"
// char *strncpy(char *dest, const char *src, size_t n)
// Сравнение strncpy и s21_strncpy
START_TEST(test1_s21_strncpy_simple_copy) {
    char dest[10] = {0};
    char s21_dest[10] = {0};
    const char src[] = "hello";
    const char s21_src[] = "hello";
    char *s21_result = s21_strncpy(s21_dest, s21_src, 5);
    char *result = strncpy(dest, src, 5);
    ck_assert_ptr_eq(s21_result, result);
    ck_assert_str_eq(s21_dest, dest);
}
END_TEST

START_TEST(test2_s21_strncpy_full_copy) {
    char dest[10] = {0};
    char s21_dest[10] = {0};
    const char src[] = "abcdefg";
    const char s21_src[] = "abcdefg";
    char *s21_result = s21_strncpy(s21_dest, s21_src, 7);
    char *result = strncpy(dest, src, 7);
    ck_assert_ptr_eq(s21_result, result);
    ck_assert_str_eq(dest, "abcdefg");
}
END_TEST

// START_TEST(test3_s21_strncpy_null_dest) {
//     char *s21_result = s21_strncpy(NULL, "test", 4);
//     char *result = strncpy(NULL, "test", 4);
//     ck_assert_ptr_eq(s21_result, result);
// }
// END_TEST

// START_TEST(test4_s21_strncpy_null_src) {
//     char dest[10] = "abc";
//     char *s21_result = s21_strncpy(dest, NULL, 4);
//     char *result = strncpy(dest, NULL, 4);
//     ck_assert_ptr_eq(s21_result, result);
//     ck_assert_str_eq(dest, "abc");
// }
// END_TEST

START_TEST(test5_s21_strncpy_embedded_null_in_src) {
    char dest[10] = {0};
    char s21_dest[10] = {0};
    const char src[] = "12\0345";
    const char s21_src[] = "12\0345";
    char *s21_result = s21_strncpy(s21_dest, s21_src, 5);
    char *result = strncpy(dest, src, 5);
    ck_assert_ptr_eq(s21_result, result);
    ck_assert_str_eq(s21_dest, dest);
}
END_TEST

START_TEST(test6_s21_strncpy_overlap) {
    char buffer[10] = "abcdefghij";
    char s21_buffer[10] = "abcdefghij";
    char *s21_result = s21_strncpy(s21_buffer + 5, s21_buffer, 5);
    char *result = strncpy(buffer + 5, buffer, 5);
    ck_assert_ptr_eq(s21_result, result);
    ck_assert_str_eq(s21_buffer, buffer);
}
END_TEST

// START_TEST(test7_s21_strncpy_zero_length) {
//     char dest[10] = "abc";
//     char s21_dest[10] = "abc";
//     char *s21_result = s21_strncpy(s21_dest, "123", 0);
//     char *result = strncpy(dest, "123", 0);
//     ck_assert_ptr_eq(s21_result, result);
//     ck_assert_str_eq(s21_dest, dest);
// }
// END_TEST

// START_TEST(test8_s21_strncpy_buffer_overflow) {
//     char dest[3] = {0}; // Буфер всего на 3 символа
//     char s21_dest[3] = {0};
//     char *s21_result = s21_strncpy(s21_dest, "123456", 6);
//     char *result = strncpy(dest, "123456", 6);
//     ck_assert_ptr_eq(s21_result, result);
//     ck_assert_str_eq(s21_dest, dest);
// }
// END_TEST

Suite *s21_strncpy_suite(void) {
    Suite *s = suite_create("s21_strncpy");
    TCase *tc = tcase_create("s21_strncpy_core");
    tcase_add_test(tc, test1_s21_strncpy_simple_copy);
    tcase_add_test(tc, test2_s21_strncpy_full_copy);
    // tcase_add_test(tc, test3_s21_strncpy_null_dest);
    // tcase_add_test(tc, test4_s21_strncpy_null_src);
    tcase_add_test(tc, test5_s21_strncpy_embedded_null_in_src);
    tcase_add_test(tc, test6_s21_strncpy_overlap);
    // tcase_add_test(tc, test7_s21_strncpy_zero_length);
    // tcase_add_test(tc, test8_s21_strncpy_buffer_overflow);
    suite_add_tcase(s, tc);
    return s;
}

int s21_strncpy_main() {
    int failed;
    SRunner *runner = srunner_create(s21_strncpy_suite());
    srunner_run_all(runner, CK_NORMAL);
    failed = srunner_ntests_failed(runner);
    srunner_free(runner);
    return (failed == 0) ? 0 : 1;
}
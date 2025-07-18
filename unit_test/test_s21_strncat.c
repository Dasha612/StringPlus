#include <string.h>
#include <check.h>
#include "../src/s21_string.h"
// char* strncat(char *dest, const char *src, size_t n)
// Сравнение strncat и s21_strncat
START_TEST(test1_s21_strncat_simple_case) {
    char s21_dest[10] = "abc";
    char dest[10] = "abc";
    const char s21_src[] = "def";
    const char src[] = "def";
    char *s21_result = s21_strncat(s21_dest, s21_src, 3);
    char *result = strncat(dest, src, 3);
    ck_assert_ptr_eq(s21_result, result);
    ck_assert_str_eq(s21_dest, dest);
}
END_TEST

START_TEST(test2_s21_strncat_full_copy) {
    char s21_dest[10] = "abc";
    char dest[10] = "abc";
    const char s21_src[] = "123456789";
    const char src[] = "123456789";
    char *s21_result = s21_strncat(s21_dest, s21_src, 6);
    char *result = strncat(dest, src, 6);
    ck_assert_ptr_eq(s21_result, result);
    ck_assert_str_eq(s21_dest, dest);
}
END_TEST

START_TEST(test3_s21_strncat_null_dest) {
    void *s21_dest = NULL;
    void *dest = NULL;
    const char s21_src[] = "test";
    const char src[] = "test";
    char *s21_result = s21_strncat(s21_dest, s21_src, 4);
    char *result = strncat(dest, src, 4);
    ck_assert_ptr_eq(s21_result, result);
    ck_assert_str_eq(s21_dest, dest);
}
END_TEST

START_TEST(test4_s21_strncat_null_src) {
    char s21_dest[10] = "abc";
    char dest[10] = "abc";
    char *s21_result = s21_strncat(s21_dest, NULL, 4);
    char *result = strncat(dest, NULL, 4);
    ck_assert_ptr_eq(s21_result, result);
    ck_assert_str_eq(s21_dest, dest);
}
END_TEST

START_TEST(test5_s21_strncat_embedded_null_in_src) {
    char s21_dest[10] = "abc";
    char dest[10] = "abc";
    const char s21_src[] = "12\0345";
    const char src[] = "12\0345";
    char *s21_result = s21_strncat(s21_dest, s21_src, 5);
    char *result = strncat(dest, src, 5);
    ck_assert_ptr_eq(s21_result, result);
    ck_assert_str_eq(s21_dest, dest);
}
END_TEST

START_TEST(test6_s21_strncat_overlap) {
    char s21_buffer[10] = "abcdefghij";
    char buffer[10] = "abcdefghij";
    char *s21_result = s21_strncat(s21_buffer + 5, s21_buffer, 5);
    char *result = strncat(buffer + 5, buffer, 5);
    ck_assert_ptr_eq(s21_result, result);
    ck_assert_str_eq(s21_buffer, buffer);
}
END_TEST

START_TEST(test7_s21_strncat_zero_length) {
    char s21_dest[10] = "abc";
    char dest[10] = "abc";
    char *s21_result = s21_strncat(s21_dest, "123", 0);
    char *result = strncat(dest, "123", 0);
    ck_assert_ptr_eq(s21_result, result);
    ck_assert_str_eq(s21_dest, dest);
}
END_TEST

START_TEST(test8_s21_strncat_buffer_overflow) {
    char s21_dest[3] = "ab";
    char dest[3] = "ab";
    char *s21_result = s21_strncat(s21_dest, "123456", 6);
    char *result = strncat(dest, "123456", 6);
    ck_assert_ptr_eq(s21_result, result);
    ck_assert_str_eq(s21_dest, dest);
}
END_TEST

Suite *s21_strncat_suite(void) {
    Suite *s = suite_create("s21_strncat");
    TCase *tc = tcase_create("s21_strncat_core");
    tcase_add_test(tc, test1_s21_strncat_simple_case);
    tcase_add_test(tc, test2_s21_strncat_full_copy);
    tcase_add_test(tc, test3_s21_strncat_null_dest);
    tcase_add_test(tc, test4_s21_strncat_null_src);
    tcase_add_test(tc, test5_s21_strncat_embedded_null_in_src);
    tcase_add_test(tc, test6_s21_strncat_overlap);
    tcase_add_test(tc, test7_s21_strncat_zero_length);
    tcase_add_test(tc, test8_s21_strncat_buffer_overflow);
    suite_add_tcase(s, tc);
    return s;
}

int main() {
    int failed;
    SRunner *runner = srunner_create(s21_strncat_suite());
    srunner_run_all(runner, CK_NORMAL);
    failed = srunner_ntests_failed(runner);
    srunner_free(runner);
    return (failed == 0) ? 0 : 1;
}
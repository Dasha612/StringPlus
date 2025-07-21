#include <string.h>
#include <check.h>
#include "../src/s21_string.h"
// char *memchr(const char *s, int c, size_t n) {
// Сравнение memchr и s21_memchr
START_TEST(test1_s21_memchr_zero_size) {
    const char buffer[10] = "abcdefghij";
    void *s21_result = s21_memchr(buffer, 'a', 0);
    void *result = memchr(buffer, 'a', 0);
    ck_assert_ptr_eq(s21_result, result);
}
END_TEST

START_TEST(test2_s21_memchr_not_found) {
    const char buffer[10] = "abcdefghij";
    void *s21_result = s21_memchr(buffer, 'z', 10);
    void *result = memchr(buffer, 'z', 10);
    ck_assert_ptr_eq(s21_result, result);
}
END_TEST

START_TEST(test3_s21_memchr_value_at_beginning) {
    const char buffer[10] = "abcdefghij";
    void *s21_result = s21_memchr(buffer, 'a', 10);
    void *result = memchr(buffer, 'a', 10);
    ck_assert_ptr_eq(s21_result, result);
}
END_TEST

START_TEST(test4_s21_memchr_value_in_middle) {
    const char buffer[10] = "abcdefghij";
    void *s21_result = s21_memchr(buffer, 'd', 10);
    void *result = memchr(buffer, 'd', 10);
    ck_assert_ptr_eq(s21_result, result);
}
END_TEST

START_TEST(test5_s21_memchr_value_at_end) {
    const char buffer[10] = "abcdefghij";
    void *s21_result = s21_memchr(buffer, 'j', 10);
    void *result = memchr(buffer, 'j', 10);
    ck_assert_ptr_eq(s21_result, result);
}
END_TEST

START_TEST(test6_s21_memchr_multiple_occurrences) {
    const char buffer[10] = "abcdeffghi";
    void *s21_result = s21_memchr(buffer, 'f', 10);
    void *result = memchr(buffer, 'f', 10);
    ck_assert_ptr_eq(s21_result, result);
}
END_TEST

START_TEST(test7_s21_memchr_high_ascii_value) {
    unsigned char buffer[10] = {0x00, 0x01, 0xFF, 0x02};
    void *s21_result = s21_memchr(buffer, -1, 4); // -1 → 0xFF
    void *result = memchr(buffer, -1, 4);
    ck_assert_ptr_eq(s21_result, result);
}
END_TEST

// START_TEST(test8_s21_memchr_null_pointer) {
//     void *s21_result = s21_memchr(NULL, 'X', 10);
//     void *result = memchr(NULL, 'X', 10);
//     ck_assert_ptr_eq(s21_result, result);
// }
// END_TEST

Suite *s21_memchr_suite(void) {
    Suite *s = suite_create("s21_memchr");
    TCase *tc = tcase_create("s21_memchr_core");
    tcase_add_test(tc, test1_s21_memchr_zero_size);
    tcase_add_test(tc, test2_s21_memchr_not_found);
    tcase_add_test(tc, test3_s21_memchr_value_at_beginning);
    tcase_add_test(tc, test4_s21_memchr_value_in_middle);
    tcase_add_test(tc, test5_s21_memchr_value_at_end);
    tcase_add_test(tc, test6_s21_memchr_multiple_occurrences);
    tcase_add_test(tc, test7_s21_memchr_high_ascii_value);
    // tcase_add_test(tc, test8_s21_memchr_null_pointer);
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
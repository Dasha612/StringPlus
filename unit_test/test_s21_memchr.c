#include <string.h>
#include <check.h>
#include "../src/s21_string.h"
// char *memchr(const char *s, int c, size_t n) {
START_TEST(test1_s21_memchr_zero_size) {
    size_t n = 0;
    s21_size_t s21_n = 0;
    const char buffer[10] = "abcdefghij";
    void *res = memchr(buffer, 'a', n);
    void *s21_res = s21_memchr(buffer, 'a', s21_n);
    ck_assert_ptr_eq(s21_res, res);
}
END_TEST

START_TEST(test2_s21_memchr_not_found) {
    size_t n = 10;
    s21_size_t s21_n = 10;
    const char buffer[10] = "abcdefghij";
    void *res = memchr(buffer, 'z', n);
    void *s21_res = s21_memchr(buffer, 'z', s21_n);
    ck_assert_ptr_eq(s21_res, res);
}
END_TEST

START_TEST(test3_s21_memchr_value_at_beginning) {
    size_t n = 10;
    s21_size_t s21_n = 10;
    const char buffer[10] = "abcdefghij";
    void *res = memchr(buffer, 'a', n);
    void *s21_res = s21_memchr(buffer, 'a', s21_n);
    ck_assert_ptr_eq(s21_res, res);
}
END_TEST

START_TEST(test4_s21_memchr_value_in_middle) {
    size_t n = 10;
    s21_size_t s21_n = 10;
    const char buffer[10] = "abcdefghij";
    void *res = memchr(buffer, 'd', n);
    void *s21_res = s21_memchr(buffer, 'd', s21_n);
    ck_assert_ptr_eq(s21_res, res);
}
END_TEST

START_TEST(test5_s21_memchr_value_at_end) {
    size_t n = 10;
    s21_size_t s21_n = 10;
    const char buffer[10] = "abcdefghij";
    void *res = memchr(buffer, 'j', n);
    void *s21_res = s21_memchr(buffer, 'j', s21_n);
    ck_assert_ptr_eq(s21_res, res);
}
END_TEST

START_TEST(test6_s21_memchr_multiple_occurrences) {
    size_t n = 10;
    s21_size_t s21_n = 10;
    const char buffer[10] = "abcdeffghi";
    void *res = memchr(buffer, 'f', n);
    void *s21_res = s21_memchr(buffer, 'f', s21_n);
    ck_assert_ptr_eq(s21_res, res);
}
END_TEST

START_TEST(test7_s21_memchr_high_ascii_value) {
    size_t n = 4;
    s21_size_t s21_n = 4;
    unsigned char buffer[10] = {0x00, 0x01, 0xFF, 0x02};

    int c = -1;
    void *res = memchr(buffer, (unsigned char)c, n);
    void *s21_res = s21_memchr(buffer, (unsigned char)c, s21_n); // -1 → 0xFF
    ck_assert_ptr_eq(s21_res, res);
}
END_TEST

START_TEST(test8_s21_memchr_search_for_null) {
    size_t n = 10;
    s21_size_t s21_n = 10;
    const char buffer[10] = {'a', 'b', 'c', '\0', 'd', 'e', 'f', 'g', 'h', 'i'};
    void *res = memchr(buffer, '\0', n);
    void *s21_res = s21_memchr(buffer, '\0', s21_n);
    ck_assert_ptr_eq(s21_res, res);
}
END_TEST

START_TEST(test9_s21_memchr_partial_search) {
    size_t n = 5;
    s21_size_t s21_n = 5;
    const char buffer[10] = "aaaaabbbbb";
    void *res = memchr(buffer, 'b', n);
    void *s21_res = s21_memchr(buffer, 'b', s21_n); // ищем только в первой половине
    ck_assert_ptr_eq(s21_res, res);
}
END_TEST

START_TEST(test10_s21_memchr_all_same) {
    size_t n = 10;
    s21_size_t s21_n = 10;
    const char buffer[10] = "cccccccccc";
    void *res = memchr(buffer, 'c', n);
    void *s21_res = s21_memchr(buffer, 'c', s21_n);
    ck_assert_ptr_eq(s21_res, res);
}
END_TEST

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
    tcase_add_test(tc, test8_s21_memchr_search_for_null);
    tcase_add_test(tc, test9_s21_memchr_partial_search);
    tcase_add_test(tc, test10_s21_memchr_all_same);
    suite_add_tcase(s, tc);
    return s;
}

int s21_memchr_main() {
    int failed;
    SRunner *runner = srunner_create(s21_memchr_suite());
    srunner_run_all(runner, CK_NORMAL);
    failed = srunner_ntests_failed(runner);
    srunner_free(runner);
    return (failed == 0) ? 0 : failed;
}
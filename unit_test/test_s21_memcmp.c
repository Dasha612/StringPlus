#include <string.h>
#include <check.h>
#include "../src/s21_string.h"
// int memcmp(const void *s1, const void *s2, size_t n) {
START_TEST(test1_s21_memcmp_zero_size) {
    size_t n = 0;
    s21_size_t s21_n = 0;
    const char a[] = "abc";
    const char b[] = "def";
    int res = memcmp(a, b, n);
    int s21_res = s21_memcmp(a, b, s21_n);
    ck_assert((res == 0 && s21_res == 0) || (res < 0 && s21_res < 0) || (res > 0 && s21_res > 0));
}
END_TEST

START_TEST(test2_s21_memcmp_equal_buffers) {
    size_t n = 5;
    s21_size_t s21_n = 5;
    const char a[] = "hello";
    const char b[] = "hello";
    int res = memcmp(a, b, n);
    int s21_res = s21_memcmp(a, b, s21_n);
    ck_assert((res == 0 && s21_res == 0) || (res < 0 && s21_res < 0) || (res > 0 && s21_res > 0));
}
END_TEST

START_TEST(test3_s21_memcmp_different_first_byte) {
    size_t n = 5;
    s21_size_t s21_n = 5;
    const char a[] = "apple";
    const char b[] = "apply";
    int res = memcmp(a, b, n);
    int s21_res = s21_memcmp(a, b, s21_n);
    ck_assert((res == 0 && s21_res == 0) || (res < 0 && s21_res < 0) || (res > 0 && s21_res > 0));
}
END_TEST

START_TEST(test4_s21_memcmp_different_middle_byte) {
    size_t n = 7;
    s21_size_t s21_n = 7;
    const char a[] = "banana";
    const char b[] = "bagnana";
    int res = memcmp(a, b, n);
    int s21_res = s21_memcmp(a, b, s21_n);
    ck_assert((res == 0 && s21_res == 0) || (res < 0 && s21_res < 0) || (res > 0 && s21_res > 0));
}
END_TEST

START_TEST(test5_s21_memcmp_different_last_byte) {
    size_t n = 4;
    s21_size_t s21_n = 4;
    const char a[] = "test";
    const char b[] = "text";
    int res = memcmp(a, b, n);
    int s21_res = s21_memcmp(a, b, s21_n);
    ck_assert((res == 0 && s21_res == 0) || (res < 0 && s21_res < 0) || (res > 0 && s21_res > 0));
}
END_TEST

START_TEST(test6_s21_memcmp_same_prefix_but_longer) {
    size_t n = 5;
    s21_size_t s21_n = 5;
    const char a[] = "hello";
    const char b[] = "hellolonger";
    int res = memcmp(a, b, n);
    int s21_res = s21_memcmp(a, b, s21_n);
    ck_assert((res == 0 && s21_res == 0) || (res < 0 && s21_res < 0) || (res > 0 && s21_res > 0));
}
END_TEST

START_TEST(test7_s21_memcmp_empty_buffers) {
    size_t n = 0;
    s21_size_t s21_n = 0;
    const char a[] = "";
    const char b[] = "";
    int res = memcmp(a, b, n);
    int s21_res = s21_memcmp(a, b, s21_n);
        ck_assert((res == 0 && s21_res == 0) || (res < 0 && s21_res < 0) || (res > 0 && s21_res > 0));
}
END_TEST

START_TEST(test8_s21_memcmp_all_bytes_different) {
    size_t n = 6;
    s21_size_t s21_n = 6;
    const char a[] = "abcdef";
    const char b[] = "ghijkl";
    int res = memcmp(a, b, n);
    int s21_res = s21_memcmp(a, b, s21_n);
        ck_assert((res == 0 && s21_res == 0) || (res < 0 && s21_res < 0) || (res > 0 && s21_res > 0));
}
END_TEST

START_TEST(test9_s21_memcmp_partial_compare) {
    size_t n = 2;
    s21_size_t s21_n = 2;
    const char a[] = "abcde";
    const char b[] = "abfde";
    int res = memcmp(a, b, n);
    int s21_res = s21_memcmp(a, b, s21_n); // сравниваем только первые 2 байта
        ck_assert((res == 0 && s21_res == 0) || (res < 0 && s21_res < 0) || (res > 0 && s21_res > 0));
}
END_TEST

Suite *s21_memcmp_suite(void) {
    Suite *s = suite_create("s21_memcmp");
    TCase *tc = tcase_create("s21_memcmp_core");
    tcase_add_test(tc, test1_s21_memcmp_zero_size);
    tcase_add_test(tc, test2_s21_memcmp_equal_buffers);
    tcase_add_test(tc, test3_s21_memcmp_different_first_byte);
    tcase_add_test(tc, test4_s21_memcmp_different_middle_byte);
    tcase_add_test(tc, test5_s21_memcmp_different_last_byte);
    tcase_add_test(tc, test6_s21_memcmp_same_prefix_but_longer);
    tcase_add_test(tc, test7_s21_memcmp_empty_buffers);
    tcase_add_test(tc, test8_s21_memcmp_all_bytes_different);
    tcase_add_test(tc, test9_s21_memcmp_partial_compare);
    suite_add_tcase(s, tc);
    return s;
}

int s21_memcmp_main() {
    int failed;
    SRunner *runner = srunner_create(s21_memcmp_suite());
    srunner_run_all(runner, CK_NORMAL);
    failed = srunner_ntests_failed(runner);
    srunner_free(runner);
    return (failed == 0) ? 0 : failed;
}
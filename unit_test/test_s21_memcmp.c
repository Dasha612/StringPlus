#include <string.h>
#include <check.h>
// int memcmp(const void *s1, const void *s2, size_t n) {
// Сравнение memcmp и s21_memcmp

START_TEST(test1_s21_memcmp_zero_size) {
    int s21_result = s21_memcmp("abc", "def", 0);
    int result = memcmp("abc", "def", 0);
    ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(test2_s21_memcmp_equal_buffers) {
    int s21_result = s21_memcmp("hello", "hello", 5);
    int result = memcmp("hello", "hello", 5);
    ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(test3_s21_memcmp_different_first_byte) {
    int s21_result = s21_memcmp("apple", "apply", 5);
    int result = memcmp("apple", "apply", 5);
    ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(test4_s21_memcmp_different_middle_byte) {
    int s21_result = s21_memcmp("banana", "barnana", 7);
    int result = memcmp("banana", "barnana", 7);
    ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(test5_s21_memcmp_different_last_byte) {
    int s21_result = s21_memcmp("test", "text", 4);
    int result = memcmp("test", "text", 4);
    ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(test6_s21_memcmp_same_prefix_but_longer) {
    int s21_result = s21_memcmp("hello", "hellolonger", 5);
    int result = memcmp("hello", "hellolonger", 5);
    ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(test7_s21_memcmp_high_ascii_values) {
    unsigned char a[] = {0xFF, 0x01};
    unsigned char b[] = {0xFE, 0x01};
    int s21_result = s21_memcmp(a, b, 2);
    int result = memcmp(a, b, 2);

    ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(test8_s21_memcmp_null_pointer) {
    int s21_result = s21_memcmp(NULL, NULL, 0);
    int result = memcmp(NULL, NULL, 0);
    ck_assert_int_eq(s21_result, result);
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
    tcase_add_test(tc, test7_s21_memcmp_high_ascii_values);
    tcase_add_test(tc, test8_s21_memcmp_null_pointer);
    suite_add_tcase(s, tc);
    return s;
}

int main() {
    int failed;
    SRunner *runner = srunner_create(s21_memcmp_suite());
    srunner_run_all(runner, CK_NORMAL);
    failed = srunner_ntests_failed(runner);
    srunner_free(runner);
    return (failed == 0) ? 0 : 1;
}
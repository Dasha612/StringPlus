#include <string.h>
#include <check.h>
#include "../src/s21_string.h"
// void *memset(void *s, int c, size_t n)
// Сравнение memset и s21_memset

START_TEST(test1_s21_memset_zero_size) {
    char buffer[10] = "abcdefghij";
    void *s21_result = s21_memset(buffer, 'X', 0);
    void *result = memset(buffer, 'X', 0);
    ck_assert_ptr_eq(s21_result, result);
    ck_assert_str_eq(buffer, "abcdefghij");
}
END_TEST

START_TEST(test2_s21_memset_one_byte) {
    char buffer[10] = {0};
    void *s21_result = s21_memset(buffer, 'A', 1);
    void *result = memset(buffer, 'A', 1);
    ck_assert_ptr_eq(s21_result, result);
    ck_assert_int_eq(buffer[0], 'A');
}
END_TEST

START_TEST(test3_s21_memset_fill_with_zero) {
    char buffer[5];
    void *s21_result = s21_memset(buffer, 0, 5);
    void *result = memset(buffer, 0, 5);
    ck_assert_ptr_eq(s21_result, result);
    for (int i = 0; i < 5; i++) {
        ck_assert_int_eq(buffer[i], 0);
    }
}
END_TEST

START_TEST(test4_s21_memset_fill_with_char) {
    char buffer[5];
    void *s21_result = s21_memset(buffer, 'X', 5);
    void *result = memset(buffer, 'X', 5);
    ck_assert_ptr_eq(s21_result, result);
    for (int i = 0; i < 5; i++) {
        ck_assert_int_eq(buffer[i], 'X');
    }
}
END_TEST

START_TEST(test5_s21_memset_partial_fill) {
    char buffer[10] = "abcdefghij";
    void *s21_result = s21_memset(buffer + 3, 'Z', 4);
    void *result = memset(buffer + 3, 'Z', 4);
    ck_assert_ptr_eq(s21_result, result);
    ck_assert_str_eq(buffer, "abZZZZfghij");
}
END_TEST

START_TEST(test6_s21_memset_full_buffer) {
    char buffer[10];
    void *s21_result = s21_memset(buffer, 'K', 10);
    void *result = memset(buffer, 'K', 10);
    ck_assert_ptr_eq(s21_result, result);
    for (int i = 0; i < 10; i++) {
        ck_assert_int_eq(buffer[i], 'K');
    }
}
END_TEST

START_TEST(test7_s21_memset_high_ascii_value) {
    unsigned char buffer[3];
    void *s21_result = s21_memset(buffer, -1, 3);
    void *result = memset(buffer, -1, 3);
    ck_assert_ptr_eq(s21_result, result);
    for (int i = 0; i < 3; i++) {
        ck_assert_int_eq(buffer[i], 0xFF);
    }
}
END_TEST

START_TEST(test8_s21_memset_null_pointer) {
    void *s21_result = s21_memset(NULL, 'X', 10);
    void *result = memset(NULL, 'X', 10);
    ck_assert_ptr_eq(s21_result, result);
}
END_TEST


Suite *s21_memset_suite(void) {
    Suite *s = suite_create("s21_memset");
    TCase *tc = tcase_create("s21_memset_core");
    tcase_add_test(tc, test1_s21_memset_zero_size);
    tcase_add_test(tc, test2_s21_memset_one_byte);
    tcase_add_test(tc, test3_s21_memset_fill_with_zero);
    tcase_add_test(tc, test4_s21_memset_fill_with_char);
    tcase_add_test(tc, test5_s21_memset_partial_fill);
    tcase_add_test(tc, test6_s21_memset_full_buffer);
    tcase_add_test(tc, test7_s21_memset_high_ascii_value);
    tcase_add_test(tc, test8_s21_memset_null_pointer);
    suite_add_tcase(s, tc);
    return s;
}

int main() {
    int failed;
    SRunner *runner = srunner_create(s21_memset_suite());
    srunner_run_all(runner, CK_NORMAL);
    failed = srunner_ntests_failed(runner);
    srunner_free(runner);
    return (failed == 0) ? 0 : 1;
}
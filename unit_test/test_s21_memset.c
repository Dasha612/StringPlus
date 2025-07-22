#include <string.h>
#include <check.h>
#include "../src/s21_string.h"
// void *memset(void *s, int c, size_t n)
// Сравнение memset и s21_memset

START_TEST(test1_s21_memset_middle_one_byte) {
    size_t n = 1;
    s21_size_t s21_n = 1;
    char buffer[10] = "abcdefghij";
    void *res = memset(buffer + 5, 'Q', n);
    void *s21_res = s21_memset(buffer + 5, 'Q', s21_n);
    ck_assert_ptr_eq(s21_res, res);
    ck_assert_int_eq(buffer[5], 'Q');
    for (int i = 0; i < 10; i++) {
        if (i != 5) {
            ck_assert_int_eq(buffer[i], "abcdefghij"[i]);
        }
    }
}
END_TEST

START_TEST(test2_s21_memset_one_byte) {
    size_t n = 1;
    s21_size_t s21_n = 1;
    char buffer[10] = {0};
    void *res = memset(buffer, 'A', n);
    void *s21_res = s21_memset(buffer, 'A', s21_n);
    ck_assert_ptr_eq(s21_res, res);
    ck_assert_int_eq(buffer[0], 'A');
}
END_TEST

START_TEST(test3_s21_memset_fill_with_zero) {
    size_t n = 5;
    s21_size_t s21_n = 5;
    char buffer[5];
    void *res = memset(buffer, 0, n);
    void *s21_res = s21_memset(buffer, 0, s21_n);
    ck_assert_ptr_eq(s21_res, res);
    for (int i = 0; i < 5; i++) {
        ck_assert_int_eq(buffer[i], 0);
    }
}
END_TEST

START_TEST(test4_s21_memset_fill_with_char) {
    size_t n = 5;
    s21_size_t s21_n = 5;
    char buffer[5];
    void *res = memset(buffer, 'X', n);
    void *s21_res = s21_memset(buffer, 'X', s21_n);
    ck_assert_ptr_eq(s21_res, res);
    for (int i = 0; i < 5; i++) {
        ck_assert_int_eq(buffer[i], 'X');
    }
}
END_TEST

START_TEST(test5_s21_memset_partial_fill) {
    size_t n = 4;
    s21_size_t s21_n = 4;
    char buffer[10] = "abcdefghij";
    void *res = memset(buffer + 3, 'Z', n);
    void *s21_res = s21_memset(buffer + 3, 'Z', s21_n);
    ck_assert_ptr_eq(s21_res, res);
}
END_TEST

START_TEST(test6_s21_memset_full_buffer) {
    size_t n = 10;
    s21_size_t s21_n = 10;
    char buffer[10];
    void *res = memset(buffer, 'K', n);
    void *s21_res = s21_memset(buffer, 'K', s21_n);
    ck_assert_ptr_eq(s21_res, res);
    for (int i = 0; i < 10; i++) {
        ck_assert_int_eq(buffer[i], 'K');
    }
}
END_TEST

START_TEST(test7_s21_memset_high_ascii_value) {
    size_t n = 3;
    s21_size_t s21_n = 3;
    unsigned char buffer[3];
    void *res = memset(buffer, -1, n);
    void *s21_res = s21_memset(buffer, -1, s21_n);
    ck_assert_ptr_eq(s21_res, res);
    for (int i = 0; i < 3; i++) {
        ck_assert_int_eq(buffer[i], 0xFF);
    }
}
END_TEST

START_TEST(test8_s21_memset_zero_length) {
    size_t n = 0;
    s21_size_t s21_n = 0;
    char buffer[10] = "abcdefghij";
    void *res = memset(buffer, 'X', n);
    void *s21_res = s21_memset(buffer, 'X', s21_n);
    ck_assert_ptr_eq(s21_res, res);
    ck_assert_str_eq(buffer, "abcdefghij");
}
END_TEST

START_TEST(test9_s21_memset_fill_middle) {
    size_t n = 5;
    s21_size_t s21_n = 5;
    char buffer[10] = "abcdefghij";
    void *res = memset(buffer + 2, 'M', n);
    void *s21_res = s21_memset(buffer + 2, 'M', s21_n);
    ck_assert_ptr_eq(s21_res, res);
    for (int i = 2; i < 7; i++) {
        ck_assert_int_eq(buffer[i], 'M');
    }
}
END_TEST

START_TEST(test10_s21_memset_all_ascii) {
    size_t n = 5;
    s21_size_t s21_n = 5;
    char buffer[5] = {0};
    for (int c = 32; c < 127; c++) {
        void *res = memset(buffer, c, n);
        void *s21_res = s21_memset(buffer, c, s21_n);
        ck_assert_ptr_eq(s21_res, res);
        for (int i = 0; i < 5; i++) {
            ck_assert_int_eq(buffer[i], c);
        }
    }
}
END_TEST

Suite *s21_memset_suite(void) {
    Suite *s = suite_create("s21_memset");
    TCase *tc = tcase_create("s21_memset_core");
    tcase_add_test(tc, test1_s21_memset_middle_one_byte);
    tcase_add_test(tc, test2_s21_memset_one_byte);
    tcase_add_test(tc, test3_s21_memset_fill_with_zero);
    tcase_add_test(tc, test4_s21_memset_fill_with_char);
    tcase_add_test(tc, test5_s21_memset_partial_fill);
    tcase_add_test(tc, test6_s21_memset_full_buffer);
    tcase_add_test(tc, test7_s21_memset_high_ascii_value);
    tcase_add_test(tc, test8_s21_memset_zero_length);
    tcase_add_test(tc, test9_s21_memset_fill_middle);
    tcase_add_test(tc, test10_s21_memset_all_ascii);

    suite_add_tcase(s, tc);
    return s;
}

int s21_memset_main() {
    int failed;
    SRunner *runner = srunner_create(s21_memset_suite());
    srunner_run_all(runner, CK_NORMAL);
    failed = srunner_ntests_failed(runner);
    srunner_free(runner);
    return (failed == 0) ? 0 : 1;
}
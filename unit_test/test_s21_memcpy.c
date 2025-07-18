#include <string.h>
#include <check.h>
// void *memcpy(void *dest, const void *src, size_t n)
// Сравнение memcpy и s21_memcpy

START_TEST(test1_s21_memcpy_zero_size) {
    char dest[10] = "abcdefghij";
    char src[10] = "1234567890";
    void *s21_result = s21_memcpy(dest, src, 0);
    void *result = memcpy(dest, src, 0);
    ck_assert_ptr_eq(s21_result, result);
    ck_assert_str_eq(dest, "abcdefghij");
}
END_TEST

START_TEST(test2_s21_memcpy_small_buffer) {
    char dest[10] = {0};
    char src[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
    void *s21_result = s21_memcpy(dest, src, 10);
    void *result = memcpy(dest, src, 10);
    ck_assert_ptr_eq(s21_result, result);
    for (int i = 0; i < 10; i++) {
        ck_assert_int_eq(dest[i], src[i]);
    }
}
END_TEST

START_TEST(test3_s21_memcpy_partial_large_buffer) {
    char dest[10] = {0};
    char src[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
    void *s21_result = s21_memcpy(dest + 2, src + 2, 5);
    void *result = memcpy(dest + 2, src + 2, 5);
    ck_assert_ptr_eq(s21_result, result);
    for (int i = 0; i < 10; i++) {
        if (i >= 2 && i < 7) {
            ck_assert_int_eq(dest[i], src[i]);
        } else {
            ck_assert_int_eq(dest[i], 0); // проверка не затронутых частей
        }
    }
}
END_TEST

START_TEST(test4_s21_memcpy_safe_overlap) {
    char buffer[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
    void *s21_result = s21_memcpy(buffer + 5, buffer, 5);
    void *result = memcpy(buffer + 5, buffer, 5);
    ck_assert_ptr_eq(s21_result, result);
    ck_assert_int_eq(buffer[5], 'a');
    ck_assert_int_eq(buffer[6], 'b');
    ck_assert_int_eq(buffer[7], 'c');
    ck_assert_int_eq(buffer[8], 'd');
    ck_assert_int_eq(buffer[9], 'e');
}
END_TEST

START_TEST(test5_s21_memcpy_unsafe_overlap) {
    char buffer[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
    void *s21_result = s21_memcpy(buffer, buffer + 5, 5);
    void *result = memcpy(buffer, buffer + 5, 5);
    ck_assert_ptr_eq(s21_result, result);
    ck_assert_int_eq(buffer[0], 'f');
    ck_assert_int_eq(buffer[1], 'g');
    ck_assert_int_eq(buffer[2], 'h');
    ck_assert_int_eq(buffer[3], 'i');
    ck_assert_int_eq(buffer[4], 'j');
}
END_TEST

START_TEST(test6_s21_memcpy_high_ascii_values) {
    unsigned char dest[5] = {0};
    unsigned char src[5] = {0xFF, 0xFE, 0xFD, 0xFC, 0xFB};
    void *s21_result = s21_memcpy(dest, src, 5);
    void *result = memcpy(dest, src, 5);
    ck_assert_ptr_eq(s21_result, result);
    for (int i = 0; i < 5; i++) {
        ck_assert_int_eq(dest[i], src[i]);
    }
}
END_TEST

START_TEST(test7_s21_memcpy_copy_to_self) {
    char buffer[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
    void *s21_result = s21_memcpy(buffer, buffer, 10);
    void *result = memcpy(buffer, buffer, 10);
    ck_assert_ptr_eq(s21_result, result);
    for (int i = 0; i < 10; i++) {
        ck_assert_int_eq(buffer[i], 'a' + i);
    }
}
END_TEST

START_TEST(test8_s21_memcpy_null_pointer) {
    void *s21_result = s21_memcpy(NULL, "test", 4);
    void *result = memcpy(NULL, "test", 4);
    ck_assert_ptr_eq(s21_result, result);
}
END_TEST


Suite *s21_memcpy_suite(void) {
    Suite *s = suite_create("s21_memcpy");
    TCase *tc = tcase_create("s21_memcpy_core");
    tcase_add_test(tc, test1_s21_memcpy_zero_size);
    tcase_add_test(tc, test2_s21_memcpy_small_buffer);
    tcase_add_test(tc, test3_s21_memcpy_partial_large_buffer);
    tcase_add_test(tc, test4_s21_memcpy_safe_overlap);
    tcase_add_test(tc, test5_s21_memcpy_unsafe_overlap);
    tcase_add_test(tc, test6_s21_memcpy_high_ascii_values);
    tcase_add_test(tc, test7_s21_memcpy_copy_to_self);
    tcase_add_test(tc, test8_s21_memcpy_null_pointer);
    suite_add_tcase(s, tc);
    return s;
}

int main() {
    int failed;
    SRunner *runner = srunner_create(s21_memcpy_suite());
    srunner_run_all(runner, CK_NORMAL);
    failed = srunner_ntests_failed(runner);
    srunner_free(runner);
    return (failed == 0) ? 0 : 1;
}
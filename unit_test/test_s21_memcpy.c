#include <check.h>
#include <string.h>

#include "../src/s21_string.h"
// void *memcpy(void *dest, const void *src, size_t n)
START_TEST(test1_s21_memcpy_zero_size) {
  size_t n = 0;
  s21_size_t s21_n = 0;
  char a[10] = "abcdefghij";
  const char b[10] = "1234567890";
  void *res = memcpy(a, b, n);
  void *s21_res = s21_memcpy(a, b, s21_n);
  ck_assert_ptr_eq(s21_res, res);
}
END_TEST

START_TEST(test2_s21_memcpy_small_buffer) {
  size_t n = 10;
  s21_size_t s21_n = 10;
  char a[10] = {0};
  char b[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
  void *res = memcpy(a, b, n);
  void *s21_res = s21_memcpy(a, b, s21_n);
  ck_assert_ptr_eq(s21_res, res);
  for (int i = 0; i < 10; i++) {
    ck_assert_int_eq(a[i], b[i]);
  }
}
END_TEST

START_TEST(test3_s21_memcpy_partial_large_buffer) {
  size_t n = 5;
  s21_size_t s21_n = 5;
  char a[10] = {0};
  char b[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
  void *res = memcpy(a + 2, b + 2, n);
  void *s21_res = s21_memcpy(a + 2, b + 2, s21_n);
  ck_assert_ptr_eq(s21_res, res);
  for (int i = 0; i < 10; i++) {
    if (i >= 2 && i < 7) {
      ck_assert_int_eq(a[i], b[i]);
    } else {
      ck_assert_int_eq(a[i], 0);  // проверка не затронутых частей
    }
  }
}
END_TEST

START_TEST(test4_s21_memcpy_safe_overlap) {
  size_t n = 5;
  s21_size_t s21_n = 5;
  char buffer[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
  void *res = memcpy(buffer + 5, buffer, n);
  void *s21_res = s21_memcpy(buffer + 5, buffer, s21_n);
  ck_assert_ptr_eq(s21_res, res);
  ck_assert_int_eq(buffer[5], 'a');
  ck_assert_int_eq(buffer[6], 'b');
  ck_assert_int_eq(buffer[7], 'c');
  ck_assert_int_eq(buffer[8], 'd');
  ck_assert_int_eq(buffer[9], 'e');
}
END_TEST

START_TEST(test5_s21_memcpy_unsafe_overlap) {
  size_t n = 5;
  s21_size_t s21_n = 5;
  char buffer[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
  void *res = memcpy(buffer, buffer + 5, n);
  void *s21_res = s21_memcpy(buffer, buffer + 5, s21_n);
  ck_assert_ptr_eq(s21_res, res);
  ck_assert_int_eq(buffer[0], 'f');
  ck_assert_int_eq(buffer[1], 'g');
  ck_assert_int_eq(buffer[2], 'h');
  ck_assert_int_eq(buffer[3], 'i');
  ck_assert_int_eq(buffer[4], 'j');
}
END_TEST

START_TEST(test6_s21_memcpy_high_ascii_values) {
  size_t n = 5;
  s21_size_t s21_n = 5;
  unsigned char a[5] = {0};
  unsigned char b[5] = {0xFF, 0xFE, 0xFD, 0xFC, 0xFB};
  void *res = memcpy(a, b, n);
  void *s21_res = s21_memcpy(a, b, s21_n);
  ck_assert_ptr_eq(s21_res, res);
  for (int i = 0; i < 5; i++) {
    ck_assert_int_eq(a[i], b[i]);
  }
}
END_TEST

START_TEST(test7_s21_memcpy_empty_src) {
  size_t n = 0;
  s21_size_t s21_n = 0;
  char a[5] = "abcd";
  const char b[1] = "";
  void *res = memcpy(a, b, n);
  void *s21_res = s21_memcpy(a, b, s21_n);
  ck_assert_ptr_eq(s21_res, res);
  ck_assert_str_eq(a, "abcd");
}
END_TEST

START_TEST(test8_s21_memcpy_partial_ascii) {
  size_t n = 4;
  s21_size_t s21_n = 4;
  char a[10] = "abcdefghij";
  char b[10] = "1234567890";
  void *res = memcpy(a + 3, b + 3, n);
  void *s21_res = s21_memcpy(a + 3, b + 3, s21_n);
  ck_assert_ptr_eq(s21_res, res);
  for (int i = 3; i < 7; i++) {
    ck_assert_int_eq(a[i], b[i]);
  }
}
END_TEST

START_TEST(test9_s21_memcpy_all_same) {
  size_t n = 6;
  s21_size_t s21_n = 6;
  char a[6] = {0};
  char b[6] = {'A', 'A', 'A', 'A', 'A', '\0'};
  void *res = memcpy(a, b, n);
  void *s21_res = s21_memcpy(a, b, s21_n);
  ck_assert_ptr_eq(s21_res, res);
  ck_assert_str_eq(a, b);
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
  tcase_add_test(tc, test7_s21_memcpy_empty_src);
  tcase_add_test(tc, test8_s21_memcpy_partial_ascii);
  tcase_add_test(tc, test9_s21_memcpy_all_same);
  suite_add_tcase(s, tc);
  return s;
}

int s21_memcpy_main() {
  int failed;
  SRunner *runner = srunner_create(s21_memcpy_suite());
  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (failed == 0) ? 0 : failed;
}
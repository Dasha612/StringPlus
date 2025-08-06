#include <check.h>
#include <string.h>

#include "../src/s21_string.h"
// char *strchr(const char *s, int c)
START_TEST(test1_s21_strchr_not_found) {
  const char str[] = "hello";
  char *res = strchr(str, 'x');
  char *s21_res = s21_strchr(str, 'x');
  ck_assert_ptr_eq(s21_res, res);
}
END_TEST

START_TEST(test2_s21_strchr_at_beginning) {
  const char str[] = "apple";
  char *res = strchr(str, 'a');
  char *s21_res = s21_strchr(str, 'a');
  ck_assert_ptr_eq(s21_res, res);
}
END_TEST

START_TEST(test3_s21_strchr_in_middle) {
  const char str[] = "banana";
  char *res = strchr(str, 'n');
  char *s21_res = s21_strchr(str, 'n');
  ck_assert_ptr_eq(s21_res, res);
}
END_TEST

START_TEST(test4_s21_strchr_at_end) {
  const char str[] = "orange";
  char *res = strchr(str, 'e');
  char *s21_res = s21_strchr(str, 'e');
  ck_assert_ptr_eq(s21_res, res);
}
END_TEST

START_TEST(test5_s21_strchr_search_for_null) {
  const char str[] = "test\0end";
  char *res = strchr(str, '\0');
  char *s21_res = s21_strchr(str, '\0');
  ck_assert_ptr_eq(s21_res, res);
}
END_TEST

START_TEST(test6_s21_strchr_multiple_occurrences) {
  const char str[] = "abcdeffghi";
  char *res = strchr(str, 'f');
  char *s21_res = s21_strchr(str, 'f');
  ck_assert_ptr_eq(s21_res, res);
}
END_TEST

START_TEST(test7_s21_strchr_empty_string) {
  const char str[] = "";
  char *res = strchr(str, 'a');
  char *s21_res = s21_strchr(str, 'a');
  ck_assert_ptr_eq(s21_res, res);
}
END_TEST

START_TEST(test8_s21_strchr_all_same) {
  const char str[] = "aaaaaa";
  char *res = strchr(str, 'a');
  char *s21_res = s21_strchr(str, 'a');
  ck_assert_ptr_eq(s21_res, res);
}
END_TEST

START_TEST(test9_s21_strchr_search_for_space) {
  const char str[] = "abc def";
  char *res = strchr(str, ' ');
  char *s21_res = s21_strchr(str, ' ');
  ck_assert_ptr_eq(s21_res, res);
}
END_TEST

Suite *s21_strchr_suite(void) {
  Suite *s = suite_create("s21_strchr");
  TCase *tc = tcase_create("s21_strchr_core");
  tcase_add_test(tc, test1_s21_strchr_not_found);
  tcase_add_test(tc, test2_s21_strchr_at_beginning);
  tcase_add_test(tc, test3_s21_strchr_in_middle);
  tcase_add_test(tc, test4_s21_strchr_at_end);
  tcase_add_test(tc, test5_s21_strchr_search_for_null);
  tcase_add_test(tc, test6_s21_strchr_multiple_occurrences);
  tcase_add_test(tc, test7_s21_strchr_empty_string);
  tcase_add_test(tc, test8_s21_strchr_all_same);
  tcase_add_test(tc, test9_s21_strchr_search_for_space);
  suite_add_tcase(s, tc);
  return s;
}

int s21_strchr_main() {
  int failed;
  SRunner *runner = srunner_create(s21_strchr_suite());
  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (failed == 0) ? 0 : failed;
}
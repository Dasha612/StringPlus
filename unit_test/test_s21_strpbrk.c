#include <check.h>
#include <string.h>

#include "../src/s21_string.h"
// char *strpbrk(const char *s, const char *accept)
START_TEST(test1_s21_strpbrk_match_at_beginning) {
  const char a[] = "apple";
  const char b[] = "a";
  const char *res = strpbrk(a, b);
  const char *s21_res = s21_strpbrk(a, b);
  ck_assert_ptr_eq(s21_res, res);
}
END_TEST

START_TEST(test2_s21_strpbrk_match_in_middle) {
  const char a[] = "banana";
  const char b[] = "n";
  const char *res = strpbrk(a, b);
  const char *s21_res = s21_strpbrk(a, b);
  ck_assert_ptr_eq(s21_res, res);
}
END_TEST

START_TEST(test3_s21_strpbrk_match_at_end) {
  const char a[] = "orange";
  const char b[] = "e";
  const char *res = strpbrk(a, b);
  const char *s21_res = s21_strpbrk(a, b);
  ck_assert_ptr_eq(s21_res, res);
}
END_TEST

START_TEST(test4_s21_strpbrk_space_match) {
  const char a[] = "abc def";
  const char b[] = " xyz";
  const char *res = strpbrk(a, b);
  const char *s21_res = s21_strpbrk(a, b);
  ck_assert_ptr_eq(s21_res, res);
}
END_TEST

START_TEST(test5_s21_strpbrk_multiple_matches) {
  const char a[] = "abcdeffghi";
  const char b[] = "fed";
  const char *res = strpbrk(a, b);
  const char *s21_res = s21_strpbrk(a, b);
  ck_assert_ptr_eq(s21_res, res);
}
END_TEST

START_TEST(test6_s21_strpbrk_no_match) {
  const char a[] = "abcdef";
  const char b[] = "xyz";
  const char *res = strpbrk(a, b);
  const char *s21_res = s21_strpbrk(a, b);
  ck_assert_ptr_eq(s21_res, res);
}
END_TEST

START_TEST(test7_s21_strpbrk_empty_str1) {
  const char a[] = "";
  const char b[] = "abc";
  const char *res = strpbrk(a, b);
  const char *s21_res = s21_strpbrk(a, b);
  ck_assert_ptr_eq(s21_res, res);
}
END_TEST

START_TEST(test8_s21_strpbrk_empty_str2) {
  const char a[] = "abcdef";
  const char b[] = "";
  const char *res = strpbrk(a, b);
  const char *s21_res = s21_strpbrk(a, b);
  ck_assert_ptr_eq(s21_res, res);
}
END_TEST

START_TEST(test9_s21_strpbrk_all_match) {
  const char a[] = "abc";
  const char b[] = "abc";
  const char *res = strpbrk(a, b);
  const char *s21_res = s21_strpbrk(a, b);
  ck_assert_ptr_eq(s21_res, res);
}
END_TEST

Suite *s21_strpbrk_suite(void) {
  Suite *s = suite_create("s21_strpbrk");
  TCase *tc = tcase_create("s21_strpbrk_core");
  tcase_add_test(tc, test1_s21_strpbrk_match_at_beginning);
  tcase_add_test(tc, test2_s21_strpbrk_match_in_middle);
  tcase_add_test(tc, test3_s21_strpbrk_match_at_end);
  tcase_add_test(tc, test4_s21_strpbrk_space_match);
  tcase_add_test(tc, test5_s21_strpbrk_multiple_matches);
  tcase_add_test(tc, test6_s21_strpbrk_no_match);
  tcase_add_test(tc, test7_s21_strpbrk_empty_str1);
  tcase_add_test(tc, test8_s21_strpbrk_empty_str2);
  tcase_add_test(tc, test9_s21_strpbrk_all_match);
  suite_add_tcase(s, tc);
  return s;
}

int s21_strpbrk_main() {
  int failed;
  SRunner *runner = srunner_create(s21_strpbrk_suite());
  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (failed == 0) ? 0 : failed;
}
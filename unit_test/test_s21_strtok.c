#include <string.h>
#include <check.h>
#include "../src/s21_string.h"
// char *strtok(char *str, const char *delim)
START_TEST(test1_s21_strtok_simple_tokenization) {
    char a[] = "apple,banana,orange";
    const char b[] = ",";
    char *res = strtok(a, b);
    char *s21_res = s21_strtok(a, b);
    while (s21_res != S21_NULL && res != NULL) {
        ck_assert_ptr_eq(s21_res, res);
        res = strtok(NULL, b);
        s21_res = s21_strtok(S21_NULL, b);
    }
    ck_assert_ptr_eq(s21_res, res);
}
END_TEST

START_TEST(test2_s21_strtok_multiple_delimiters) {
    char a[] = "a;b,c;d";
    const char b[] = ",;:";
    char *res = strtok(a, b);
    char *s21_res = s21_strtok(a, b);
    while (s21_res != S21_NULL && res != NULL) {
        ck_assert_ptr_eq(s21_res, res);
        res = strtok(NULL, b);
        s21_res = s21_strtok(S21_NULL, b);
    }
    ck_assert_ptr_eq(s21_res, res);
}
END_TEST

START_TEST(test3_s21_strtok_empty_string) {
    char a[] = "";
    const char b[] = ",";
    char *res = strtok(a, b);
    char *s21_res = s21_strtok(a, b);
    ck_assert_ptr_eq(s21_res, res);
}
END_TEST

START_TEST(test4_s21_strtok_delimiter_at_beginning) {
    char a[] = ",abc,def";
    const char b[] = ",";
    char *res = strtok(a, b);
    char *s21_res = s21_strtok(a, b);
    int i = 0;
    while (s21_res != S21_NULL && res != NULL) {
        ck_assert_ptr_eq(s21_res, res);
        res = strtok(NULL, b);
        s21_res = s21_strtok(S21_NULL, b);
        i++;
    }
    ck_assert_int_eq(i, 2); // должно быть 2 токена: "abc", "def"
}
END_TEST

START_TEST(test5_s21_strtok_delimiter_at_end) {
    char a[] = "abc,def,";
    const char b[] = ",";
    char *res = strtok(a, b);
    char *s21_res = s21_strtok(a, b);
    int i = 0;
    while (s21_res != S21_NULL && res != NULL) {
        ck_assert_ptr_eq(s21_res, res);
        res = strtok(NULL, b);
        s21_res = s21_strtok(S21_NULL, b);
        i++;
    }
    ck_assert_int_eq(i, 2); // должно быть 2 токена: "abc", "def"
}
END_TEST

START_TEST(test6_s21_strtok_consecutive_delimiters) {
    char a[] = "a,,b,,c";
    const char b[] = ",";
    char *res = strtok(a, b);
    char *s21_res = s21_strtok(a, b);
    int i = 0;
    while (s21_res != NULL && res != NULL) {
        ck_assert_ptr_eq(s21_res, res);
        res = strtok(NULL, b);
        s21_res = s21_strtok(NULL, b);
        i++;
    }
    ck_assert_int_eq(i, 3); // должно быть 3 токена: "a", "b", "c"
}
END_TEST

START_TEST(test7_s21_strtok_only_delimiters) {
    char a[] = ",,,";
    const char b[] = ",";
    char *res = strtok(a, b);
    char *s21_res = s21_strtok(a, b);
    ck_assert_ptr_eq(s21_res, res);
}
END_TEST

START_TEST(test8_s21_strtok_null_pointer_input) {
    char *res = strtok(NULL, ",");
    char *s21_res = s21_strtok(NULL, ",");
    ck_assert_ptr_eq(s21_res, res);
}
END_TEST

START_TEST(test9_s21_strtok_all_delimiters) {
    char a[] = ",,,";
    const char b[] = ",";
    char *res = strtok(a, b);
    char *s21_res = s21_strtok(a, b);
    ck_assert_ptr_eq(s21_res, res);
}
END_TEST

START_TEST(test10_s21_strtok_no_delimiters) {
    char a[] = "abcdef";
    const char b[] = ",";
    char *res = strtok(a, b);
    char *s21_res = s21_strtok(a, b);
    ck_assert_str_eq(s21_res, res);
}
END_TEST

START_TEST(test11_s21_strtok_delim_is_space) {
    char a[] = "a b c";
    const char b[] = " ";
    char *res = strtok(a, b);
    char *s21_res = s21_strtok(a, b);
    while (s21_res != S21_NULL && res != NULL) {
        ck_assert_ptr_eq(s21_res, res);
        res = strtok(NULL, b);
        s21_res = s21_strtok(S21_NULL, b);
    }
    ck_assert_ptr_eq(s21_res, res);
}
END_TEST

Suite *s21_strtok_suite(void) {
    Suite *s = suite_create("s21_strtok");
    TCase *tc = tcase_create("s21_strtok_core");
    tcase_add_test(tc, test1_s21_strtok_simple_tokenization);
    tcase_add_test(tc, test2_s21_strtok_multiple_delimiters);
    tcase_add_test(tc, test3_s21_strtok_empty_string);
    tcase_add_test(tc, test4_s21_strtok_delimiter_at_beginning);
    tcase_add_test(tc, test5_s21_strtok_delimiter_at_end);
    tcase_add_test(tc, test6_s21_strtok_consecutive_delimiters);
    tcase_add_test(tc, test7_s21_strtok_only_delimiters);
    tcase_add_test(tc, test8_s21_strtok_null_pointer_input);
    tcase_add_test(tc, test9_s21_strtok_all_delimiters);
    tcase_add_test(tc, test10_s21_strtok_no_delimiters);
    tcase_add_test(tc, test11_s21_strtok_delim_is_space);
    suite_add_tcase(s, tc);
    return s;
}

int s21_strtok_main() {
    int failed;
    SRunner *runner = srunner_create(s21_strtok_suite());
    srunner_run_all(runner, CK_NORMAL);
    failed = srunner_ntests_failed(runner);
    srunner_free(runner);
    return (failed == 0) ? 0 : failed;
}
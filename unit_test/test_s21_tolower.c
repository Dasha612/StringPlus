#include <string.h>
#include <check.h>
#include <stdlib.h>
#include "../src/s21_string.h"
// void *to_lower(const char *str)
START_TEST(test1_s21_tolower_usual) {
    const char *s1 = "HelloWorld";
    char *res1 = "helloworld";
    char *s21_res1 = s21_to_lower(s1);
    ck_assert_str_eq(s21_res1, res1);
    free(s21_res1);

    const char *s2 = "IloveCoding";
    char *res2 = "ilovecoding";
    char *s21_res2 = s21_to_lower(s2);
    ck_assert_str_eq(s21_res2, res2);
    free(s21_res2);
}
END_TEST

START_TEST(test2_s21_tolower_upper) {
    const char *s1 = "HELLOWORLD";
    char *res1 = "helloworld";  
    char *s21_res1 = s21_to_lower(s1);
    ck_assert_str_eq(s21_res1, res1);
    free(s21_res1);

    const char *s2 = "ILOVECODING";
    char *res2 = "ilovecoding";
    char *s21_res2 = s21_to_lower(s2);
    ck_assert_str_eq(s21_res2, res2);
    free(s21_res2);
}
END_TEST

START_TEST(test3_s21_tolower_lower) {
    const char *s1 = "helloworld";
    char *res1 = "helloworld";
    char *s21_res1 = s21_to_lower(s1);
    ck_assert_str_eq(s21_res1, res1);
    free(s21_res1);

    const char *s2 = "ilovecoding";
    char *res2 = "ilovecoding";
    char *s21_res2 = s21_to_lower(s2);
    ck_assert_str_eq(s21_res2, res2);
    free(s21_res2);
}
END_TEST

START_TEST(test4_s21_tolower_empty) {
    const char *s = "";
    char *res = "";
    char *s21_res = s21_to_lower(s);
    ck_assert_str_eq(s21_res, res);
    free(s21_res);
}
END_TEST

START_TEST(test5_s21_tolower_with_spaces) {
    const char *s1 = "Hello World";
    char *res1 = "hello world";
    char *s21_res1 = s21_to_lower(s1);
    ck_assert_str_eq(s21_res1, res1);
    free(s21_res1);

    const char *s2 = "I Love Coding";
    char *res2 = "i love coding";
    char *s21_res2 = s21_to_lower(s2);
    ck_assert_str_eq(s21_res2, res2);
    free(s21_res2);

    const char *s3 = "     ";
    char *res3 = "     ";
    char *s21_res3 = s21_to_lower(s3);
    ck_assert_str_eq(s21_res3, res3);
    free(s21_res3);

    const char *s4 = " ";
    char *res4 = " ";
    char *s21_res4 = s21_to_lower(s4);
    ck_assert_str_eq(s21_res4, res4);
    free(s21_res4);
}
END_TEST

START_TEST(test6_s21_tolower_with_numbers) {
    const char *s1 = "1234567890";
    char *res1 = "1234567890";
    char *s21_res1 = s21_to_lower(s1);
    ck_assert_str_eq(s21_res1, res1);
    free(s21_res1);

    const char *s2 = "111";
    char *res2 = "111";
    char *s21_res2 = s21_to_lower(s2);
    ck_assert_str_eq(s21_res2, res2);
    free(s21_res2);
}
END_TEST

START_TEST(test7_s21_tolower_with_special_characters) {
    const char *s1 = "!Hello?World%%";
    char *res1 = "!hello?world%%";
    char *s21_res1 = s21_to_lower(s1);
    ck_assert_str_eq(s21_res1, res1);
    free(s21_res1);

    const char *s2 = "1!2@3#4$5%%6^7&8*9(0)";
    char *res2 = "1!2@3#4$5%%6^7&8*9(0)";
    char *s21_res2 = s21_to_lower(s2);
    ck_assert_str_eq(s21_res2, res2);
    free(s21_res2);

    const char *s3 = "(I) {L}[o]|v|(e) {C}[o]|d|+i+-n-=g=";
    char *res3 = "(i) {l}[o]|v|(e) {c}[o]|d|+i+-n-=g=";
    char *s21_res3 = s21_to_lower(s3);
    ck_assert_str_eq(s21_res3, res3);
    free(s21_res3);
}
END_TEST

START_TEST(test8_s21_tolower_one_char) {
    const char *s1 = "A";
    char *res1 = "a";
    char *s21_res1 = s21_to_lower(s1);
    ck_assert_str_eq(s21_res1, res1);
    free(s21_res1);

    const char *s2 = "B";
    char *res2 = "b";
    char *s21_res2 = s21_to_lower(s2);
    ck_assert_str_eq(s21_res2, res2);
    free(s21_res2);

    const char *s3 = "Z";
    char *res3 = "z";
    char *s21_res3 = s21_to_lower(s3);
    ck_assert_str_eq(s21_res3, res3);
    free(s21_res3);
}
END_TEST

START_TEST(test9_s21_tolower_zero_char) {
    const char *s1 = "0";
    char *res1 = "0";
    char *s21_res1 = s21_to_lower(s1);
    ck_assert_str_eq(s21_res1, res1);
    free(s21_res1);

    const char *s2 = "\0";
    char *res2 = "\0";   // ??
    char *s21_res2 = s21_to_lower(s2);
    ck_assert_str_eq(s21_res2, res2);
    free(s21_res2);
}
END_TEST

START_TEST(test10_s21_tolower_null) {
    const char *s = S21_NULL;
    char *res = NULL;
    char *s21_res = s21_to_lower(s);
    ck_assert_ptr_eq(s21_res, res);
}
END_TEST

Suite* s21_tolower_suite(void) {
    Suite *s = suite_create("s21_tolower");
    TCase *tc = tcase_create("s21_tolower_core");
    tcase_add_test(tc, test1_s21_tolower_usual);
    tcase_add_test(tc, test2_s21_tolower_upper);
    tcase_add_test(tc, test3_s21_tolower_lower);
    tcase_add_test(tc, test4_s21_tolower_empty);
    tcase_add_test(tc, test5_s21_tolower_with_spaces);
    tcase_add_test(tc, test6_s21_tolower_with_numbers);
    tcase_add_test(tc, test7_s21_tolower_with_special_characters);
    tcase_add_test(tc, test8_s21_tolower_one_char);
    tcase_add_test(tc, test9_s21_tolower_zero_char);
    tcase_add_test(tc, test10_s21_tolower_null);
    suite_add_tcase(s, tc);
    return s;
}

int s21_tolower_main() {
    int failed;
    SRunner *runner = srunner_create(s21_tolower_suite());
    srunner_run_all(runner, CK_NORMAL);
    failed = srunner_ntests_failed(runner);
    srunner_free(runner);
    return (failed == 0) ? 0 : failed;
}
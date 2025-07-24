#include <string.h>
#include <check.h>
#include "../src/s21_string.h"
// Описание функции
// Описание теста
START_TEST(test1_s21_toupper_usual) {
    char s1 = "HelloWorld";
    char res1 = "HELLOWORLD";
    char *s21_res1 = s21_to_upper(s1);
    ck_assert_str_eq(s21_res1, res1);

    char s2 = "IloveCoding";
    char res2 = "ILOVECODING";
    char *s21_res2 = s21_to_upper(s2);
    ck_assert_str_eq(s21_res2, res2);
}
END_TEST

START_TEST(test2_s21_toupper_upper) {
    char s1 = "HELLOWORLD";
    char res1 = "HELLOWORLD";  
    char *s21_res1 = s21_to_upper(s1);
    ck_assert_str_eq(s21_res1, res1);

    char s2 = "ILOVECODING";
    char res2 = "ILOVECODING";
    char *s21_res2 = s21_to_upper(s2);
    ck_assert_str_eq(s21_res2, res2);
}
END_TEST

START_TEST(test3_s21_toupper_lower) {
    char s1 = "helloworld";
    char res1 = "HELLOWORLD";
    char *s21_res1 = s21_to_upper(s1);
    ck_assert_str_eq(s21_res1, res1);

    char s2 = "ilovecoding";
    char res2 = "ILOVECODING";
    char *s21_res2 = s21_to_upper(s2);
    ck_assert_str_eq(s21_res2, res2);
}
END_TEST

START_TEST(test4_s21_toupper_empty) {
    char s = "";
    char res = "";
    char *s21_res = s21_to_upper(s);
    ck_assert_str_eq(s21_res, res);
}
END_TEST

START_TEST(test5_s21_toupper_with_spaces) {
    char s1 = "Hello World";
    char res1 = "HELLO WORLD";
    char *s21_res1 = s21_to_upper(s1);
    ck_assert_str_eq(s21_res1, res1);

    char s2 = "I Love Coding";
    char res2 = "I LOVE CODING";
    char *s21_res2 = s21_to_upper(s2);
    ck_assert_str_eq(s21_res2, res2);

    char s3 = "     ";
    char res3 = "     ";
    char *s21_res3 = s21_to_upper(s3);
    ck_assert_str_eq(s21_res3, res3);

    char s4 = " ";
    char res4 = " ";
    char *s21_res4 = s21_to_upper(s4);
    ck_assert_str_eq(s21_res4, res4);
}
END_TEST

START_TEST(test6_s21_toupper_with_numbers) {
    char s1 = "1234567890";
    char res1 = "1234567890";
    char *s21_res1 = s21_to_upper(s1);
    ck_assert_str_eq(s21_res1, res1);

    char s2 = "111";
    char res2 = "111";
    char *s21_res2 = s21_to_upper(s2);
    ck_assert_str_eq(s21_res2, res2);
}
END_TEST

START_TEST(test7_s21_toupper_with_special_characters) {
    char s1 = "!Hello?World%%";
    char res1 = "!HELLO?WORLD%%";
    char *s21_res1 = s21_to_upper(s1);
    ck_assert_str_eq(s21_res1, res1);

    char s2 = "1!2@3#4$5%%6^7&8*9(0)";
    char res2 = "1!2@3#4$5%%6^7&8*9(0)";
    char *s21_res2 = s21_to_upper(s2);
    ck_assert_str_eq(s21_res2, res2);

    char s3 = "(I) {L}[o]|v|(e) {C}[o]|d|+i+-n-=g=";
    char res3 = "(I) {L}[O]|V|(E) {C}[O]|D|+I+-N-=G=";
    char *s21_res3 = s21_to_upper(s3);
    ck_assert_str_eq(s21_res3, res3);
}
END_TEST

START_TEST(test8_s21_toupper_one_char) {
    char s1 = "a";
    char res1 = "A";
    char *s21_res1 = s21_to_upper(s1);
    ck_assert_str_eq(s21_res1, res1);

    char s2 = "b";
    char res2 = "B";
    char *s21_res2 = s21_to_upper(s2);
    ck_assert_str_eq(s21_res2, res2);

    char s3 = "z";
    char res3 = "Z";
    char *s21_res3 = s21_to_upper(s3);
    ck_assert_str_eq(s21_res3, res3);
}
END_TEST

START_TEST(test9_s21_toupper_zero_char) {
    char s1 = "0";
    char res1 = "0";
    char *s21_res1 = s21_to_upper(s1);
    ck_assert_str_eq(s21_res1, res1);

    char s2 = "\0";
    char res2 = "\0";   // ??
    char *s21_res2 = s21_to_upper(s2);
    ck_assert_str_eq(s21_res2, res2);
}
END_TEST

START_TEST(test10_s21_toupper_null) {
    char *s = S21_NULL; // ?
    char *res = NULL;
    char *s21_res = s21_to_upper(s);
    ck_assert_str_eq(s21_res, res);

}
END_TEST

Suite* s21_toupper_suite(void) {
    Suite *s = suite_create("s21_toupper");
    TCase *tc = tcase_create("s21_toupper_core");
    tcase_add_test(tc, test1_s21_toupper_usual);
    tcase_add_test(tc, test2_s21_toupper_upper);
    tcase_add_test(tc, test3_s21_toupper_lower);
    tcase_add_test(tc, test4_s21_toupper_empty);
    tcase_add_test(tc, test5_s21_toupper_with_spaces);
    tcase_add_test(tc, test6_s21_toupper_with_numbers);
    tcase_add_test(tc, test7_s21_toupper_with_special_characters);
    tcase_add_test(tc, test8_s21_toupper_one_char);
    tcase_add_test(tc, test9_s21_toupper_zero_char);
    tcase_add_test(tc, test10_s21_toupper_null);
    suite_add_tcase(s, tc);
    return s;
}

int s21_toupper_main() {
    int failed;
    SRunner *runner = srunner_create(s21_toupper_suite());
    srunner_run_all(runner, CK_NORMAL);
    failed = srunner_ntests_failed(runner);
    srunner_free(runner);
    return (failed == 0) ? 0 : failed;
}
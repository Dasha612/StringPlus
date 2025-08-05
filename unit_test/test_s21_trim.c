#include <string.h>
#include <check.h>
#include <stdlib.h>
#include "../src/s21_string.h"
// void *trim(const char *src, const char *trim_chars)
START_TEST(test1_s21_trim_not_spaces) {
    const char *s1 = "Hello, World!";
    char *res1 = "Hello, World!";
    char *s21_res1 = s21_trim(s1, " ");
    ck_assert_str_eq(s21_res1, res1);
    free(s21_res1);

    const char *s2 = "Hello   World";
    char *res2 = "Hello   World";
    char *s21_res2 = s21_trim(s2, " ");
    ck_assert_str_eq(s21_res2, res2);
    free(s21_res2);
}

END_TEST

START_TEST(test2_s21_trim_spases) {
    const char *s1 = "   Hello, World!";
    char *res1 = "Hello, World!";
    char *s21_res1 = s21_trim(s1, " ");
    ck_assert_str_eq(s21_res1, res1);
    free(s21_res1);

    const char *s2 = "Hello, World!   ";
    char *res2 = "Hello, World!";
    char *s21_res2 = s21_trim(s2, " ");
    ck_assert_str_eq(s21_res2, res2);
    free(s21_res2);
    
    const char *s3 = "   Hello, World!   ";
    char *res3 = "Hello, World!";
    char *s21_res3 = s21_trim(s3, " ");
    ck_assert_str_eq(s21_res3, res3);
    free(s21_res3);

    const char *s4 = "   Hello   World   ";
    char *res4 = "Hello   World";
    char *s21_res4 = s21_trim(s4, " ");
    ck_assert_str_eq(s21_res4, res4);
    free(s21_res4);
}
END_TEST


START_TEST(test3_s21_trim_points) {
    const char *s1 = ".Hello, World.";
    char *res1 = "Hello, World";
    char *s21_res1 = s21_trim(s1, ".");
    ck_assert_str_eq(s21_res1, res1);
    free(s21_res1);

    const char *s2 = "...Hello...World...";
    char *res2 = "Hello...World";
    char *s21_res2 = s21_trim(s2, ".");
    ck_assert_str_eq(s21_res2, res2);
    free(s21_res2);

    const char *s3 = "........";
    char *res3 = "";
    char *s21_res3 = s21_trim(s3, ".");
    ck_assert_str_eq(s21_res3, res3);
    free(s21_res3);

    const char *s4 = "."; 
    char *res4 = "."; // Исправлено: если тримим запятые, точка не тримится
    char *s21_res4 = s21_trim(s4, ",");
    ck_assert_str_eq(s21_res4, res4);
    free(s21_res4);
}
END_TEST

START_TEST(test4_s21_trim_few_chars) {
    const char *s1 = "hello, world";
    char *res1 = "ello, worl";
    const char trim_chars1[] = {'h', 'd'};
    char *s21_res1 = s21_trim(s1, trim_chars1);
    ck_assert_str_eq(s21_res1, res1);
    free(s21_res1);

    const char *s2 = "hello, world";
    char *res2 = "o, wor";
    const char trim_chars2[] = {'h', 'e', 'l', 'd'};
    char *s21_res2 = s21_trim(s2, trim_chars2);
    ck_assert_str_eq(s21_res2, res2);
    free(s21_res2);

    const char *s3 = "abcbananabac";
    char *res3 = "nan";
    const char trim_chars3[] = {'a', 'b', 'c'};
    char *s21_res3 = s21_trim(s3, trim_chars3);
    ck_assert_str_eq(s21_res3, res3);
    free(s21_res3);

    const char *s4 = "abcbaccbacbb";
    char *res4 = "";
    const char trim_chars4[] = {'a', 'b', 'c'};
    char *s21_res4 = s21_trim(s4, trim_chars4);
    ck_assert_str_eq(s21_res4, res4);
    free(s21_res4);
}
END_TEST

START_TEST(test5_s21_trim_null_chars) {
    const char *s1 = "Hello, World!";
    char *res1 = "Hello, World!";
    char *s21_res1 = s21_trim(s1, S21_NULL);
    ck_assert_str_eq(s21_res1, res1);
    free(s21_res1);

    const char *s2 = "   Hello   World   ";
    char *res2 = "Hello   World";
    char *s21_res2 = s21_trim(s2, S21_NULL);
    ck_assert_str_eq(s21_res2, res2);
    free(s21_res2);

    const char *s3 = "\n\t\rHello, World!\n\t\r";
    char *res3 = "Hello, World!";
    char *s21_res3 = s21_trim(s3, S21_NULL);
    ck_assert_str_eq(s21_res3, res3);
    free(s21_res3);

    const char *s4 = "\n \n \n \n \n";
    char *res4 = "";
    char *s21_res4 = s21_trim(s4, S21_NULL);
    ck_assert_str_eq(s21_res4, res4);
    free(s21_res4);
}
END_TEST

START_TEST(test6_s21_trim_special_chars) {
    const char *s1 = "$$$HELLO$$$WORLD$$$";
    char *res1 = "HELLO$$$WORLD";
    char *s21_res1 = s21_trim(s1, "$$$");
    ck_assert_str_eq(s21_res1, res1);
    free(s21_res1);

    const char *s2 = "%%%%%%%%%%%%";
    char *res2 = "";
    char *s21_res2 = s21_trim(s2, "%%");
    ck_assert_str_eq(s21_res2, res2);
    free(s21_res2);

    const char *s3 = "!@#$%^&*()";
    char *res3 = "";
    char *s21_res3 = s21_trim(s3, "!@#$%^&*()");
    ck_assert_str_eq(s21_res3, res3);
    free(s21_res3);
}
END_TEST

START_TEST(test7_s21_trim_null_src) {
    // В C# Trim(null) выбрасывает ArgumentNullException, здесь возвращается NULL
    const char *s1 = S21_NULL;
    char *res1 = NULL;
    char *s21_res1 = s21_trim(s1, " ");
    ck_assert_ptr_eq(s21_res1, res1);
    free(s21_res1);
    
    const char *s2 = NULL;
    char *res2 = NULL;
    char *s21_res2 = s21_trim(s2, "Hello, World!");
    ck_assert_ptr_eq(s21_res2, res2);
    free(s21_res2);
}
END_TEST

START_TEST(test8_s21_trim_im_middle) {
    const char *s1 = "a b c d e";
    char *res1 = "a b c d e";
    char *s21_res1 = s21_trim(s1, "bcd");
    ck_assert_str_eq(s21_res1, res1);
    free(s21_res1);

    const char *s2 = "a b c d e";
    char *res2 = "a b c d e";
    char *s21_res2 = s21_trim(s2, " ");
    ck_assert_str_eq(s21_res2, res2);
    free(s21_res2);

    const char *s3 = "a b c d e";
    char *res3 = "a b c d e";
    char *s21_res3 = s21_trim(s3, " c ");
    ck_assert_str_eq(s21_res3, res3);
    free(s21_res3);
}
END_TEST

START_TEST(test9_s21_trim_src_equal_trim) {
    const char *s1 = "apple banana";
    char *res1 = "banan";
    char *s21_res1 = s21_trim(s1, "apple ");
    ck_assert_str_eq(s21_res1, res1);
    free(s21_res1);

    const char *s2 = "apple banana";
    char *res2 = "";
    char *s21_res2 = s21_trim(s2, "abnple ");
    ck_assert_str_eq(s21_res2, res2);
    free(s21_res2);
}
END_TEST

Suite* s21_trim_suite(void) {
    Suite *s = suite_create("s21_trim");
    TCase *tc = tcase_create("s21_trim_core");
    tcase_add_test(tc, test1_s21_trim_not_spaces);
    tcase_add_test(tc, test2_s21_trim_spases);
    tcase_add_test(tc, test3_s21_trim_points);
    tcase_add_test(tc, test4_s21_trim_few_chars);
    tcase_add_test(tc, test5_s21_trim_null_chars);
    tcase_add_test(tc, test6_s21_trim_special_chars);
    tcase_add_test(tc, test7_s21_trim_null_src);
    tcase_add_test(tc, test8_s21_trim_im_middle);
    tcase_add_test(tc, test9_s21_trim_src_equal_trim);
    suite_add_tcase(s, tc);
    return s;
}

int s21_trim_main() {
    int failed;
    SRunner *runner = srunner_create(s21_trim_suite());
    srunner_run_all(runner, CK_NORMAL);
    failed = srunner_ntests_failed(runner);
    srunner_free(runner);
    return (failed == 0) ? 0 : failed;
}
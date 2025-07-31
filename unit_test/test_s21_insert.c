#include <check.h>
#include <stdlib.h>
#include "../src/s21_string.h"
#include <string.h>
// s21_insert(const char *src, const char *str, size_t start_index)
// Возвращает новую строку, в которой указанная строка (str) вставлена 
// в указанную позицию (start_index) в данной строке (src). 
// В случае какой-либо ошибки следует вернуть значение NULL.
START_TEST(test1_s21_insert_in_middle) {
    char *src1 = "HelloWorld";
    char *str1 = ", ";
    s21_size_t n1 = 5;
    char *s21_res1 = s21_insert(src1, str1, n1);
    ck_assert_str_eq(s21_res1, "Hello, World");
    free(s21_res1);

    char *src2 = "abcdef";
    char *str2 = "123";
    s21_size_t n2 = 3;
    char *s21_res2 = s21_insert(src2, str2, n2);
    ck_assert_str_eq(s21_res2, "abc123def");
    free(s21_res2);

    char *src3 = "abcdef";
    char *str3 = "";
    s21_size_t n3 = 2;
    char *s21_res3 = s21_insert(src3, str3, n3);
    ck_assert_str_eq(s21_res3, "abcdef");
    free(s21_res3);

    char *src4 = "foo bar";
    char *str4 = "123";
    s21_size_t n4 = 4;
    char *s21_res4 = s21_insert(src4, str4, n4);
    ck_assert_str_eq(s21_res4, "foo 123bar");
    free(s21_res4);
}
END_TEST

START_TEST(test2_s21_insert_at_begin) {
    char *src1 = "World";
    char *str1 = "Hello ";
    s21_size_t n1 = 0;
    char *s21_res1 = s21_insert(src1, str1, n1);
    ck_assert_str_eq(s21_res1, "Hello World");
    free(s21_res1);

    char *src2 = "";
    char *str2 = "Hello";
    s21_size_t n2 = 0;
    char *s21_res2 = s21_insert(src2, str2, n2);
    ck_assert_str_eq(s21_res2, "Hello");
    free(s21_res2);

    char *src3 = "Test";
    char *str3 = "";
    s21_size_t n3 = 0;
    char *s21_res3 = s21_insert(src3, str3, n3);
    ck_assert_str_eq(s21_res3, "Test");
    free(s21_res3);

    char *src4 = "data";
    char *str4 = "@@@";
    s21_size_t n4 = 0;
    char *s21_res4 = s21_insert(src4, str4, n4);
    ck_assert_str_eq(s21_res4, "@@@data");
    free(s21_res4);
}
END_TEST

START_TEST(test3_s21_insert_at_end) {
    char *src1 = "Hello";
    char *str1 = " World";
    s21_size_t n1 = 5;
    char *s21_res1 = s21_insert(src1, str1, n1);
    ck_assert_str_eq(s21_res1, "Hello World");
    free(s21_res1);

    char *src2 = "";
    char *str2 = "Test";
    s21_size_t n2 = 0;
    char *s21_res2 = s21_insert(src2, str2, n2);
    ck_assert_str_eq(s21_res2, "Test");
    free(s21_res2);

    char *src3 = "Data";
    char *str3 = "";
    s21_size_t n3 = 4;
    char *s21_res3 = s21_insert(src3, str3, n3);
    ck_assert_str_eq(s21_res3, "Data");
    free(s21_res3);

    char *src4 = "abc";
    char *str4 = "@@@";
    s21_size_t n4 = 3;
    char *s21_res4 = s21_insert(src4, str4, n4);
    ck_assert_str_eq(s21_res4, "abc@@@");
    free(s21_res4);
}
END_TEST

START_TEST(test4_s21_insert_after_end_str) {
    char *src1 = "Hello";
    char *str1 = "World";
    s21_size_t n1 = 10;
    char *s21_res1 = s21_insert(src1, str1, n1);
    ck_assert_ptr_eq(s21_res1, NULL);

    char *src2 = "abc";
    char *str2 = "123";
    s21_size_t n2 = 100;
    char *s21_res2 = s21_insert(src2, str2, n2);
    ck_assert_str_eq(s21_res2, NULL);

    char *src3 = "";
    char *str3 = "test";
    s21_size_t n3 = 1;
    char *s21_res3 = s21_insert(src3, str3, n3);
    ck_assert_str_eq(s21_res3, NULL);

    char *src4 = "foo";
    char *str4 = "bar";
    s21_size_t n4 = 3;
    char *s21_res4 = s21_insert(src4, str4, n4);
    ck_assert_str_eq(s21_res4, "foobar");
    free(s21_res4);

}
END_TEST

START_TEST(test5_s21_insert_into_empty_str) {
    char *src1 = "";
    char *str1 = "abc";
    s21_size_t n1 = 0;
    char *s21_res1 = s21_insert(src1, str1, n1);
    ck_assert_str_eq(s21_res1, "abc");
    free(s21_res1);

    char *src2 = "";
    char *str2 = "";
    s21_size_t n2 = 0;
    char *s21_res2 = s21_insert(src2, str2, n2);
    ck_assert_str_eq(s21_res2, "");
    free(s21_res2);

    char *src3 = "";
    char *str3 = "test";
    s21_size_t n3 = 1;
    char *s21_res3 = s21_insert(src3, str3, n3);
    ck_assert_ptr_eq(s21_res3, NULL);

    char *src4 = "";
    char *str4 = "@@@";
    s21_size_t n4 = 0;
    char *s21_res4 = s21_insert(src4, str4, n4);
    ck_assert_str_eq(s21_res4, "@@@");
    free(s21_res4);
}
END_TEST

START_TEST(test6_s21_insert_empty_str) {
    char *src1 = "abc";
    char *str1 = "";
    s21_size_t n1 = 0;
    char *s21_res1 = s21_insert(src1, str1, n1);
    ck_assert_str_eq(s21_res1, "abc");
    free(s21_res1);

    char *src2 = "abc";
    char *str2 = "";
    s21_size_t n2 = 1;
    char *s21_res2 = s21_insert(src2, str2, n2);
    ck_assert_str_eq(s21_res2, "abc");
    free(s21_res2);

    char *src3 = "abc";
    char *str3 = "";
    s21_size_t n3 = 3;
    char*s21_res3 = s21_insert(src3, str3, n3);
    ck_assert_str_eq(s21_res3, "abc");
    free(s21_res3);

    char *src4 = "";
    char *str4 = "";
    s21_size_t n4 = 0;
    char *s21_res4 = s21_insert(src4, str4, n4);
    ck_assert_str_eq(s21_res4, "");
    free(s21_res4);

    char *src5 = "abc";
    char *str5 = "";
    s21_size_t n5 = 10;
    char *s21_res5 = s21_insert(src5, str5, n5);
    ck_assert_ptr_eq(s21_res5, NULL);
}
END_TEST

START_TEST(test7_s21_insert_src_str_empty) {
    char *src1 = "";
    char *str1 = "";
    s21_size_t n1 = 0;
    char *s21_res1 = s21_insert(src1, str1, n1);
    ck_assert_str_eq(s21_res1, "");
    free(s21_res1);

    char *src2 = "";
    char *str2 = "";
    s21_size_t n2 = 1;
    char *s21_res2 = s21_insert(src2, str2, n2);
    ck_assert_ptr_eq(s21_res2, NULL);

    char *src3 = "";
    char *str3 = "";
    s21_size_t n3 = 100;
    char *s21_res3 = s21_insert(src3, str3, n3);
    ck_assert_ptr_eq(s21_res3, NULL);
}
END_TEST

START_TEST(test8_s21_insert_src_is_null) {
    char *src1 = S21_NULL;
    char *str1 = "abc";
    s21_size_t n1 = 0;
    char *s21_res1 = s21_insert(src1, str1, n1);
    ck_assert_ptr_eq(s21_res1, NULL);

    char *src2 = S21_NULL;
    char *str2 = "";
    s21_size_t n2 = 0;
    char *s21_res2 = s21_insert(src2, str2, n2);
    ck_assert_ptr_eq(s21_res2, NULL);

    char *src3 = S21_NULL;
    char *str3 = "test";
    s21_size_t n3 = 5;
    char* s21_res3 = s21_insert(src3, str3, n3);
    ck_assert_ptr_eq(s21_res3, NULL);
}
END_TEST

START_TEST(test9_s21_insert_str_is_null) {
    char *src1 = "abc";
    char *str1 = S21_NULL;
    s21_size_t n1 = 0;
    char *s21_res1 = s21_insert(src1, str1, n1);
    ck_assert_ptr_eq(s21_res1, NULL);

    char *src2 = "";
    char *str2 = S21_NULL;
    s21_size_t n2 = 0;
    char *s21_res2 = s21_insert(src2, str2, n2);
    ck_assert_ptr_eq(s21_res2, NULL);

    char *src3 = "test";
    char *str3 = S21_NULL;
    s21_size_t n3 = 2;
    char *s21_res3 = s21_insert(src3, str3, n3);
    ck_assert_str_eq(s21_res3, NULL);
    free(s21_res3);
}
END_TEST

START_TEST(test10_s21_insert_long_str) {
    char src1[1024];
    char str1[1024];
    s21_memset(src1, 'A', 512); src1[512] = 0;
    s21_memset(str1, 'B', 512); str1[512] = 0;
    s21_size_t n1 = 256;
    char *s21_res1 = s21_insert(src1, str1, n1);
    char expected1[1024 + 1024];
    memcpy(expected1, src1, n1);
    memcpy(expected1 + n1, str1, strlen(str1));
    memcpy(expected1 + n1 + strlen(str1), src1 + n1, strlen(src1) - n1 + 1);
    ck_assert_str_eq(s21_res1, expected1);
    free(s21_res1);

    char src2[1024];
    char str2[1024];
    s21_memset(src2, 'X', 800); src2[800] = 0;
    s21_memset(str2, 'Y', 200); str2[200] = 0;
    s21_size_t n2 = 0;
    char *s21_res2 = s21_insert(src2, str2, n2);
    char expected2[1201];
    strcpy(expected2, str2);
    strcat(expected2, src2);
    ck_assert_str_eq(s21_res2, expected2);
    free(s21_res2);

    char src3[1024];
    char str3[1024];
    memset(src3, 'M', 700); src3[700] = 0;
    memset(str3, 'N', 300); str3[300] = 0;
    s21_size_t n3 = strlen(src3);
    char *s21_res3 = s21_insert(src3, str3, n3);
    char expected3[1025 + 300];
    strcpy(expected3, src3);
    strcat(expected3, str3);
    ck_assert_str_eq(s21_res3, expected3);
    free(s21_res3);
}
END_TEST

START_TEST(test11_s21_insert_overlap_mem) {
    char *src1 = "abcdef";
    char *str1 = "123";
    s21_size_t n1 = 3;
    char src1_copy[sizeof(src1)];
    strcpy(src1_copy, src1);
    char *s21_res1 = s21_insert(src1, str1, n1);
    ck_assert_str_eq(s21_res1, "abc123def");
    ck_assert_str_eq(src1, src1_copy);
    free(s21_res1);

    char *src2 = "hello";
    char *str2 = "start-";
    s21_size_t n2 = 0;
    char src2_copy[sizeof(src2)];
    strcpy(src2_copy, src2);
    char *s21_res2 = s21_insert(src2, str2, n2);
    ck_assert_str_eq(s21_res2, "start-hello");
    ck_assert_str_eq(src2, src2_copy);
    free(s21_res2);

    char *src3 = "end";
    char *str3 = "-finish";
    s21_size_t n3 = s21_strlen(src3);
    char src3_copy[sizeof(src3)];
    strcpy(src3_copy, src3);
    char *s21_res3 = s21_insert(src3, str3, n3);
    ck_assert_str_eq(s21_res3, "end-finish");
    ck_assert_str_eq(src3, src3_copy);
    free(s21_res3);
}
END_TEST

START_TEST(test12_s21_insert_with_spec_chars) {
    char *src1 = "HelloWorld";
    char *str1 = "\n";
    s21_size_t n1 = 5;
    char *s21_res1 = s21_insert(src1, str1, n1);
    ck_assert_str_eq(s21_res1, "Hello\nWorld");
    free(s21_res1);

    char *src2 = "foo bar";
    char *str2 = "\t";
    s21_size_t n2 = 3;
    char *s21_res2 = s21_insert(src2, str2, n2);
    ck_assert_str_eq(s21_res2, "foo\t bar");
    free(s21_res2);

    char *src3 = "C:Users";
    char *str3 = "\\";
    s21_size_t n3 = 2;
    char *s21_res3 = s21_insert(src3, str3, n3);
    ck_assert_str_eq(s21_res3, "C:\\Users");
    free(s21_res3);

    char *src4 = "abc";
    char *str4 = "\n\t\\";
    s21_size_t n4 = 1;
    char *s21_res4 = s21_insert(src4, str4, n4);
    ck_assert_str_eq(s21_res4, "a\n\t\\bc");
    free(s21_res4);

    char *src5 = "abcdef";
    char str5[] = {'X', '\0', 'Y', 0};
    s21_size_t n5 = 3;
    char* s21_res5 = s21_insert(src5, str5, n5);
    ck_assert_str_eq(s21_res5, "abcXdef");
    free(s21_res5);
}
END_TEST


Suite* s21_insert_suite(void) {
    Suite *s = suite_create("s21_insert");
    TCase *tc = tcase_create("s21_insert_core");
    tcase_add_test(tc, test1_s21_insert_in_middle);
    tcase_add_test(tc, test2_s21_insert_at_begin);
    tcase_add_test(tc, test3_s21_insert_at_end);
    tcase_add_test(tc, test4_s21_insert_after_end_str);
    tcase_add_test(tc, test5_s21_insert_into_empty_str);
    tcase_add_test(tc, test6_s21_insert_empty_str);
    tcase_add_test(tc, test7_s21_insert_src_str_empty);
    tcase_add_test(tc, test8_s21_insert_src_is_null);
    tcase_add_test(tc, test9_s21_insert_str_is_null);
    tcase_add_test(tc, test10_s21_insert_long_str);
    tcase_add_test(tc, test11_s21_insert_overlap_mem);
    tcase_add_test(tc, test12_s21_insert_with_spec_chars);

    suite_add_tcase(s, tc);
    return s;
}

int s21_insert_main() {
    int failed;
    SRunner *runner = srunner_create(s21_insert_suite());
    srunner_run_all(runner, CK_NORMAL);
    failed = srunner_ntests_failed(runner);
    srunner_free(runner);
    return (failed == 0) ? 0 : failed;
}
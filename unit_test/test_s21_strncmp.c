#include <string.h>
#include <check.h>
#include "../src/s21_string.h"
// int strncmp(const char *s1, const char *s2, size_t n)
START_TEST(test1_s21_strncmp_equal_strings) {
    struct { const char *a; const char *b; } cases[] = {
        {"apple", "apple"},
        {"test1", "test1"},
        {"caseA", "caseA"}
    };
    for (size_t i = 0; i < sizeof(cases)/sizeof(cases[0]); i++) {
        int res = strncmp(cases[i].a, cases[i].b, 5);
        int s21_res = s21_strncmp(cases[i].a, cases[i].b, 5);
        ck_assert((res < 0 && s21_res < 0) || (res > 0 && s21_res > 0) || (res == 0 && s21_res == 0));
    }
}
END_TEST

START_TEST(test2_s21_strncmp_different_last_char) {
    struct { const char *a; const char *b; } cases[] = {
        {"apple", "apply"},
        {"test1", "test2"},
        {"caseA", "caseB"}
    };
    for (size_t i = 0; i < sizeof(cases)/sizeof(cases[0]); i++) {
        int res = strncmp(cases[i].a, cases[i].b, 5);
        int s21_res = s21_strncmp(cases[i].a, cases[i].b, 5);
        ck_assert((res < 0 && s21_res < 0) || (res > 0 && s21_res > 0) || (res == 0 && s21_res == 0));
    }
}
END_TEST

START_TEST(test3_s21_strncmp_different_first_char) {
    struct { const char *a; const char *b; } cases[] = {
        {"kbcde", "abcde"},
        {"Zebra", "apple"},
        {"9start", "1start"}
    };
    for (size_t i = 0; i < sizeof(cases)/sizeof(cases[0]); i++) {
        int res = strncmp(cases[i].a, cases[i].b, 5);
        int s21_res = s21_strncmp(cases[i].a, cases[i].b, 5);
        ck_assert((res < 0 && s21_res < 0) || (res > 0 && s21_res > 0) || (res == 0 && s21_res == 0));
    }
}
END_TEST

START_TEST(test4_s21_strncmp_embedded_null) {
    struct { const char *a; const char *b; } cases[] = {
        {"abc\0def", "abc\0ghi"},
        {"1\0xxxx", "1\0yyyy"},
        {"\0hidden", "\0data"}
    };
    for (size_t i = 0; i < sizeof(cases)/sizeof(cases[0]); i++) {
        int res = strncmp(cases[i].a, cases[i].b, 6);
        int s21_res = s21_strncmp(cases[i].a, cases[i].b, 6);
        ck_assert((res < 0 && s21_res < 0) || (res > 0 && s21_res > 0) || (res == 0 && s21_res == 0));
    }
}
END_TEST

START_TEST(test5_s21_strncmp_zero_length) {
    struct { const char *a; const char *b; } cases[] = {
        {"test3", "test123"},
        {"", ""},
        {"abc", "def"}
    };
    for (size_t i = 0; i < sizeof(cases)/sizeof(cases[0]); i++) {
        int res = strncmp(cases[i].a, cases[i].b, 0);
        int s21_res = s21_strncmp(cases[i].a, cases[i].b, 0);
        ck_assert((res < 0 && s21_res < 0) || (res > 0 && s21_res > 0) || (res == 0 && s21_res == 0));
    }
}
END_TEST

START_TEST(test6_s21_strncmp_same_prefix_longer_string) {
    struct { const char *a; const char *b; } cases[] = {
        {"hello", "hellolonger"},
        {"short", "shorter"},
        {"pre", "prefix"}
    };
    for (size_t i = 0; i < sizeof(cases)/sizeof(cases[0]); i++) {
        int res = strncmp(cases[i].a, cases[i].b, 5);
        int s21_res = s21_strncmp(cases[i].a, cases[i].b, 5);
        ck_assert((res < 0 && s21_res < 0) || (res > 0 && s21_res > 0) || (res == 0 && s21_res == 0));
    }
}
END_TEST

START_TEST(test7_s21_strncmp_high_ascii_values) {
    struct { const char *a; const char *b; } cases[] = {
        {"\xff\xfe", "\xfe\xff"},
        {"\x80\x81", "\x7f\x82"},
        {"\xff\xff", "\xff\xfe"}
    };
    for (size_t i = 0; i < sizeof(cases)/sizeof(cases[0]); i++) {
        int res = strncmp(cases[i].a, cases[i].b, 2);
        int s21_res = s21_strncmp(cases[i].a, cases[i].b, 2);
        ck_assert((res < 0 && s21_res < 0) || (res > 0 && s21_res > 0) || (res == 0 && s21_res == 0));
    }
}
END_TEST

START_TEST(test8_s21_strncmp_buffer_overflow) {
    struct { const char *a; const char *b;} cases[] = {
        {"abcdefghij", "abcdefghijk"},
        {"short", "longer"},
        {"x", "y"}
    };
    for (size_t i = 0; i < sizeof(cases)/sizeof(cases[0]); i++) {
        int res = strncmp(cases[i].a, cases[i].b, 100);
        int s21_res = s21_strncmp(cases[i].a, cases[i].b, 100);
        ck_assert((res < 0 && s21_res < 0) || (res > 0 && s21_res > 0) || (res == 0 && s21_res == 0));
    }
}
END_TEST

START_TEST(test9_s21_strncmp_empty_strings) {
    struct { const char *a; const char *b; } cases[] = {
        {"", ""}
    };
    for (size_t i = 0; i < sizeof(cases)/sizeof(cases[0]); i++) {
        int res = strncmp(cases[i].a, cases[i].b, 1);
        int s21_res = s21_strncmp(cases[i].a, cases[i].b, 1);
        ck_assert((res < 0 && s21_res < 0) || (res > 0 && s21_res > 0) || (res == 0 && s21_res == 0));
    }
}
END_TEST

START_TEST(test10_s21_strncmp_partial_compare) {
    struct { const char *a; const char *b; } cases[] = {
        {"abcdef", "abcxyz"},
        {"123456", "123abc"},
        {"qwerty", "qweasd"}
    };
    for (size_t i = 0; i < sizeof(cases)/sizeof(cases[0]); i++) {
        int res = strncmp(cases[i].a, cases[i].b, 3);
        int s21_res = s21_strncmp(cases[i].a, cases[i].b, 3);
        ck_assert((res < 0 && s21_res < 0) || (res > 0 && s21_res > 0) || (res == 0 && s21_res == 0));
    }
}
END_TEST

Suite *s21_strncmp_suite(void) {
    Suite *s = suite_create("s21_strncmp");
    TCase *tc = tcase_create("s21_strncmp_core");
    tcase_add_test(tc, test1_s21_strncmp_equal_strings);
    tcase_add_test(tc, test2_s21_strncmp_different_last_char);
    tcase_add_test(tc, test3_s21_strncmp_different_first_char);
    tcase_add_test(tc, test4_s21_strncmp_embedded_null);
    tcase_add_test(tc, test5_s21_strncmp_zero_length);
    tcase_add_test(tc, test6_s21_strncmp_same_prefix_longer_string);
    tcase_add_test(tc, test7_s21_strncmp_high_ascii_values);
    tcase_add_test(tc, test8_s21_strncmp_buffer_overflow);
    tcase_add_test(tc, test9_s21_strncmp_empty_strings);
    tcase_add_test(tc, test10_s21_strncmp_partial_compare);
    suite_add_tcase(s, tc);
    return s;
}

int s21_strncmp_main() {
    int failed;
    SRunner *runner = srunner_create(s21_strncmp_suite());
    srunner_run_all(runner, CK_NORMAL);
    failed = srunner_ntests_failed(runner);
    srunner_free(runner);
    return (failed == 0) ? 0 : failed;
}
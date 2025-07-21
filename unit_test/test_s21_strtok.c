#include <string.h>
#include <check.h>
#include "../src/s21_string.h"
// char *strtok(char *str, const char *delim)
// Сравнение strtok и s21_strtok
START_TEST(test1_s21_strtok_simple_tokenization) {
    char str[] = "apple,banana,orange";
    const char delim[] = ",";
    char *s21_result = s21_strtok(str, delim);
    char *result = strtok(str, delim);
    while (s21_result != NULL && result != NULL) {
        ck_assert_ptr_eq(s21_result, result);
        s21_result = s21_strtok(NULL, delim);
        result = strtok(NULL, delim);
    }
    ck_assert_ptr_eq(s21_result, result);
}
END_TEST

START_TEST(test2_s21_strtok_multiple_delimiters) {
    char str[] = "a;b,c;d";
    const char delim[] = ",;:";
    char *s21_result = s21_strtok(str, delim);
    char *result = strtok(str, delim);
    while (s21_result != NULL && result != NULL) {
        ck_assert_ptr_eq(s21_result, result);
        s21_result = s21_strtok(NULL, delim);
        result = strtok(NULL, delim);
    }
    ck_assert_ptr_eq(s21_result, result);
}
END_TEST

START_TEST(test3_s21_strtok_empty_string) {
    char str[] = "";
    const char delim[] = ",";
    char *s21_result = s21_strtok(str, delim);
    char *result = strtok(str, delim);
    ck_assert_ptr_eq(s21_result, result);
}
END_TEST

START_TEST(test4_s21_strtok_delimiter_at_beginning) {
    char str[] = ",abc,def";
    const char delim[] = ",";
    char *s21_result = s21_strtok(str, delim);
    char *result = strtok(str, delim);
    int i = 0;
    while (s21_result != NULL && result != NULL) {
        ck_assert_ptr_eq(s21_result, result);
        s21_result = s21_strtok(NULL, delim);
        result = strtok(NULL, delim);
        i++;
    }
    ck_assert_int_eq(i, 2); // должно быть 2 токена: "abc", "def"
}
END_TEST

START_TEST(test5_s21_strtok_delimiter_at_end) {
    char str[] = "abc,def,";
    const char delim[] = ",";
    char *s21_result = s21_strtok(str, delim);
    char *result = strtok(str, delim);
    int i = 0;
    while (s21_result != NULL && result != NULL) {
        ck_assert_ptr_eq(s21_result, result);
        s21_result = s21_strtok(NULL, delim);
        result = strtok(NULL, delim);
        i++;
    }
    ck_assert_int_eq(i, 2); // должно быть 2 токена: "abc", "def"
}
END_TEST

START_TEST(test6_s21_strtok_consecutive_delimiters) {
    char str[] = "a,,b,,c";
    const char delim[] = ",";
    char *s21_result = s21_strtok(str, delim);
    char *result = strtok(str, delim);
    int i = 0;
    while (s21_result != NULL && result != NULL) {
        ck_assert_ptr_eq(s21_result, result);
        s21_result = s21_strtok(NULL, delim);
        result = strtok(NULL, delim);
        i++;
    }
    ck_assert_int_eq(i, 3); // должно быть 3 токена: "a", "b", "c"
}
END_TEST

START_TEST(test7_s21_strtok_null_delimiter_input) {
    char str[] = "apple,banana,orange";
    const char delim[] = ",";
    char *s21_result = s21_strtok(str, delim);
    char *result = strtok(str, delim);
    while (s21_result != NULL && result != NULL) {
        ck_assert_ptr_eq(s21_result, result);
        s21_result = s21_strtok(NULL, NULL); // второй аргумент NULL
        result = strtok(NULL, NULL);
    }
    ck_assert_ptr_eq(s21_result, result);
}
END_TEST

START_TEST(test8_s21_strtok_null_pointer_input) {
    char *s21_result = s21_strtok(NULL, ",");
    char *result = strtok(NULL, ",");
    ck_assert_ptr_eq(s21_result, result);
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
    tcase_add_test(tc, test7_s21_strtok_null_delimiter_input);
    tcase_add_test(tc, test8_s21_strtok_null_pointer_input);
    suite_add_tcase(s, tc);
    return s;
}

int main() {
    int failed;
    SRunner *runner = srunner_create(s21_strtok_suite());
    srunner_run_all(runner, CK_NORMAL);
    failed = srunner_ntests_failed(runner);
    srunner_free(runner);
    return (failed == 0) ? 0 : 1;
}
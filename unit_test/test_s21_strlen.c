#include <string.h>
#include <check.h>
// size_t strlen(const char *s)
// Сравнение strlen и s21_strlen
/*
START_TEST(test1_s21_strlen) {
    // s21_code here
    // code here
    ck_assert_int_eq(result, s21_result)
}
END_TEST

START_TEST(test2_s21_strlen) {
    // s21_code here
    // code here
    ck_assert_int_eq(result, s21_result)
}
END_TEST

START_TEST(test3_s21_strlen) {
    // s21_code here
    // code here
    ck_assert_int_eq(result, s21_result)
}
END_TEST

START_TEST(test4_s21_strlen) {
    // s21_code here
    // code here
    ck_assert_int_eq(result, s21_result)
}
END_TEST

START_TEST(test5_s21_strlen) {
    // s21_code here
    // code here
    ck_assert_int_eq(result, s21_result)
}
END_TEST

START_TEST(test6_s21_strlen) {
    // s21_code here
    // code here
    ck_assert_int_eq(result, s21_result)
}
END_TEST

START_TEST(test7_s21_strlen) {
    // s21_code here
    // code here
    ck_assert_int_eq(result, s21_result)
}
END_TEST

START_TEST(test8_s21_strlen) {
    // s21_code here
    // code here
    ck_assert_int_eq(result, s21_result)
}
END_TEST
*/

Suite *s21_strlen_suite(void) {
    Suite *s = suite_create("s21_strlen");
    TCase *tc = tcase_create("s21_strlen_core");
    // tcase_add_test(tc, test1_s21_strlen);
    // tcase_add_test(tc, test2_s21_strlen);
    // tcase_add_test(tc, test3_s21_strlen);
    // tcase_add_test(tc, test4_s21_strlen);
    // tcase_add_test(tc, test5_s21_strlen);
    // tcase_add_test(tc, test6_s21_strlen);
    // tcase_add_test(tc, test7_s21_strlen);
    // tcase_add_test(tc, test8_s21_strlen);
    suite_add_tcase(s, tc);
    return s;
}

int main() {
    int failed;
    SRunner *runner = srunner_create(s21_strlen_suite());
    srunner_run_all(runner, CK_NORMAL);
    failed = srunner_ntests_failed(runner);
    srunner_free(runner);
    return (failed == 0) ? 0 : 1;
}
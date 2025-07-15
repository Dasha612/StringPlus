// test_hello.c
#include <check.h>
#include <stdio.h>

START_TEST(test_hello)
{
    ck_assert_int_eq(1, 1);
}
END_TEST

Suite *hello_suite(void) {
    Suite *s = suite_create("Hello");
    TCase *tc = tcase_create("Core");
    tcase_add_test(tc, test_hello);
    suite_add_tcase(s, tc);
    return s;
}

int main() {
    int failed;
    SRunner *runner = srunner_create(hello_suite());
    srunner_run_all(runner, CK_NORMAL);
    failed = srunner_ntests_failed(runner);
    srunner_free(runner);
    return (failed == 0) ? 0 : 1;
}
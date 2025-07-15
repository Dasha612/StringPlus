#include <string.h>
#include <check.h>

START_TEST(test_memchr) {








Suite *memchr_suite(void) {
    Suite *s = suite_create("memchr");
    TCase *tc_core = tcase_create("Core");
    tcase_add_test(tc_core, test_memchr);
    suite_add_tcase(s, tc_core);
    return s;
}

int main() {
    int number_failed;
    SRunner *runner = srunner_create(memchr_suite());
}
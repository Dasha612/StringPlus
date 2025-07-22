#include <check.h>

Suite *s21_memchr_suite(void);
Suite *s21_memcmp_suite(void);
Suite *s21_memcpy_suite(void);
Suite *s21_memset_suite(void);
Suite *s21_strchr_suite(void);
Suite *s21_strcspn_suite(void);
Suite *s21_strerror_suite(void);
Suite *s21_strlen_suite(void);
Suite *s21_strncat_suite(void);
Suite *s21_strncmp_suite(void);
Suite *s21_strncpy_suite(void);
Suite *s21_strpbrk_suite(void);
Suite *s21_strrchr_suite(void);
Suite *s21_strstr_suite(void);
// Suite *sprintf_suite(void);
// Suite *sscanf_suite(void);
// Suite *toupper_suite(void);
// Suite *tolower_suite(void);
// Suite *insert_suite(void);
// Suite *trim_suite(void);

int s21_memchr_main(void);
int s21_memcmp_main(void);
int s21_memcpy_main(void);
int s21_memset_main(void);
int s21_strchr_main(void);
int s21_strcspn_main(void);
int s21_strerror_main(void);
int s21_strlen_main(void);
int s21_strncat_main(void);
int s21_strncmp_main(void);
int s21_strncpy_main(void);
int s21_strpbrk_main(void);
int s21_strrchr_main(void);
int s21_strstr_main(void);
// int sprintf_main(void);
// int sscanf_main(void);
// int toupper_main(void);
// int tolower_main(void);
// int insert_main(void);
// int trim_main(void);

int main(void) {
    int failed = 0;
    failed += s21_memchr_main();
    failed += s21_memcmp_main();
    failed += s21_memcpy_main();
    failed += s21_memset_main();
    failed += s21_strchr_main();
    failed += s21_strcspn_main();
    failed += s21_strerror_main();
    failed += s21_strlen_main();
    failed += s21_strncat_main();
    failed += s21_strncmp_main();
    failed += s21_strncpy_main();
    failed += s21_strpbrk_main();
    failed += s21_strrchr_main();
    failed += s21_strstr_main();
    // failed += sprintf_main();
    // failed += sscanf_main();
    // failed += toupper_main();
    // failed += tolower_main();
    // failed += insert_main();
    // failed += trim_main();

    return (failed == 0) ? 0 : 1;


}

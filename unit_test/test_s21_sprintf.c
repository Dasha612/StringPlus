#include <check.h>
#include <stdlib.h>
#include "../src/s21_string.h"
// int sprintf(char *str, const char *format, ...) 
// отправляет форматированный вывод в строку, на которую указывает str.
START_TEST(test1_s21_sprintf_char) {
    char s21_buff[100];
    char buff[100];
    
    int s21_res1 = s21_sprintf(s21_buff, "Hello %c!", 'A');
    int res1 = sprintf(buff, "Hello %c!", 'A');
    ck_assert_int_eq(s21_res1, res1);
    ck_assert_str_eq(s21_buff, buff);

    int s21_res2 = s21_sprintf(s21_buff, "Newline: %c end", '\n' );
    int res2 = sprintf(buff, "Newline: %c end", '\n' );
    ck_assert_int_eq(s21_res2, res2);
    ck_assert_str_eq(s21_buff, buff);
    
    int s21_res3 = s21_sprintf(s21_buff, "DEL: %c", 127);
    int res3 = sprintf(buff, "DEL: %c", 127);
    ck_assert_int_eq(s21_res3, res3);
    ck_assert_str_eq(s21_buff, buff);

    int s21_res4 = s21_sprintf(s21_buff, "%c %c %c,", 'X', 'Y', 'Z');
    int res4 = sprintf(buff, "%c %c %c,", 'X', 'Y', 'Z');
    ck_assert_int_eq(s21_res4, res4);
    ck_assert_str_eq(s21_buff, buff);

    int s21_res5 = s21_sprintf(s21_buff, "Negative char: %c", -65);
    int res5 = sprintf(buff, "Negative char: %c", -65);
    ck_assert_int_eq(s21_res5, res5);
    ck_assert_str_eq(s21_buff, buff);

    int s21_res6 = s21_sprintf(s21_buff, "A");
    int res6 = sprintf(buff, "A");
    ck_assert_int_eq(s21_res6, res6);
    ck_assert_str_eq(s21_buff, buff);
}
END_TEST

START_TEST(test2_s21_sprintf_char_width) {
    char s21_buff[100];
    char buff[100];

    int s21_res1 = s21_sprintf(s21_buff, "|%5c|", 'X');
    int res1 = sprintf(buff, "|%5c|", 'X');
    ck_assert_int_eq(s21_res1, res1);
    ck_assert_str_eq(s21_buff, buff);

    int s21_res2 = s21_sprintf(s21_buff, "|%1c|", 'X');
    int res2 = sprintf(buff, "|%1c|", 'X');
    ck_assert_int_eq(s21_res2, res2);
    ck_assert_str_eq(s21_buff, buff);

    int s21_res3 = s21_sprintf(s21_buff, "|%3c|", 'A');
    int res3 = sprintf(buff, "|%3c|", 'A');
    ck_assert_int_eq(s21_res3, res3);
    ck_assert_str_eq(s21_buff, buff);

    int s21_res4 = s21_sprintf(s21_buff, "|%2c|%2c|%2c|", 'X', 'Y', 'Z');
    int res4 = sprintf(buff, "|%2c|%2c|%2c|", 'X', 'Y', 'Z');
    ck_assert_int_eq(s21_res4, res4);
    ck_assert_str_eq(s21_buff, buff);

    int s21_res5 = s21_sprintf(s21_buff, "|%10c|", 'Z');
    int res5 = sprintf(buff, "|%10c|", 'Z');
    ck_assert_int_eq(s21_res5, res5);
    ck_assert_str_eq(s21_buff, buff);
}
END_TEST


START_TEST(test3_s21_sprintf_str) {
    char s21_buff[200];
    char buff[200];

    int s21_res1 = s21_sprintf(s21_buff, "String %s", "hello");
    int res1 = sprintf(buff, "String %s", "hello");
    ck_assert_int_eq(s21_res1, res1);
    ck_assert_str_eq(s21_buff, buff);

    int s21_res2 = s21_sprintf(s21_buff, "Empty: '%s' end", "");
    int res2 = sprintf(buff, "Empty: '%s' end", "");
    ck_assert_int_eq(s21_res2, res2);
    ck_assert_str_eq(s21_buff, buff);

    int s21_res3 = s21_sprintf(s21_buff, "%s %s %s", "abc", "", "xyz");
    int res3 = sprintf(buff, "%s %s %s", "abc", "", "xyz");
    ck_assert_int_eq(s21_res3, res3);
    ck_assert_str_eq(s21_buff, buff);

    int s21_res4 = s21_sprintf(s21_buff, "%s", "one");
    int res4 = sprintf(buff, "%s", "one");
    ck_assert_int_eq(s21_res4, res4);
    ck_assert_str_eq(s21_buff, buff);
}
END_TEST

START_TEST(test4_s21_sprintf_str_width) {
    char s21_buff[200];
    char buff[200];

    int s21_res1 = s21_sprintf(s21_buff, "|%10s|", "hi");
    int res1 = sprintf(buff, "|%10s|", "hi");
    ck_assert_int_eq(s21_res1, res1);
    ck_assert_str_eq(s21_buff, buff);

    int s21_res2 = s21_sprintf(s21_buff, "|%5s|", "hello");
    int res2 = sprintf(buff, "|%5s|", "hello");
    ck_assert_int_eq(s21_res2, res2);
    ck_assert_str_eq(s21_buff, buff);

    int s21_res3 = s21_sprintf(s21_buff, "|%2s|", "hello");
    int res3 = sprintf(buff, "|%2s|", "hello");
    ck_assert_int_eq(s21_res3, res3);
    ck_assert_str_eq(s21_buff, buff);

    int s21_res4 = s21_sprintf(s21_buff, "|%20s|", "abc");
    int res4 = sprintf(buff, "|%20s|", "abc");
    ck_assert_int_eq(s21_res4, res4);
    ck_assert_str_eq(s21_buff, buff);

    int s21_res5 = s21_sprintf(s21_buff, "|%5s|", "");
    int res5 = sprintf(buff, "|%5s|", "");
    ck_assert_int_eq(s21_res5, res5);
    ck_assert_str_eq(s21_buff, buff);
}
END_TEST

START_TEST(test5_s21_sprintf_str_precision) {
    char s21_buff[200];
    char buff[200];

    int s21_res1 = s21_sprintf(s21_buff, "|%.0s|", "hello");
    int res1 = sprintf(buff, "|%.0s|", "hello");
    ck_assert_int_eq(s21_res1, res1);
    ck_assert_str_eq(s21_buff, buff);

    int s21_res2 = s21_sprintf(s21_buff, "|%.0s|", "");
    int res2 = sprintf(buff, "|%.0s|", "");
    ck_assert_int_eq(s21_res2, res2);
    ck_assert_str_eq(s21_buff, buff);

    int s21_res3 = s21_sprintf(s21_buff, "|%.3s|", "hello");
    int res3 = sprintf(buff, "|%.3s|", "hello");
    ck_assert_int_eq(s21_res3, res3);
    ck_assert_str_eq(s21_buff, buff);

    int s21_res4 = s21_sprintf(s21_buff, "|%.5s|", "hello");
    int res4 = sprintf(buff, "|%.5s|", "hello");
    ck_assert_int_eq(s21_res4, res4);
    ck_assert_str_eq(s21_buff, buff);

    int s21_res5 = s21_sprintf(s21_buff, "|%.10s|", "hello");
    int res5 = sprintf(buff, "|%.10s|", "hello");
    ck_assert_int_eq(s21_res5, res5);
    ck_assert_str_eq(s21_buff, buff);

    int s21_res6 = s21_sprintf(s21_buff, "|%.1s|%.2s|%.3s|", "abc", "xyz", "12345");
    int res6 = sprintf(buff, "|%.1s|%.2s|%.3s|", "abc", "xyz", "12345");
    ck_assert_int_eq(s21_res6, res6);
    ck_assert_str_eq(s21_buff, buff);
}
END_TEST

START_TEST(test6_s21_sprintf_str_width_precision) {
    char s21_buff[512];
    char buff[512];

    int s21_res1 = s21_sprintf(s21_buff, "|%10.3s|", "hello");
    int res1 = sprintf(buff, "|%10.3s|", "hello");
    ck_assert_int_eq(s21_res1, res1);
    ck_assert_str_eq(s21_buff, buff);

    int s21_res2 = s21_sprintf(s21_buff, "|%5.10s|", "hi");
    int res2 = sprintf(buff, "|%5.10s|", "hi");
    ck_assert_int_eq(s21_res2, res2);
    ck_assert_str_eq(s21_buff, buff);

    int s21_res3 = s21_sprintf(s21_buff, "|%5.5s|", "hello");
    int res3 = sprintf(buff, "|%5.5s|", "hello");
    ck_assert_int_eq(s21_res3, res3);
    ck_assert_str_eq(s21_buff, buff);

    int s21_res4 = s21_sprintf(s21_buff, "|%2.3s|", "hello");
    int res4 = sprintf(buff, "|%2.3s|", "hello");
    ck_assert_int_eq(s21_res4, res4);
    ck_assert_str_eq(s21_buff, buff);

    int s21_res5 = s21_sprintf(s21_buff, "|%8.0s|", "test");
    int res5 = sprintf(buff, "|%8.0s|", "test");
    ck_assert_int_eq(s21_res5, res5);
    ck_assert_str_eq(s21_buff, buff);

    int s21_res6 = s21_sprintf(s21_buff, "|%5.3s|", "");
    int res6 = sprintf(buff, "|%5.3s|", "");
    ck_assert_int_eq(s21_res6, res6);
    ck_assert_str_eq(s21_buff, buff);

    int s21_res7 = s21_sprintf(s21_buff, "|%5.3s|", " ");
    int res7 = sprintf(buff, "|%5.3s|", " ");
    ck_assert_int_eq(s21_res7, res7);
    ck_assert_str_eq(s21_buff, buff);

    int s21_res8 = s21_sprintf(s21_buff, "|%15.2s|", "abcde");
    int res8 = sprintf(buff, "|%15.2s|", "abcde");
    ck_assert_int_eq(s21_res8, res8);
    ck_assert_str_eq(s21_buff, buff);
}
END_TEST

START_TEST(test7_s21_sprintf_dec) {
    char s21_buff[512];
    char buff[512];

    int s21_res1 = s21_sprintf(s21_buff, "Dec: %d", 123);
    int res1 = sprintf(buff, "Dec: %d", 123);
    ck_assert_int_eq(s21_res1, res1);
    ck_assert_str_eq(s21_buff, buff);

    int s21_res2 = s21_sprintf(s21_buff, "Dec: %d", -456);
    int res2 = sprintf(buff, "Dec: %d", -456);
    ck_assert_int_eq(s21_res2, res2);
    ck_assert_str_eq(s21_buff, buff);

    int s21_res3 = s21_sprintf(s21_buff, "Dec: %d", 0);
    int res3 = sprintf(buff, "Dec: %d", 0);
    ck_assert_int_eq(s21_res3, res3);
    ck_assert_str_eq(s21_buff, buff);

    int s21_res4 = s21_sprintf(s21_buff, "Max: %d", 2147483647);
    int res4 = sprintf(buff, "Max: %d", 2147483647);
    ck_assert_int_eq(s21_res4, res4);
    ck_assert_str_eq(s21_buff, buff);

    int s21_res5 = s21_sprintf(s21_buff, "Min: %d", -2147483647);
    int res5 = sprintf(buff, "Min: %d", -2147483647);
    ck_assert_int_eq(s21_res5, res5);
    ck_assert_str_eq(s21_buff, buff);

    int s21_res6 = s21_sprintf(s21_buff, "Large: %d", 1999999999);
    int res6 = sprintf(buff, "Large: %d", 1999999999);
    ck_assert_int_eq(s21_res6, res6);
    ck_assert_str_eq(s21_buff, buff);

    int s21_res7 = s21_sprintf(s21_buff, "%d%d%d", 1, -1, 0);
    int res7 = sprintf(buff, "%d%d%d", 1, -1, 0);
    ck_assert_int_eq(s21_res7, res7);
    ck_assert_str_eq(s21_buff, buff);

    int s21_res8 = s21_sprintf(s21_buff, "%d %d %d", 1, 2, 3);
    int res8 = sprintf(buff, "%d %d %d", 1, 2, 3);
    ck_assert_int_eq(s21_res8, res8);
    ck_assert_str_eq(s21_buff, buff);
}
END_TEST

START_TEST(test8_s21_sprintf_dec_flags) {
    char s21_buff[512];
    char buff[512];

    int s21_res1 = s21_sprintf(s21_buff, "%+d %+d", 42, -42);
    int res1 = sprintf(buff, "%+d %+d", 42, -42);
    ck_assert_int_eq(s21_res1, res1);
    ck_assert_str_eq(s21_buff, buff);

    int s21_res2 = s21_sprintf(s21_buff, "|%-10d|", 123);
    int res2 = sprintf(buff, "|%-10d|", 123);
    ck_assert_int_eq(s21_res2, res2);
    ck_assert_str_eq(s21_buff, buff);

    int s21_res3 = s21_sprintf(s21_buff, "% d % d", 77, -77);
    int res3 = sprintf(buff, "% d % d", 77, -77);
    ck_assert_int_eq(s21_res3, res3);
    ck_assert_str_eq(s21_buff, buff);

    int s21_res4 = s21_sprintf(s21_buff, "%+d % d", 0, 0);
    int res4 = sprintf(buff, "%+d % d", 0, 0);
    ck_assert_int_eq(s21_res4, res4);
    ck_assert_str_eq(s21_buff, buff);

    int s21_res6 = s21_sprintf(s21_buff, "|%-8d|%+-10d|% -6d|", -500, 999, 42);
    int res6 = sprintf(buff, "|%-8d|%+-10d|% -6d|", -500, 999, 42);
    ck_assert_int_eq(s21_res6, res6);
    ck_assert_str_eq(s21_buff, buff);    
}
END_TEST

START_TEST(test9_s21_sprintf_dec_width) {
    char s21_buff[512];
    char buff[512];

    int s21_res1 = s21_sprintf(s21_buff, "|%8d|%2d|", 123, 12345);
    int res1 = sprintf(buff, "|%8d|%2d|", 123, 12345);
    ck_assert_int_eq(s21_res1, res1);
    ck_assert_str_eq(s21_buff, buff);

    int s21_res2 = s21_sprintf(s21_buff, "|%5d|%0d|", 12345, 42);
    int res2 = sprintf(buff, "|%5d|%0d|", 12345, 42);
    ck_assert_int_eq(s21_res2, res2);
    ck_assert_str_eq(s21_buff, buff);

    int s21_res3 = s21_sprintf(s21_buff, "|%0d|", 0);
    int res3 = sprintf(buff, "|%0d|", 0);
    ck_assert_int_eq(s21_res3, res3);
    ck_assert_str_eq(s21_buff, buff);

    int s21_res4 = s21_sprintf(s21_buff, "|%7d|%12d|", -100, -999);
    int res4 = sprintf(buff, "|%7d|%12d|", -100, -999);
    ck_assert_int_eq(s21_res4, res4);
    ck_assert_str_eq(s21_buff, buff);

    int s21_res5 = s21_sprintf(s21_buff, "|%3d|%4d|%5d|", 1, -1, 0);
    int res5 = sprintf(buff, "|%3d|%4d|%5d|", 1, -1, 0);
    ck_assert_int_eq(s21_res5, res5);
    ck_assert_str_eq(s21_buff, buff);
}
END_TEST

START_TEST(test10_s21_sprintf_dec_precision) {
    char s21_buff[512];
    char buff[512];

    int s21_res1 = s21_sprintf(s21_buff, "|%.5d|%.3d|", 42, 123);
    int res1 = sprintf(buff, "|%.5d|%.3d|", 42, 123);
    ck_assert_int_eq(s21_res1, res1);
    ck_assert_str_eq(s21_buff, buff);

    int s21_res2 = s21_sprintf(s21_buff, "|%.2d|", 12345);
    int res2 = sprintf(buff, "|%.2d|", 12345);
    ck_assert_int_eq(s21_res2, res2);
    ck_assert_str_eq(s21_buff, buff);

    int s21_res3 = s21_sprintf(s21_buff, "|%.0d|%.0d|", 0, 42);
    int res3 = sprintf(buff, "|%.0d|%.0d|", 0, 42);
    ck_assert_int_eq(s21_res3, res3);
    ck_assert_str_eq(s21_buff, buff);

    int s21_res4 = s21_sprintf(s21_buff, "|%-5d|%.d|", 100, 0);
    int res4 = sprintf(buff, "|%-5d|%.d|", 100, 0);
    ck_assert_int_eq(s21_res4, res4);
    ck_assert_str_eq(s21_buff, buff);

    int s21_res5 = s21_sprintf(s21_buff, "|%.6d|%.10d|", -777, 0);
    int res5 = sprintf(buff, "|%.6d|%.10d|", -777, 0);
    ck_assert_int_eq(s21_res5, res5);
    ck_assert_str_eq(s21_buff, buff); 
}
END_TEST

START_TEST(test11_s21_sprintf_dec_width_precision) {
    char s21_buff[512];
    char buff[512];

    int s21_res1 = s21_sprintf(s21_buff, "|%10.5d|%5.8d|%3.5d|", 123, 42, 123);
    int res1 = sprintf(buff, "|%10.5d|%5.8d|%3.5d|", 123, 42, 123);
    ck_assert_int_eq(s21_res1, res1);
    ck_assert_str_eq(s21_buff, buff);

    int s21_res2 = s21_sprintf(s21_buff, "|%8.0d|%10.0d|%-10.5d|", 0, 42, 123);
    int res2 = sprintf(buff, "|%8.0d|%10.0d|%-10.5d|", 0, 42, 123);
    ck_assert_int_eq(s21_res2, res2);
    ck_assert_str_eq(s21_buff, buff);

    int s21_res3 = s21_sprintf(s21_buff, "|%10.6d|%15.3d|%20.15d|", -777, 42, 123);
    int res3 = sprintf(buff, "|%10.6d|%15.3d|%20.15d|", -777, 42, 123);
    ck_assert_int_eq(s21_res3, res3);
    ck_assert_str_eq(s21_buff, buff);  
}
END_TEST

START_TEST(test12_s21_sprintf_unsigned) {
    char s21_buff[512];
    char buff[512];

    int s21_res1 = s21_sprintf(s21_buff, "Zero: %u", 0u);
    int res1 = sprintf(buff, "Zero: %u", 0u);
    ck_assert_int_eq(s21_res1, res1);
    ck_assert_str_eq(s21_buff, buff);

    int s21_res2 = s21_sprintf(s21_buff, "Positive: %u", 42u);
    int res2 = sprintf(buff, "Positive: %u", 42u);
    ck_assert_int_eq(s21_res2, res2);
    ck_assert_str_eq(s21_buff, buff);

    int s21_res3 = s21_sprintf(s21_buff, "Max: %u", 4294967295u);
    int res3 = sprintf(buff, "Max: %u", 4294967295u);
    ck_assert_int_eq(s21_res3, res3);
    ck_assert_str_eq(s21_buff, buff);

    int s21_res4 = s21_sprintf(s21_buff, "Negative: %u", (unsigned int)(-1));
    int res4 = sprintf(buff, "Negative: %u", (unsigned int)(-1));
    ck_assert_int_eq(s21_res4, res4);
    ck_assert_str_eq(s21_buff, buff);

    int s21_res5 = s21_sprintf(s21_buff, "%u %u %u", 0u, 1u, 123u);
    int res5 = sprintf(buff, "%u %u %u", 0u, 1u, 123u);
    ck_assert_int_eq(s21_res5, res5);
    ck_assert_str_eq(s21_buff, buff);

    int s21_res6 = s21_sprintf(s21_buff, "%u %u %u", 0, 1, 123);
    int res6 = sprintf(buff, "%u %u %u", 0, 1, 123);
    ck_assert_int_eq(s21_res6, res6);
    ck_assert_str_eq(s21_buff, buff);    
}
END_TEST

START_TEST(test13_s21_sprintf_unsigned_width) {
    char s21_buff[512];
    char buff[512];

    int s21_res1 = s21_sprintf(s21_buff, "|%8u|%3u|%5u|", 123u, 12345u, 12345u);
    int res1 = sprintf(buff, "|%8u|%3u|%5u|", 123u, 12345u, 12345u);
    ck_assert_int_eq(s21_res1, res1);
    ck_assert_str_eq(s21_buff, buff);

    int s21_res2 = s21_sprintf(s21_buff, "|%0u|%12u|", 42u, 987654321u);
    int res2 = sprintf(buff, "|%0u|%12u|", 42u, 987654321u);
    ck_assert_int_eq(s21_res2, res2);
    ck_assert_str_eq(s21_buff, buff);

    int s21_res3 = s21_sprintf(s21_buff, "|%0u|%5u|%0u|%5u|", 0u, 0u, 0, 0);
    int res3 = sprintf(buff, "|%0u|%5u|%0u|%5u|", 0u, 0u, 0, 0);
    ck_assert_int_eq(s21_res3, res3);
    ck_assert_str_eq(s21_buff, buff);

    int s21_res4 = s21_sprintf(s21_buff, "|%10u|", (unsigned int)(-1));
    int res4 = sprintf(buff, "|%10u|", (unsigned int)(-1));
    ck_assert_int_eq(s21_res4, res4);
    ck_assert_str_eq(s21_buff, buff);    
}
END_TEST

START_TEST(test14_s21_sprintf_unsigned_precision) {
    char s21_buff[512];
    char buff[512];

    int s21_res1 = s21_sprintf(s21_buff, "|%.6u|%.5u|", 123u, 12345u);
    int res1 = sprintf(buff, "|%.6u|%.5u|", 123u, 12345u);
    ck_assert_int_eq(s21_res1, res1);
    ck_assert_str_eq(s21_buff, buff);

    int s21_res2 = s21_sprintf(s21_buff, "|%.3u|%.12u|", 12345u, 66666u);
    int res2 = sprintf(buff, "|%.3u|%.12u|", 12345u, 66666u);
    ck_assert_int_eq(s21_res2, res2);
    ck_assert_str_eq(s21_buff, buff);

    int s21_res3 = s21_sprintf(s21_buff, "|%.0u|%.0u|%.15u|%.1u|", 0u, 42u, 0u, 0u);
    int res3 = sprintf(buff, "|%.0u|%.0u|%.15u|%.1u|", 0u, 42u, 0u, 0u);
    ck_assert_int_eq(s21_res3, res3);
    ck_assert_str_eq(s21_buff, buff);
}
END_TEST

START_TEST(test15_s21_sprintf_unsigned_width_precision) {
    char s21_buff[512];
    char buff[512];

    int s21_res1 = s21_sprintf(s21_buff, "|%10.6u|%5.8u|%4.6u|", 123u, 42u, 123u);
    int res1 = sprintf(buff, "|%10.6u|%5.8u|%4.6u|", 123u, 42u, 123u);
    ck_assert_int_eq(s21_res1, res1);
    ck_assert_str_eq(s21_buff, buff);

    int s21_res2 = s21_sprintf(s21_buff, "|%8.0u|%10.0u|%-10.6u|", 0u, 42u, 123u);
    int res2 = sprintf(buff, "|%8.0u|%10.0u|%-10.6u|", 0u, 42u, 123u);
    ck_assert_int_eq(s21_res2, res2);
    ck_assert_str_eq(s21_buff, buff);

    int s21_res3 = s21_sprintf(s21_buff, "|%15.10u|%12.8u|", 7777, 0u);
    int res3 = sprintf(buff, "|%15.10u|%12.8u|", 7777, 0u);
    ck_assert_int_eq(s21_res3, res3);
    ck_assert_str_eq(s21_buff, buff);

    int s21_res4 = s21_sprintf(s21_buff, "|%1.1u|%2.2u|%3.3u|%4.4u", 1111u, 111u, 11u, 1u);
    int res4 = sprintf(buff, "|%1.1u|%2.2u|%3.3u|%4.4u", 1111u, 111u, 11u, 1u);
    ck_assert_int_eq(s21_res4, res4);
    ck_assert_str_eq(s21_buff, buff);
}
END_TEST

START_TEST(test16_s21_sprintf_unsigned_flags) {
    char s21_buff[512];
    char buff[512];

    int s21_res1 = s21_sprintf(s21_buff, "|%-10u|", 123u);
    int res1 = sprintf(buff,  "|%-10u|", 123u);
    ck_assert_int_eq(s21_res1, res1);
    ck_assert_str_eq(s21_buff, buff);

    int s21_res2 = s21_sprintf(s21_buff, "|%-u|", 0u);
    int res2 = sprintf(buff, "|%-u|", 0u);
    ck_assert_int_eq(s21_res2, res2);
    ck_assert_str_eq(s21_buff, buff);

    int s21_res3 = s21_sprintf(s21_buff, "|%-12u|%-8u|%-5u|", 111111u, 2222u, 333u);
    int res3 = sprintf(buff, "|%-12u|%-8u|%-5u|", 111111u, 2222u, 333u);
    ck_assert_int_eq(s21_res3, res3);
    ck_assert_str_eq(s21_buff, buff);
}
END_TEST

START_TEST(test17_s21_sprintf_modifier) {
    char s21_buff[512];
    char buff[512];
    short int s_val = 32767;
    unsigned short int us_val = 65535;
    long int l_val = 2147483647L;
    unsigned long int ul_val = 4294967295UL;
    char lc_val = 'Y';

    int s21_res1 = s21_sprintf(s21_buff, "|%hd|%hu|", s_val, us_val);
    int res1 = sprintf(buff, "|%hd|%hu|", s_val, us_val);
    ck_assert_int_eq(s21_res1, res1);
    ck_assert_str_eq(s21_buff, buff);

    int s21_res2 = s21_sprintf(s21_buff, "|%hd|%hu|", (short)-1, (unsigned short)0);
    int res2 = sprintf(buff, "|%hd|%hu|", (short)-1, (unsigned short)0);
    ck_assert_int_eq(s21_res2, res2);
    ck_assert_str_eq(s21_buff, buff);

    int s21_res3 = s21_sprintf(s21_buff, "|%ld|%lu|%lc|", l_val, ul_val, lc_val);
    int res3 = sprintf(buff, "|%ld|%lu|%lc|", l_val, ul_val, lc_val);
    ck_assert_int_eq(s21_res3, res3);
    ck_assert_str_eq(s21_buff, buff);

    int s21_res4 = s21_sprintf(s21_buff, "|%ld|%lu", -1L, 0UL);
    int res4 = sprintf(buff, "|%ld|%lu", -1L, 0UL);
    ck_assert_int_eq(s21_res4, res4);
    ck_assert_str_eq(s21_buff, buff);

    int s21_res5 = s21_sprintf(s21_buff, "|%hd|%ld|%hu|%lu", s_val, l_val, us_val, ul_val);
    int res5 = sprintf(buff, "|%hd|%ld|%hu|%lu", s_val, l_val, us_val, ul_val);
    ck_assert_int_eq(s21_res5, res5);
    ck_assert_str_eq(s21_buff, buff);

    int s21_res6 = s21_sprintf(s21_buff, "|%5hd|%5ld|%5hu|%5lu|", s_val, l_val, us_val, ul_val);
    int res6 = sprintf(buff, "|%5hd|%5ld|%5hu|%5lu|", s_val, l_val, us_val, ul_val);
    ck_assert_int_eq(s21_res6, res6);
    ck_assert_str_eq(s21_buff, buff);

    int s21_res7 = s21_sprintf(s21_buff, "|%.6hd|%.10ld|%.8hu|%.12lu|", s_val, l_val, us_val, ul_val);
    int res7 = sprintf(buff, "|%.6hd|%.10ld|%.8hu|%.12lu|", s_val, l_val, us_val, ul_val);
    ck_assert_int_eq(s21_res7, res7);
    ck_assert_str_eq(s21_buff, buff);

    int s21_res8 = s21_sprintf(s21_buff, "|%hd|%lc|%ld|", 42, 'B', 123L);
    int res8 = sprintf(buff, "|%hd|%lc|%ld|", 42, 'B', 123L);
    ck_assert_int_eq(s21_res8, res8);
    ck_assert_str_eq(s21_buff, buff);
}
END_TEST

START_TEST(test18_s21_sprintf_empty) {
    char s21_buff[512];
    char buff[512];

    int s21_res2 = s21_sprintf(s21_buff, "    ");
    int res2 = sprintf(buff, "    ");
    ck_assert_int_eq(s21_res2, res2);
    ck_assert_str_eq(s21_buff, buff);

    int s21_res3 = s21_sprintf(s21_buff, "   text   ");
    int res3 = sprintf(buff, "   text   ");
    ck_assert_int_eq(s21_res3, res3);
    ck_assert_str_eq(s21_buff, buff);

    int s21_res4 = s21_sprintf(s21_buff, "%%");
    int res4 = sprintf(buff, "%%");
    ck_assert_int_eq(s21_res4, res4);
    ck_assert_str_eq(s21_buff, buff);

    int s21_res5 = s21_sprintf(s21_buff, "\t");
    int res5 = sprintf(buff, "\t");
    ck_assert_int_eq(s21_res5, res5);
    ck_assert_str_eq(s21_buff, buff);

    int s21_res6 = s21_sprintf(s21_buff, "\n");
    int res6 = sprintf(buff, "\n");
    ck_assert_int_eq(s21_res6, res6);
    ck_assert_str_eq(s21_buff, buff);
}
END_TEST

START_TEST(test19_s21_sprintf_float) {
    char s21_buff[512];
    char buff[512];

    int s21_res1 = s21_sprintf(s21_buff, "|%f|%f|%f|", 3.14f, -3.14f, 3.00f);
    int res1 = sprintf(buff, "|%f|%f|%f|", 3.14f, -3.14f, 3.00f);
    ck_assert_int_eq(s21_res1, res1);
    ck_assert_str_eq(s21_buff, buff);

    int s21_res2 = s21_sprintf(s21_buff, "|%f|%f|%f|", 0.0f, 0.000001f, -0.0000001f);
    int res2 = sprintf(buff, "|%f|%f|%f|", 0.0f, 0.000001f, -0.0000001f);
    ck_assert_int_eq(s21_res2, res2);
    ck_assert_str_eq(s21_buff, buff);

    int s21_res3 = s21_sprintf(s21_buff, "|%f|%f|%f|%f|", 12345678.0f, 1234.5678f, -12345678.0f, -1234.5678f);
    int res3 = sprintf(buff, "|%f|%f|%f|%f|", 12345678.0f, 1234.5678f, -12345678.0f, -1234.5678f);
    ck_assert_int_eq(s21_res3, res3);
    ck_assert_str_eq(s21_buff, buff);
}
END_TEST

START_TEST(test20_s21_sprintf_float_width) {
    char s21_buff[512];
    char buff[512];

    int s21_res1 = s21_sprintf(s21_buff, "|%10f|%10f|%10f|", 3.14f, -3.14f, 3.00);
    int res1 = sprintf(buff, "|%10f|%10f|%10f|", 3.14f, -3.14f, 3.00);
    ck_assert_int_eq(s21_res1, res1);
    ck_assert_str_eq(s21_buff, buff);

    int s21_res2 = s21_sprintf(s21_buff, "|%5f|%9f|%15f|", 12345.678f, 123.456f, 987654.321f);
    int res2 = sprintf(buff, "|%5f|%9f|%15f|", 12345.678f, 123.456f, 987654.321f);
    ck_assert_int_eq(s21_res2, res2);
    ck_assert_str_eq(s21_buff, buff);

    int s21_res3 = s21_sprintf(s21_buff, "|%0f|%10f|%8f|", 2.5f, -1.5f, 0.0f);
    int res3 = sprintf(buff, "|%0f|%10f|%8f|", 2.5f, -1.5f, 0.0f);
    ck_assert_int_eq(s21_res3, res3);
    ck_assert_str_eq(s21_buff, buff);
}
END_TEST

START_TEST(test21_s21_sprintf_float_precision) {
    char s21_buff[512];
    char buff[512];

    int s21_res1 = s21_sprintf(s21_buff, "|%.0f|%.0f|%.0f|", 3.14f, -3.14f, 0.0f);
    int res1 = sprintf(buff, "|%.0f|%.0f|%.0f|", 3.14f, -3.14f, 0.0f);
    ck_assert_int_eq(s21_res1, res1);
    ck_assert_str_eq(s21_buff, buff);

    int s21_res2 = s21_sprintf(s21_buff, "|%.1f|%.3f|%.10f|", 3.14f, 3.14159f, 1.23f);
    int res2 = sprintf(buff, "|%.1f|%.3f|%.10f|", 3.14f, 3.14159f, 1.23f);
    ck_assert_int_eq(s21_res2, res2);
    ck_assert_str_eq(s21_buff, buff);

    int s21_res3 = s21_sprintf(s21_buff, "|%.6f|%.8f|%.2f|", 2.5f, 0.0000001f, 12345.678f);
    int res3 = sprintf(buff, "|%.6f|%.8f|%.2f|", 2.5f, 0.0000001f, 12345.678f);
    ck_assert_int_eq(s21_res3, res3);
    ck_assert_str_eq(s21_buff, buff);
}
END_TEST

START_TEST(test22_s21_sprintf_float_width_precision) {
    char s21_buff[512];
    char buff[512];

    int s21_res1 = s21_sprintf(s21_buff, "|%10.2f|%10.5f|%5.6f|", 3.14f, 2.5f, 1.234567f);
    int res1 = sprintf(buff, "|%10.2f|%10.5f|%5.6f|", 3.14f, 2.5f, 1.234567f);
    ck_assert_int_eq(s21_res1, res1);
    ck_assert_str_eq(s21_buff, buff);

    int s21_res2 = s21_sprintf(s21_buff, "|%8.0f|%10.3f|%15.1f|", 42.11f, -1.2345f, 9876.543f);
    int res2 = sprintf(buff, "|%8.0f|%10.3f|%15.1f|", 42.11f, -1.2345f, 9876.543f);
    ck_assert_int_eq(s21_res2, res2);
    ck_assert_str_eq(s21_buff, buff);

    int s21_res3 = s21_sprintf(s21_buff, "|%12.8f|%10.4f|%-10.2f|", 0.0000001f, 0.0f, 3.14f);
    int res3 = sprintf(buff, "|%12.8f|%10.4f|%-10.2f|", 0.0000001f, 0.0f, 3.14f);
    ck_assert_int_eq(s21_res3, res3);
    ck_assert_str_eq(s21_buff, buff);
}
END_TEST

START_TEST(test23_s21_sprintf_float_flags) {
    char s21_buff[512];
    char buff[512];

    int s21_res1 = s21_sprintf(s21_buff, "|%+f|%+f|%+f|", 3.14f, -3.14f, 0.0f);
    int res1 = sprintf(buff, "|%+f|%+f|%+f|", 3.14f, -3.14f, 0.0f);
    ck_assert_int_eq(s21_res1, res1);
    ck_assert_str_eq(s21_buff, buff);

    int s21_res2 = s21_sprintf(s21_buff, "|% f|% f|% f|", 3.14f, -3.14f, 0.0f);
    int res2 = sprintf(buff, "|% f|% f|% f|", 3.14f, -3.14f, 0.0f);
    ck_assert_int_eq(s21_res2, res2);
    ck_assert_str_eq(s21_buff, buff);

    int s21_res3 = s21_sprintf(s21_buff, "|%-10f|%-12f|% -10f|", 3.14f, -3.14f, 3.00f);
    int res3 = sprintf(buff, "|%-10f|%-12f|% -10f|", 3.14f, -3.14f, 3.00f);
    ck_assert_int_eq(s21_res3, res3);
    ck_assert_str_eq(s21_buff, buff);

    int s21_res4 = s21_sprintf(s21_buff, "|%+-10.2f|% -8.1f|", 3.14f, -2.56f);
    int res4 = sprintf(buff, "|%+-10.2f|% -8.1f|", 3.14f, -2.56f);
    ck_assert_int_eq(s21_res4, res4);
    ck_assert_str_eq(s21_buff, buff);
}
END_TEST

Suite* s21_sprintf_suite(void) {
    Suite *s = suite_create("s21_sprintf");
    TCase *tc = tcase_create("s21_sprintf_core");
    tcase_add_test(tc, test1_s21_sprintf_char); 
    tcase_add_test(tc, test2_s21_sprintf_char_width);
    tcase_add_test(tc, test3_s21_sprintf_str);
    tcase_add_test(tc, test4_s21_sprintf_str_width);
    tcase_add_test(tc, test5_s21_sprintf_str_precision);
    tcase_add_test(tc, test6_s21_sprintf_str_width_precision);
    tcase_add_test(tc, test7_s21_sprintf_dec);
    tcase_add_test(tc, test8_s21_sprintf_dec_flags);
    tcase_add_test(tc, test9_s21_sprintf_dec_width);
    tcase_add_test(tc, test10_s21_sprintf_dec_precision);
    tcase_add_test(tc, test11_s21_sprintf_dec_width_precision);
    tcase_add_test(tc, test12_s21_sprintf_unsigned);
    tcase_add_test(tc, test13_s21_sprintf_unsigned_width);
    tcase_add_test(tc, test14_s21_sprintf_unsigned_precision);
    tcase_add_test(tc, test15_s21_sprintf_unsigned_width_precision);
    tcase_add_test(tc, test16_s21_sprintf_unsigned_flags);
    tcase_add_test(tc, test17_s21_sprintf_modifier);
    tcase_add_test(tc, test18_s21_sprintf_empty);
    tcase_add_test(tc, test19_s21_sprintf_float);
    tcase_add_test(tc, test20_s21_sprintf_float_width);
    tcase_add_test(tc, test21_s21_sprintf_float_precision);
    tcase_add_test(tc, test22_s21_sprintf_float_width_precision);
    tcase_add_test(tc, test23_s21_sprintf_float_flags);
    suite_add_tcase(s, tc);
    return s;
}

int s21_sprintf_main() {
    int failed;
    SRunner *runner = srunner_create(s21_sprintf_suite());
    srunner_run_all(runner, CK_NORMAL);
    failed = srunner_ntests_failed(runner);
    srunner_free(runner);
    return (failed == 0) ? 0 : failed;
}
CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11 -g -I../src
LDFLAGS = ../src/s21_string.a -lcheck -lcheck_pic -lm -pthread -lsubunit
# Нужен будет добавить отчет в html

OBJS = test_s21_memchr.o test_s21_memcmp.o test_s21_memcpy.o test_s21_memset.o test_s21_strchr.o test_s21_strcspn.o test_s21_strerror.o test_s21_strlen.o test_s21_strncat.o test_s21_strncmp.o test_s21_strncpy.o test_s21_strpbrk.o test_s21_strrchr.o test_s21_strstr.o test_s21_strtok.o main_tests.o

all: test_all

test_all: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o test_all

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o test_all

.PHONY: all clean
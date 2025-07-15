CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11 -g
LDFLAGS = -lcheck -lcheck_pic -lm -pthread -lsubunit
# Нужен будет добавить отчет в html
all: test_all

test_all: test_memchr test_memcmp test_memcpy test_memset test_strchr test_strcspn test_strerror test_strlen test_strncat test_strncmp test_strncpy test_strpbrk test_strrchr test_strstr test_strtok

test_memchr: test_s21_memchr.c
	$(CC) $(CFLAGS) -o test_memchr test_s21_memchr.c $(LDFLAGS)

test_memcmp: test_s21_memcmp.c
	$(CC) $(CFLAGS) -o test_memcmp test_s21_memcmp.c $(LDFLAGS)

test_memcpy: test_s21_memcpy.c
	$(CC) $(CFLAGS) -o test_memcpy test_s21_memcpy.c $(LDFLAGS)

test_memset: test_s21_memset.c
	$(CC) $(CFLAGS) -o test_memset test_s21_memset.c $(LDFLAGS)

test_strchr: test_s21_strchr.c
	$(CC) $(CFLAGS) -o test_strchr test_s21_strchr.c $(LDFLAGS)

test_strcspn: test_s21_strcspn.c
	$(CC) $(CFLAGS) -o test_strcspn test_s21_strcspn.c $(LDFLAGS)

test_strerror: test_s21_strerror.c
	$(CC) $(CFLAGS) -o test_strerror test_s21_strerror.c $(LDFLAGS)

test_strlen: test_s21_strlen.c
	$(CC) $(CFLAGS) -o test_strlen test_s21_strlen.c $(LDFLAGS)

test_strncat: test_s21_strncat.c
	$(CC) $(CFLAGS) -o test_strncat test_s21_strncat.c $(LDFLAGS)

test_strncmp: test_s21_strncmp.c
	$(CC) $(CFLAGS) -o test_strncmp test_s21_strncmp.c $(LDFLAGS)

test_strncpy: test_s21_strncpy.c
	$(CC) $(CFLAGS) -o test_strncpy test_s21_strncpy.c $(LDFLAGS)

test_strpbrk: test_s21_strpbrk.c
	$(CC) $(CFLAGS) -o test_strpbrk test_s21_strpbrk.c $(LDFLAGS)

test_strrchr: test_s21_strrchr.c
	$(CC) $(CFLAGS) -o test_strrchr test_s21_strrchr.c $(LDFLAGS)

test_strstr: test_s21_strstr.c
	$(CC) $(CFLAGS) -o test_strstr test_s21_strstr.c $(LDFLAGS)

test_strtok: test_s21_strtok.c
	$(CC) $(CFLAGS) -o test_strtok test_s21_strtok.c $(LDFLAGS)\

test_delete_me: delete_me.c
	$(CC) $(CFLAGS) -o delete_me delete_me.c $(LDFLAGS)

clean:
	rm -f delete_m
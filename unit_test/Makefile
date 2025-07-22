CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -I../src
LDFLAGS = ../src/s21_string.a -lcheck -lcheck_pic -lm -pthread -lsubunit
# Нужен будет добавить отчет в html
all: test_all
# gcc -Wall -Wextra -Werror -std=c11 -g -Isrc test_s21_memchr.c -Lsrc -lstring -lcheck -lcheck_pic -lm -pthread -lsubunit -o test_memchr
test_all: memchr.o memcmp.o memcpy.o memset.o strchr.o strcspn.o strerror.o strlen.o strncat.o strncmp.o strncpy.o strpbrk.o strrchr.o strstr.o strtok.o
	$(CC) $(CFLAGS) memchr.o memcmp.o memcpy.o memset.o strchr.o strcspn.o strerror.o strlen.o strncat.o strncmp.o strncpy.o strpbrk.o strrchr.o strstr.o strtok.o $(LDFLAGS) -o test_all
	echo "test_all compiled"
	./test_all
	echo "test_all executed"
	rm -f *.o
	rm -f test_all

memchr.o: test_s21_memchr.c
	$(CC) $(CFLAGS) test_s21_memchr.c -o memchr.o

memcmp.o: test_s21_memcmp.c
	$(CC) $(CFLAGS) test_s21_memcmp.c -o memcmp.o

memcpy.o: test_s21_memcpy.c
	$(CC) $(CFLAGS) test_s21_memcpy.c -o memcpy.o

memset.o: test_s21_memset.c
	$(CC) $(CFLAGS) test_s21_memset.c -o memset.o

strchr.o: test_s21_strchr.c
	$(CC) $(CFLAGS) test_s21_strchr.c -o strchr.o

strcspn.o: test_s21_strcspn.c
	$(CC) $(CFLAGS) test_s21_strcspn.c -o strcspn.o

strerror.o: test_s21_strerror.c
	$(CC) $(CFLAGS) test_s21_strerror.c -o strerror.o

strlen.o: test_s21_strlen.c
	$(CC) $(CFLAGS) test_s21_strlen.c -o strlen.o

strncat.o: test_s21_strncat.c
	$(CC) $(CFLAGS) test_s21_strncat.c -o strncat.o

strncmp.o: test_s21_strncmp.c
	$(CC) $(CFLAGS) test_s21_strncmp.c -o strncmp.o

strncpy.o: test_s21_strncpy.c
	$(CC) $(CFLAGS) test_s21_strncpy.c -o strncpy.o

strpbrk.o: test_s21_strpbrk.c
	$(CC) $(CFLAGS) test_s21_strpbrk.c -o strpbrk.o

strrchr.o: test_s21_strrchr.c
	$(CC) $(CFLAGS) test_s21_strrchr.c -o strrchr.o

strstr.o: test_s21_strstr.c
	$(CC) $(CFLAGS) test_s21_strstr.c -o strstr.o

strtok.o: test_s21_strtok.c
	$(CC) $(CFLAGS) test_s21_strtok.c -o strtok.o

rebuild: clean all

clean:
	rm -f *.o
	rm -f test_all

PHONY: rebuild clean all
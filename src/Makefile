CC = gcc
LIB_NAME = s21_string.a
CFLAGS = -std=c11 -Wall -Wextra -Werror
CFLAGS_TESTS = -std=c11 -Wall -Wextra -Werror -g -I../src
LDFLAGS_TESTS = $(LIB_NAME) -lcheck -lcheck_pic -lm -pthread -lsubunit

SRC = s21_string.c \
      BASE/s21_memchr.c \
      BASE/s21_memcmp.c \
      BASE/s21_memcpy.c \
	  BASE/s21_memset.c \
	  BASE/s21_strchr.c \
	  BASE/s21_strcspn.c \
	  BASE/s21_strerror.c \
	  BASE/s21_strlen.c \
	  BASE/s21_strncat.c \
	  BASE/s21_strncmp.c \
	  BASE/s21_strncpy.c \
	  BASE/s21_strpbrk.c \
	  BASE/s21_strrchr.c \
  	  BASE/s21_strstr.c \
	  BASE/s21_strtok.c \
	  DOP/s21_insert.c \
	  DOP/s21_trim.c \
	  DOP/s21_to_upper.c \
	  DOP/s21_to_lower.c 

OBJ = $(SRC:.c=.o)

TEST_SRC = ../unit_test/test_s21_memchr.c ../unit_test/test_s21_memcmp.c ../unit_test/test_s21_memcpy.c \
		   ../unit_test/test_s21_memset.c ../unit_test/test_s21_strchr.c ../unit_test/test_s21_strcspn.c \
		   ../unit_test/test_s21_strerror.c ../unit_test/test_s21_strlen.c ../unit_test/test_s21_strncat.c \
		   ../unit_test/test_s21_strncmp.c ../unit_test/test_s21_strncpy.c ../unit_test/test_s21_strpbrk.c \
		   ../unit_test/test_s21_strrchr.c ../unit_test/test_s21_strstr.c ../unit_test/test_s21_strtok.c \
		   ../unit_test/test_s21_tolower.c ../unit_test/test_s21_toupper.c ../unit_test/test_s21_trim.c \
		   ../unit_test/test_s21_insert.c ../unit_test/main_tests.c

TEST_OBJS = $(TEST_SRC:.c=.o)

TEST_EXEC = test_all

all: $(LIB_NAME)

$(LIB_NAME): $(OBJ)
	ar rcs $@ $^
	ranlib $@
	rm -f BASE/*.o
	rm -f DOP/*.o
	rm -f *.o
	
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Правило для тестов
test: $(TEST_OBJS)
	$(CC) $(CFLAGS_TESTS) $(TEST_OBJS) $(LDFLAGS_TESTS) -o $(TEST_EXEC)
	rm -f ../unit_test/*.o
	./$(TEST_EXEC)
	rm -f $(TEST_EXEC)

../unit_test/%.o: ../unit_test/%.c
	$(CC) $(CFLAGS_TESTS) -c $< -o $@

cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem $(SRC) $(TEST_SRC)

clang:
	cp ../materials/linters/.clang-format ./
	clang-format -i $(SRC) $(TEST_SRC)

clean:
	rm -rf *.o *.a *.gc* *.info $(TEST_EXEC) BASE/*.o ../unit_test/*.o

rebuild: clean all

.PHONY: all clean test cppcheck clang rebuild

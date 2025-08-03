CC = gcc
LIB_NAME = s21_string.a
CFLAGS = -std=c11 -Wall -Wextra -Werror
CFLAGS_TESTS = -std=c11 -Wall -Wextra -Werror -g -I../src
LDFLAGS_TESTS = $(LIB_NAME) -lcheck -lcheck_pic -lm -pthread -lsubunit

SRC = s21_memchr.c \
      s21_memcmp.c \
      s21_memcpy.c \
	  s21_memset.c \
	  s21_strchr.c \
	  s21_strcspn.c \
	  s21_strerror.c \
	  s21_strlen.c \
	  s21_strncat.c \
	  s21_strncmp.c \
	  s21_strncpy.c \
	  s21_strpbrk.c \
	  s21_strrchr.c \
  	  s21_strstr.c \
	  s21_strtok.c \
	  s21_insert.c \
	  s21_trim.c \
	  s21_to_upper.c \
	  s21_to_lower.c \
	  s21_sprintf.c

OBJ = $(SRC:.c=.o)

TEST_SRC = ../unit_test/test_s21_memchr.c ../unit_test/test_s21_memcmp.c ../unit_test/test_s21_memcpy.c \
		   ../unit_test/test_s21_memset.c ../unit_test/test_s21_strchr.c ../unit_test/test_s21_strcspn.c \
		   ../unit_test/test_s21_strerror.c ../unit_test/test_s21_strlen.c ../unit_test/test_s21_strncat.c \
		   ../unit_test/test_s21_strncmp.c ../unit_test/test_s21_strncpy.c ../unit_test/test_s21_strpbrk.c \
		   ../unit_test/test_s21_strrchr.c ../unit_test/test_s21_strstr.c ../unit_test/test_s21_strtok.c \
		   ../unit_test/test_s21_sprintf.c ../unit_test/test_s21_tolower.c ../unit_test/test_s21_toupper.c \
		   ../unit_test/test_s21_trim.c ../unit_test/test_s21_insert.c ../unit_test/main_tests.c

TEST_OBJS = $(TEST_SRC:.c=.o)

TEST_EXEC = test_all

all: $(LIB_NAME)

$(LIB_NAME): $(OBJ)
	ar rcs $@ $^
	ranlib $@
	rm -f BASE/*.o
	rm -f DOP/*.o
	rm -f *.o
	

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
	rm -rf *.o *.a *.gc* *.info $(TEST_EXEC) ../unit_test/*.o

rebuild: clean all

.PHONY: all clean test cppcheck clang rebuild

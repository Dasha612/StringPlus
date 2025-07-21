CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Werror
LIB_NAME = s21_string.a
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


OBJ = $(SRC:.c=.o)

# Тестовые файлы (пример)
TEST_SRC = tests/test_memcpy.c
TEST_EXEC = test_memcpy

all: $(LIB_NAME)

$(LIB_NAME): $(OBJ)
	ar rcs $@ $^
	ranlib $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Правило для тестов
test: $(TEST_EXEC)
	./$(TEST_EXEC)

$(TEST_EXEC): $(TEST_SRC) $(LIB_NAME)
	$(CC) $(CFLAGS) $^ -o $@ -L. -l$(LIB_NAME:.a=)

cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem $(SRC) $(TEST_SRC)

clang:
	cp ../materials/linters/.clang-format ./
	clang-format -i $(SRC) $(TEST_SRC)

clean:
	rm -rf *.o *.a *.gc* *.info $(TEST_EXEC) BASE/*.o

.PHONY: all clean test cppcheck clang

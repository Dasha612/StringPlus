CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Werror


LIB_NAME = s21_string.a


SRC = s21_string.c

OBJ = $(SRC:.c=.o)


all: $(LIB_NAME)


$(LIB_NAME): $(OBJ)
	ar rcs $@ $^
	ranlib $@


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -rf *.o *.a *.gc* *.info


.PHONY: all clean

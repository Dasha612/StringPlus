CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11 -g
LDFLAGS = -lcheck -lcheck_pic -lm -pthread -lsubunit

all: test

test: delete_me.c
	$(CC) $(CFLAGS) -o delete_me delete_me.c $(LDFLAGS)

clean:
	rm -f delete_me

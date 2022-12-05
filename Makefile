CC = gcc
SRC = simple_shell.c get_path.c strings.c node_functions.c
DEPS = path.h strings.h node.h
NAME = hsh
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu89 -g

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^

%.c: $(DEPS)

run:
	valgrind -s --leak-check=full ./$(NAME)

.PHONY: clean
clean: ; $(RM) ./$(NAME)

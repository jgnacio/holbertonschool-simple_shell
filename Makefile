CC = gcc
SRC = simple_shell.c get_path.c strings.c node_functions.c aux_functions.c getline.c env.c
DEPS = path.h strings.h node.h
NAME = hsh
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu89 -g

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^

%.c: $(DEPS)

run:
	valgrind -s --track-origins=yes --leak-check=full --show-leak-kinds=all ./$(NAME)

.PHONY: clean
clean: ; $(RM) ./$(NAME)

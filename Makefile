CC = gcc
SRC = simple_shell.c get_path.c strings.c add_node_end.c
DEPS = main.h strings.h
NAME = hsh
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu89 -g

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^

%.c: $(DEPS)

run:
	valgrind ./$(NAME) -s -leak_check=full

.PHONY: clean
clean: ; $(RM) ./$(NAME)

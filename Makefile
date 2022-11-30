CC = gcc
SRC =
DEPS = 
NAME = hsh
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu89 -g

all: $(NAME)

$(NAME): $(SRC) $(DEPS)
	$(CC) $(CFLAGS) -o $@ $^

run:
	valgrind ./$(NAME) -s -leak_check=full

.PHONY: clean
clean: ; $(RM) ./$(NAME)

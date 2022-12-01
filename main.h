#ifndef SHELL_H
#define SHELL_H
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <stdarg.h>

/**
 * struct list_s - singly linked list
 * @str: string - (malloc'ed string)
 * @len: length of the string
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 */
typedef struct list_s
{
	char *str;
	unsigned int len;
	struct list_s *next;
} list_t;

extern char **environ;
int find_char(char *string, char searched_char);
char *find_env_variable(char *searched_var);
char **parse_env_variable(char *var);
char *path_verify(char **ar_path, char *bin);
char *path_concat(int cnt_str, char *s1, ...);
list_t *makenode(const char *str);
#endif

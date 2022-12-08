#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>

extern char **environ;

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


/* Prototypes */
int find_char(char *string, char searched_char);
char *find_env_variable(char *searched_var);
char **parse_env_variable(char *var);
char *path_verify(char **ar_path, char *filename, char *exec_name);
char *mstr_concat(int cnt_str, char *s1, ...);
list_t *add_node_end(list_t **head, char *str);
list_t *makenode(char *str);
void free_list(list_t *head);
void freedom(unsigned int n, ...);
char **parse_str(char *s, char *delim);
int in(char c, char *s);
char * str_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
int64_t my_getline(char **lineptr, int *n, int fd);

#endif

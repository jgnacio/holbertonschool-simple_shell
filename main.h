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

/**
 * struct built_s - structure to identify which function to execute for your id
 * @id: function identifier.
 * @funct: pointer to function that return a char **.
 * @vfunct: pointer to function that return nothing.
 * @ifunct: pointer to funct that returns an int.
 */
typedef struct built_s
{
	char *id;
	char **(*funct)();
	void (*vfunct)();
	int (*ifunct)();
} built_t;

/* Prototypes */
int find_char(char *string, char searched_char);
char *find_env_variable(char *searched_var, int *index);
char **parse_env_variable(char *var);
list_t *add_node_end(list_t **head, char *str);
list_t *makenode(char *str);
void free_list(list_t *head);
void free5(char **s1, char **s2, char **s3, char ***ar1, char ***ar2);
char **parse_str(char *s, char *delim);
int in(char c, char *s);
char *str_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
int my_getline(char **lineptr, int *n, int fd);
int print_env(char **env);
int _atoi(char *s);
void sighandler(int signum);
char **set_env(char *v_name, char *v_value);
char **unset_env(char *v_name);
int builtin(char **ar);
char *check_existance(char **ar_path, char *filename,
		char *exec_name, int index);

#endif

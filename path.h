#ifndef SHELL_H
#define SHELL_H
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <stdarg.h>

/* Prototypes */
int find_char(char *string, char searched_char);
char *find_env_variable(char *searched_var);
char **parse_env_variable(char *var);
char *path_verify(char **ar_path, char *bin);
char *mstr_concat(int cnt_str, char *s1, ...);
#endif

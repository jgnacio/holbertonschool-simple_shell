#ifndef STRINGS_H
#define STRINGS_H

#include <stdlib.h>

int _strlen(char *str);
int _strcmp(char *str1, char *str2);
int _strncmp(char *s1, char *s2, unsigned int n);
char *_strdup(char *str);
char *_str_concat(char *s1, char *s2);
char *ltrim(char *s);
int _puts(int fd, char *s);

#endif

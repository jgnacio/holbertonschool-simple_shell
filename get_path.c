#include <stdlib.h>
#include <stddef.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include "main.h"
#include "strings.h"

/**
 * parse_env_variable - create an array of tokens for an env variable
 * @var: string from the environ array
 *
 * Return: NULL terminated array of strings (or NULL if malloc failed)
 */

char **parse_env_variable(char *var)
{
	char *str, *tmp, **ar;
	int i, count_delim;

	str = _strdup(var);
	if (!str)
		return (NULL);

	for (i = 0, count_delim = 0; str[i]; i++)
		if (str[i] == ':')
			count_delim++;

	ar = malloc(sizeof(char *) * (count_delim + 3));
	tmp = strtok(str, ":=\n\\");
	i = 0;
	ar[i++] = tmp;
	for (tmp = strtok(NULL, ":\n\\"); tmp; tmp = strtok(NULL, ":\n\\"))
		ar[i++] = tmp;
	ar[i] = NULL;

	return (ar);
}

/**
 * find_char - find the first occurrance of a char in a str
 * @string: string
 * @searched_char: char to search
 *
 * Return: index of char, or -1 if not found
 */

int find_char(char *string, char searched_char)
{
	int i;

	for (i = 0; string[i]; i++)
	{
		if (string[i] == searched_char)
			return (i);
	}
	return (-1);
}


/**
 * find_env_variable - find a variable in environ
 * @searched_var: searched variable ('key', if the string is
 * 'key=value')
 * @index: pointe to int that whill be changed to the
 * index in the array where the variable lies
 *
 * Return: the found string
 */

char *find_env_variable(char *searched_var, int *index)
{
	int i, j;

	for (i = 0; environ[i]; i++)
	{
		j = find_char(environ[i], '=');
		if (j < 0)
			return (NULL);

		if (_strncmp(environ[i], searched_var, (unsigned int) j) == 0)
		{
			*index = i;
			return (environ[i]);
		}
	}

	return (NULL);
}


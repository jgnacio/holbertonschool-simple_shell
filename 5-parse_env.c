#include "main.h"
#include "string.h"
#include "path_concat.c"

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

	for (i = 0, count_delim; str[i]; i++)
		if (str[i] == ':')
			count_delim++;

	ar = malloc(sizeof(char *) * (count_delim + 3));
	tmp = strtok(str, ":=");
	i = 0;
	ar[i++] = tmp;
	while (tmp = strtok(NULL, ":"))
		ar[i++] = tmp;
	ar[i] = tmp;

	return (ar);
}

/**
 * find_env_variable - find a variable in environ
 * @searched_var: searched variable ('key', if the string is 
 * 'key=value')
 * Return: the found string
 */

char *find_env_variable(char *searched_var)
{
	int i, j;
	char *str;

	for (i = 0; environ[i]; i++)
	{
		j = find_char(environ[i], '=');
		if (j < 0)
			return (NULL);

		if (_strncmp(environ[i], searched_var, j - 1) == 0)
			return (environ[i]);
	}

	return (NULL);
}

/**
 * find_char - find the first occurrance of a char in a str
 * @string: self explanatory
 * @searched_char: char to look for
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


char *path_verify(char **ar_path, char *bin)
{
	struct stat check;
	char *bin_path = NULL, *buf = NULL;
	int i;

	if (!bin)
		return (NULL);

	buf = path_concat(3, ar_path[1], "/", bin);
	if (!buf)
		return (NULL);
	printf("%s\n", buf);
	
	if (stat(bin, &check) == 0)
		return (bin_path);
}

int main(void)
{
	char *path = find_env_variable("PATH");
	char **ar_path = NULL;
	int i = 0;

	ar_path = parse_env_variable(path);

	path_verify(ar_path, "ls");

	return (0);
}

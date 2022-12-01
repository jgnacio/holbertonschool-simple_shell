#include "main.h"
#include "string.h"

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

		if (_strncmp(environ[i], searched_var, (unsigned int) j - 1) == 0)
			return (environ[i]);
	}

	return (NULL);
}

/**
 * mstr_concat - function that concatenates multiples strings.
 * @cnt_str: the number of strings to concatenates.
 * @s1: first string to concatenate.
 *
 * Return: strings concatenates.
 */
char *mstr_concat(int cnt_str, char *s1, ...)
{
	int len_strn = 0, i = 0, j = 0;
	char *concat_buf = NULL;
	va_list c_str;
	list_t *str_list = NULL, *tmp = NULL;

	va_start(c_str, s1);

	while (cnt_str >= 0)
	{
		if (s1 == NULL)
		{
			s1 = "";
		}
		tmp = add_node_end(&str_list, s1);
		len_strn += tmp->len;

		s1 = va_arg(c_str, char *);
		cnt_str--;
	}
	if (str_list)

	concat_buf = malloc(len_strn + 1);
	if (!concat_buf)
		return (NULL);

	while (str_list)
	{
		s1 = str_list->str;
		for (i = 0; s1[i]; i++, j++)
			concat_buf[j] = s1[i];
		str_list = str_list->next;
	}

	return (concat_buf);
}

/**
 * path_verify - check if an executable exists
 * @ar_path: array of directories in PATH
 * @bin: command passed
 *
 * Return: a str that can be executed with execve
 */

char *path_verify(char **ar_path, char *bin)
{
	struct stat check;
	char *buf = NULL;
	int i;

	if (!bin || !ar_path)
		return (NULL);
	for (i = 1; ar_path[i]; i++)
	{
		buf = mstr_concat(3, ar_path[i], "/", bin);
		if (!buf)
			return (NULL);
		if (stat(bin, &check) == 0)
			return (buf);
		free(buf);
	}
	write(STDOUT_FILENO, &"File not found\n", _strlen("File not found\n"));
	return (NULL);
}

#include "main.h"

/**
 *
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
 *
 *
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

		if (strncmp(environ[i], searched_var, (size_t) j - 1) == 0)
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
 *
 */
char *path_verify(char **ar_path, char *bin)
{
	struct stat check;
	char *bin_path = NULL, *buf = NULL;
	int i;

	if (!bin)
		return (NULL);

	buf = mstr_concat(3, ar_path[1], "/", bin);
	if (!buf)
		return (NULL);
	printf("%s\n", buf);

	if (stat(bin, &check) == 0)
		return (bin_path);
}

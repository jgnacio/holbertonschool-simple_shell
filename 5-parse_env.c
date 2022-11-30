#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

extern char **environ;
int find_char(char *string, char searched_char);
char *find_env_variable(char *searched_var);


char *parse_env_variable(char *var)
{
	char *str, *tmp, **ar;
	int i, count_delim;

	for (i = 0; var[i]; i++)
		continue;

	str = malloc(i + 1);
	for (i = 0; var[i]; i++)
		str[i] = var[i];
	str[i] = '\0';

	for (i = 0, count_delim; str[i]; i++)
		if (str[i] == ':')
			count_delim++;

	ar = malloc(sizeof(char *) * (count_delim + 2));
	strtok(str, ":=");
	i = 0;
	while (tmp = strtok(NULL, ":"))
		ar[i++] = tmp;
	ar[i] = tmp;

	for (i = 0; ar[i]; i++)
		printf("[%d] %s\n", i, ar[i]);

	free(str);
	free(ar);

	return (NULL);
}

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

int main(void)
{
	char *path = find_env_variable("PATH");

	parse_env_variable(path);
	return (0);
}

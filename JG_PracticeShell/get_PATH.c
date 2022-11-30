#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 *
 *
 */
char **get_path(char *);
extern char **environ;

int main(void)
{
	char **a_path = NULL;
	int i = 0;

	if (!environ)
		return (1);

	a_path = get_path("PATH");

	/*
	for (i = 0; a_path[i]; i++)
		printf("%s\n", a_path[i]);
		*/

	return (0);
}
/**
 *
 *
 */
char **get_path(char *var_env)
{
	char **a_path = NULL, *c_path = NULL, *str = NULL;
	int i = 0, cnt_delim = 0, var_len = 0;


	if (!var_env && strcmp(var_env, ""))
		return (NULL);

	var_len = strlen(var_env);

	for (i = 0; environ[i]; i++)
	{
		if (strncmp(environ[i], var_env, 4) == 0)
			printf("%s\n", environ[i]);
	}

	/*
	for (i = 0; c_path[i]; i++)
	{
		if (c_path[i] == ':')
			cnt_delim++;
	}

	a_path = malloc(sizeof(char *) * (cnt_delim + 2));
	if (!a_path)
		return (NULL);

	i = 0;
	a_path[i++] = strtok(c_path, ":");

	while (str = strtok(NULL, ":"))
		a_path[i++] = str;
	a_path[i] = str;
	*/

	return (a_path);
}

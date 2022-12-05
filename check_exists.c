#include "path.h"
#include "nodes.h"
#include "strings.h"
#include <stdlib.h>

/**
 * check_existance - check if an executable exists in the current
 * dir, or in any of the directories specified in PATH
 * @filename: name of file
 *
 * Return: pathname that is executable by execve, or NULL if not found
 */

char *check_existance(char **array, char *filename)
{
	struct stat buf;
	char *res, *tmp;
	int i;

	if (stat(filename, &buf) == 0)
		return (filename);

	for (i = 1; array[i]; i++)
	{
		tmp = _str_concat(array[i], "/");
		res = _str_concat(tmp, filename);
		free(tmp);
		if (stat(res, &buf) == 0)
			return (res);
		free(res);
	}
	return (NULL);
}

/*
int main(int ac, char **av)
{
	char **ar, *path, *tmp;
	if (ac != 2)
	{
		printf("Usage: ./exists	COMMAND\n");
		return (-1);
	}
	path = find_env_variable("PATH");
	ar = parse_env_variable(path);
	tmp = check_existance(ar, av[1]);
	if (tmp)
	{
		printf("%s\n", tmp);
		free(tmp);
	}
	free(ar[0]);
	free(ar);

	return (0);
}*/

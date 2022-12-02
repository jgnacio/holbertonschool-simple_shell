#include "main.h"
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
	char *tmp1, *tmp2, *res;
	int i;

	if (stat(filename, &buf) == 0)
		return (filename);

	for (i = 1; array[i]; i++)
	{
		tmp1 = _str_concat(array[i], "/");
		res = _str_concat(tmp1, filename);
		free(tmp1);
		if (stat(res, &buf) == 0)
			return (res);
		free(res);
	}
	tmp2 = "File not found\n";
	write(STDOUT_FILENO, &tmp2, _strlen(tmp2));
	return (NULL);
}


int main(int ac, char **av)
{
	int i;
	char **ar, *path, *tmp;
	if (ac != 2)
	{
		printf("Usage: ./a.out COMMAND\n");
		return (-1);
	}
	path = find_env_variable("PATH");
	ar = parse_env_variable(path);

	tmp = check_existance(ar, av[1]);
	printf("%s\n", tmp);

	free(tmp);
	free(ar[0]);
	free(ar);

	return (0);
}

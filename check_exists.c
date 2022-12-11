#include "main.h"
#include "strings.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdint.h>


/**
 * check_existance - check if an executable exists in the current
 * dir, or in any of the directories specified in PATH
 * @filename: name of file
 * @ar_path: path array
 * @exec_name: name of executable
 *
 * Return: pathname that is executable by execve, or NULL if not found
 */

char *check_existance(char **ar_path, char *filename, char *exec_name)
{
	struct stat check;
	char *res, *tmp;
	char *s = "Passed filename isn't a regular file with execution permission\n";
	int i;

	if (!ar_path || !filename)
		return (NULL);


	if (stat(filename, &check) == 0)
	{
		if (S_ISREG(check.st_mode) && !access(filename, X_OK))
		{
			res = _strdup(filename);
			return (res);
		}
		fprintf(stderr, "%s", s);
		return (NULL);
	}

	for (i = 1; ar_path[i]; i++)
	{
		tmp = _str_concat(ar_path[i], "/");
		res = _str_concat(tmp, filename);
		free(tmp);
		if (stat(res, &check) == 0)
		{
			if (S_ISREG(check.st_mode) && !access(res, X_OK))
				return (res);
			fprintf(stderr, "%s", s);
			return (NULL);
		}
		free(res);
	}
	fprintf(stderr, "%s: 1: %s: not found\n", exec_name, filename);
	return (NULL);
}


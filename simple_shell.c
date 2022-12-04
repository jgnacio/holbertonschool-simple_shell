#include "strings.h"
#include "main.h"
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * main - runs a very simple shell (a CLI)
 *
 * Return: 0 on success (shell was exited with  "exit")
 */

int main(void)
{
	int i, count_delim, child_pid, status;
	size_t len = 0, check_getline;
	char *str = NULL, *tmp = NULL, **ar = NULL, **a_path = NULL;
	struct stat statbuffer;

	while (1)
	{
		write(STDOUT_FILENO, &"$ ", 2);
		check_getline = getline(&str, &len, stdin);
		if (_strcmp(str,"exit\n") == 0 || check_getline == (size_t) -1)
			break;

		for (i = 0, count_delim = 0; str[i]; i++)
			if (str[i] == ' ' && (str[i] > 32 && str[i] < 127))
				count_delim++;

		ar = malloc(sizeof(char *) * (count_delim + 2));
		i = 0;
		ar[i++] = strtok(str, " \n");
		for (tmp = strtok(NULL, " \n"); tmp; tmp = strtok(NULL, " \n"))
			ar[i++] = tmp;
		ar[i] = tmp;

		/*
		if (stat(ar[0], &statbuffer) != 0)
		{
			printf("Error: File not found\nExiting...\n");
			break;
		}
		*/
		a_path = parse_env_variable(find_env_variable("PATH"));

		tmp = path_verify(a_path, ar[0]);
		if (!tmp)
		{
			free(str);
			free(ar);
			free(a_path);
			str = NULL;
			ar = NULL;
			a_path = NULL;
			printf("not found");
			continue;
		}

		printf("%s\n", tmp);

		child_pid = fork();
		(child_pid != 0) ? wait(&status) : execve(tmp, ar, environ);
		free(str);
		free(ar);
		str = NULL;
		ar = NULL;
		a_path = NULL;
	}
	return (0);
}

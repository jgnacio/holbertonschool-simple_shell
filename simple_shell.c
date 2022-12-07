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
 * @ac: argument count
 * @av: NULL terminated array of arguments as str
 * Return: 0 on success (shell was exited with  "exit")
 */

int main(int __attribute__ ((unused)) ac, char **av)
{
	int child_pid, status;
	size_t len = 0, check_getline;
	char *str = NULL, **ar = NULL, **a_path = NULL;

	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);
		check_getline = getline(&str, &len, stdin);

		ar = parse_str(str, " \t\n");

		if (_strcmp(ar[0], "exit") == 0 || check_getline == (size_t) -1)
		{
			freedom(2, &str, &ar);
			break;
		}

		a_path = parse_env_variable(find_env_variable("PATH="));
		ar[0] = path_verify(a_path, ar[0], av[0]);

		if (!ar[0])
		{
			freedom(4, &str, &ar, &a_path[0], &a_path);
			continue;
		}

		child_pid = fork();
		(child_pid != 0) ? wait(&status) : execve(ar[0], ar, environ);

		freedom(5, &str, &ar[0], &a_path[0], &a_path, &ar);
	}
	return (0);
}


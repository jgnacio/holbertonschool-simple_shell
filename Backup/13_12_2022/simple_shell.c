#include "strings.h"
#include "main.h"
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>

/**
 * main - runs a very simple shell (a CLI)
 * @ac: argument count
 * @av: NULL terminated array of arguments as str
 * Return: 0 on success (shell was exited with  "exit")
 */

int main(int __attribute__ ((unused)) ac, char **av)
{
	int child_pid, status, built_stat, index = 0, exit_status = 0,
			check_getline = 0, i = 1;
	size_t len = 0;
	char *str = NULL, **ar = NULL, **a_path = NULL;

	signal(SIGINT, sighandler);
	while (1)
	{
		(isatty(STDIN_FILENO)) ? write(STDOUT_FILENO, "$ ", 2) : 0;
		check_getline = getline(&str, &len, stdin), exit_status = 0;
		if (check_getline == -1)
		{
			free(str), str = NULL;
			break;
		}
		ar = parse_str(str, " \\\t\n"), built_stat = builtin(ar);
		if (built_stat != 0)
		{
			if (built_stat == -1)
			{
				if (ar[1])
					exit_status = _atoi(ar[1], i, av[0]);
				free5(&str, NULL, NULL, &ar, NULL);
				if (exit_status != INT_MIN)
					exit(exit_status);
				else
					exit_status = 2;
			}
			free5(&str, NULL, NULL, &ar, NULL);
			continue;
		}
		a_path = parse_env_variable(find_env_variable("PATH=", &index));
		ar[0] = check_existance(a_path, ar[0], av[0], i);
		if (ar[0])
		{
			child_pid = fork();
			(child_pid != 0) ? wait(&status) : execve(ar[0], ar, environ);
		}
		nonInteractiveExit(&str, &ar[0], &a_path[0], &a_path, &ar);
		free5(&str, &ar[0], &a_path[0], &a_path, &ar), i++;
	}
	return (0);
}


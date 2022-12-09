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

void sighandler(int signum);
/**
 * main - runs a very simple shell (a CLI)
 * @ac: argument count
 * @av: NULL terminated array of arguments as str
 * Return: 0 on success (shell was exited with  "exit")
 */

int main(int __attribute__ ((unused)) ac, char **av)
{
	int child_pid, status;
	int len = 0, check_getline, exit_status = 0;
	char *str = NULL, **ar = NULL, **a_path = NULL;

	signal(SIGINT, sighandler);

	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);

		check_getline = my_getline(&str, &len, STDIN_FILENO);

		if (check_getline == -1)
		{
			freedom(1, &str);
			break;
		}

		ar = parse_str(str, " \t\n");
		if (_strcmp(ar[0], "exit") == 0)
		{
			if (ar[1])
				exit_status = _atoi(ar[1]);
			freedom(2, &str, &ar);
			exit(exit_status);
		}

		else if (_strcmp(ar[0], "env") == 0)
		{
			print_env(environ);
			freedom(2, &str, &ar);
			continue;
		}

		a_path = parse_env_variable(find_env_variable("PATH="));
		ar[0] = path_verify(a_path, ar[0], av[0]);
		if (!ar[0])
		{
			freedom(4, &str, &ar, &a_path[0], &a_path);
			continue;
		}

		child_pid = fork();
		if (child_pid != 0)
			wait(&status);
		else
		{
			if (execve(ar[0], ar, environ) == -1)
			{
				write(STDERR_FILENO, "File passed is not an executable\n", 34);
				freedom(5, &str, &ar[0], &a_path[0], &a_path, &ar);
				break;
			}
		}
		freedom(5, &str, &ar[0], &a_path[0], &a_path, &ar);
	}
	return (0);
}


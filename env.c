#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "strings.h"

/**
 * _puts - print a string
 * @fd: file descriptor
 * @s: null-byte terminated string
 *
 * Return: number of chars printed
 */
int _puts(int fd, char *s)
{
	char *buf = NULL;
	int i;

	i = _strlen(s);
	if (i == -1)
		return (-1);
	buf = malloc(i);
	for (i = 0; s[i]; i++)
		buf[i] = s[i];
	i = write(fd, buf, i);
	free(buf);
	return (i);
}

/**
 * print_env - print the env to stdout
 * @env: NULL terminated array of strings (environ)
 *
 * Return: 0 on success
 */

int print_env(char **env)
{
	int i;

	for (i = 0; env[i]; i++)
		fprintf(stdout, "%s\n", env[i]);

	return (0);
}



/**
 * _atoi - convert a number as str to an int
 * @s: number as string
 *
 * Return: number as int
 */

int _atoi(char *s)
{
	int i = 0, res = 0, neg = 1;

	if (!s)
		exit(98);

	if (s[0] == '-')
	{
		i = 1;
		neg = -1;
	}
	for (; i < 10 && s[i]; i++)
	{
		if (s[i] >= 48 && s[i] < 58)
			res = res * 10 + (s[i] - '0');
		else
		{
			fprintf(stdout, "Can't atoi a non-numeric char\n");
			exit(0);
		}
	}
	return (res * neg);
}

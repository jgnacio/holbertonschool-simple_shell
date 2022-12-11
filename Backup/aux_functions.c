#include <stdarg.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include "main.h"

/**
 * freedom - free multiple pointers
 * @n: number of pointers to free
 *
 * Return: void
 * Note: the function recieves the address of
 * the pointers it must free
 */

void freedom(unsigned int n, ...)
{
	unsigned int i;
	void **p = NULL;
	va_list ap;

	va_start(ap, n);
	for (i = 0; i < n; i++)
	{
		p = (void **) va_arg(ap, void **);
		if (*p != NULL)
			free(*p);
		*p = NULL;
	}
	va_end(ap);
}


/**
 * parse_str - parse a str into an array that execve understands
 * @s: string recieved by getline
 * @delim: str of delimiters
 * Return: NULL terminated array on success
 */

char **parse_str(char *s, char *delim)
{
	int i, count_delim;
	char **ar, *tmp;

	if (!s && !delim)
		return (NULL);

	for (i = 0, count_delim = 0; s[i]; i++)
	{
		if (in(s[i], delim) == 1 && (s[i + 1] > 32 && s[i + 1] < 127))
			count_delim++;
	}

	ar = malloc(sizeof(char *) * (count_delim + 3));
	if (!ar)
		return (NULL);
	ar[0] = strtok(s, delim);

	for (tmp = strtok(NULL, delim), i = 1; tmp; tmp = strtok(NULL, delim))
		ar[i++] = tmp;

	ar[i] = NULL;
	return (ar);
}


/**
 * in - checks if a char is in a str
 * @c: char
 * @s: string
 *
 * Return: 1 for true, 0 for false
 */

int in(char c, char *s)
{
	int i;

	for (i = 0; s[i]; i++)
		if (c == s[i])
			return (1);
	return (0);
}

/**
 * sighandler - function used to handle Ctrl + C
 * @sig: signal
 *
 * Return: void
 */
void sighandler(__attribute__ ((unused)) int sig)
{
	write(STDOUT_FILENO, &"\n$ ", 3);
}

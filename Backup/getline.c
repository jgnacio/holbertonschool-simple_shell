#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>
#include "main.h"

#define GL_BUFFER 120

/**
 * my_getline - read in a line of input from a file stream
 * @lineptr: function will change *lineptr to new malloc'ed str
 * @n: function will change *n to size of malloc'ed str
 * @fd: file descriptor from which we're reading
 *
 * Return: number of chars read
 */

int my_getline(char **lineptr, int *n, int fd)
{
	int i = 1;
	size_t check_read;
	char *buffer = NULL;

	if (!lineptr || !n)
	{
		perror("lineptr and n cannot be NULL\n");
		return (-1);
	}
	buffer = str_realloc(NULL, 0, GL_BUFFER);
	if (!buffer)
	{
		perror("Malloc in getline function failed\n");
		return (-1);
	}
	check_read = read(fd, buffer, GL_BUFFER);
	*lineptr = buffer, *n = GL_BUFFER;

	if (check_read == (size_t) -1 || check_read == 0)
		return (-1);
	for (i = 1; check_read == GL_BUFFER; i++)
	{
		buffer = str_realloc(buffer, i * GL_BUFFER, (i + 1) * GL_BUFFER);
		if (!buffer)
		{
			perror("Realloc failed\n");
			return (-1);
		}
		check_read = read(fd, &buffer[GL_BUFFER * i], GL_BUFFER);
		if (check_read == (size_t) -1)
		{
			perror("Error reading from stdin\n");
			exit(98);
		}
	}
	*lineptr = buffer;
	*n = i * GL_BUFFER;
	return ((i - 1) * GL_BUFFER + check_read);
}

/**
 * str_realloc - realloc memory for a str
 * @ptr: char * (string)
 * @old_size: previous size
 * @new_size: new size
 *
 * Return: new address
 */

char *str_realloc(char *ptr, unsigned int old_size, unsigned int new_size)
{
	unsigned int i;
	char *res = NULL;

	if (!ptr)
	{
		res = malloc(new_size);
		if (!res)
			return (NULL);
		for (i = 0; i < new_size; i++)
			res[i] = '\0';
		return (res);
	}
	if (old_size >= new_size)
	{
		ptr[new_size - 1] = '\0';
		return (ptr);
	}
	res = malloc(new_size);
	if (!res)
		return (NULL);
	for (i = 0; i < new_size; i++)
	{
		if (i < old_size)
			res[i] = ptr[i];
		else
			res[i] = '\0';
	}
	free(ptr);
	return (res);
}


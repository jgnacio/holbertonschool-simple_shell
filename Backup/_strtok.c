#include <stdio.h>
#include "strings.h"
#include "main.h"

/**
 * _strtok - tokenize a string
 * @str: string to tokenize
 * @delim: string of delimiters
 *
 * Return: start of last token
 */

char *_strtok(char *str, char *delim)
{
	int i, exitLoopFlag = 1, consecDelim = 0;
	static char *tok;
	static int endFlag;

	if ((!str && !tok) || endFlag)
		return (NULL);

	else if (!tok)
		tok = str;

	else if (!str)
		str = tok;

	for (i = 0; tok[i]; i++)
	{
		if (in(tok[i], delim) == 1)
		{
			exitLoopFlag = 0;
			tok[i] = '\0';
			break;
		}
		consecDelim = 1;
	}
	if (exitLoopFlag)
	{	tok = NULL;
		endFlag = 1;
		return (str);
	}
	/* Now we must set tok to be the first non-delim char */
	tok = &tok[i + 1];
	if (!consecDelim)
		return (_strtok(NULL, delim));
	while (in(tok[0], delim) == 1 && tok)
	{
		tok[0] = '\0';
		tok++;
	}
	if (!tok[0])
		tok = NULL;
	return (str);
}


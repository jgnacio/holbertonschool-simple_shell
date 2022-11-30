#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int i, count_delim, child_pid, status;
	size_t len = 0, check_getline;
	char *str = NULL, *tmp = NULL, **ar;
	struct stat statbuffer;

	while (1)
	{
		write(STDOUT_FILENO, &"$ ", 2);
		check_getline = getline(&str, &len, stdin);
		if (strcmp(str,"exit\n") == 0 || check_getline == -1)
			break;

		for (i = 0, count_delim = 0; str[i]; i++)
			if (str[i] == ' ' && (str[i] > 32 && str[i] < 127))
				count_delim++;

		ar = malloc(sizeof(char *) * (count_delim + 2));
		i = 0;
		ar[i++] = strtok(str, " \n");
		while (tmp = strtok(NULL, " \n"))
			ar[i++] = tmp;
		ar[i] = tmp;

		if (stat(ar[0], &statbuffer) != 0)
		{
			printf("Error: File not found\nExiting...\n");
			break;
		}
		child_pid = fork();
		(child_pid != 0) ? wait(&status) : execve(ar[0], ar, NULL);
		free(str);
		free(ar);
	}
	return (0);
}

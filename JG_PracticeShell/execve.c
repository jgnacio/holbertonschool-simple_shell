#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

char **getcmd(char *);
void printcmd(char **);
extern char **environ;

int main(void)
{
	pid_t child_pid;
	size_t size_buf = 0;
	char *cmd = NULL, **exe = NULL, **PATH = NULL;
	int status = 0, i = 0;

	while(1)
	{
		printf("j-shell$ ");
		getline(&cmd, &size_buf, stdin);
		exe = getcmd(cmd);
		/* print cmd split */
		printcmd(exe);
		printf("%s\n",&environ[20][5]);

		if (strcmp(exe[0], "exit") == 0)
			break;
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error:");
			return (1);
		}
		if (child_pid == 0)
		{
			execve(exe[0], exe, environ);
		}
		else
		{
			wait(&status);
		}
		free(cmd);
	}
	return (0);
}

char **getcmd(char *input)
{
	char *tok = NULL, *dup = NULL, **exe = NULL;
	int i = 0;

	dup = strdup(input);
	tok = strtok(dup, " \n");

	for (i = 0; tok; i++)
		tok = strtok(NULL, " \n");
	free(dup);

	exe = malloc(sizeof(char *) * (i + 1));
	tok = strtok(input, " \n");
	for (i = 0; tok; i++)
	{
		exe[i] = tok;
		tok = strtok(NULL, " \n");
	}
	exe[i] = NULL;
	return (exe);
}

void printcmd(char **exe)
{
	int i = 0;

	printf("## cmd split ##\n{");
	for (i = 0; exe[i]; i++)
	{
		printf("'%s'", exe[i]);
		if (exe[i + 1])
			printf(",");
	}
	printf("}\n");
}

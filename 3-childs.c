#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>

int main(int __attribute__ ((unused)) ac, char **av)
{
	int i, status;
	pid_t my_pid, child_pid;
	char *ar[] = {"/bin/ls", "-l", "/tmp/", NULL};

	for (i = 0; i < 5; i++)
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			write(STDOUT_FILENO, &"Failed to create child", 23);
			return (1);
		}
		printf("Current process PID = %d\n", getpid());
		if (child_pid != 0)
			wait(&status);
		else
			execve(ar[0], ar, NULL);
	}
	return (0);
}

#include <unistd.h>
#include <stdio.h>

int main(void)
{
	pid_t c_pid;
	pid_t c_ppid;


	c_pid = getpid();
	c_ppid = getppid();
	printf("pid:%d\n", c_pid);
	printf("ppid:%d\n", c_ppid);
}

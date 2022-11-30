#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int ac, char **av)
{
	size_t len = 0;
	char *str;
	ssize_t check = 1;

	while (check > 0)
	{
		write(STDOUT_FILENO, &"$ ", 2);
		check = getline(&str, &len, stdin);
		printf("%s", str);
		if (strcmp(str, "exit\n") == 0)
			break;
	}

	free(str);
	return (0);
}

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
	int i, count_delim;
	char **ar, *str;

	if (ac != 2)
	{
		printf("Usage: ./a.out \"[Insert string]\"\n");
		return (-1);
	}

	for (i = 0, count_delim = 0; av[1][i]; i++)
		if (av[1][i] == ' ' && (av[1][i + 1] > 32 && av[1][i + 1] < 127))
			count_delim++;

	ar = malloc(sizeof(char *) * (count_delim + 2));
	i = 0;
	ar[i++] = strtok(av[1], " ");
	
	while (str = strtok(NULL, " "))
		ar[i++] = str;
	
	ar[i] = str;
	for (i = 0; ar[i]; i++)
		printf("[%d] %s\n", i, ar[i]);
	printf("[%d] %s\n", i, ar[i]);
	free(ar);
	return (0);
}

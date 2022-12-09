#include <stdint.h>
#include <unistd.h>
#include "main.h"
#include "strings.h"

void exit_(char *, char *);
void print_env();
void cd_fun();
/**
 *
 *
 */
int builtin(char **ar)
{
	int i, cnt_ar;
	built_t a_built[] =
	{
		{"exit", NULL, NULL},
		{"setenv", set_env, NULL},
		{"unsetenv", unset_env, NULL},
		{"env", NULL, print_env},
		{"cd", NULL, cd_fun},
		{NULL, NULL, NULL}
	};

	for (cnt_ar = 0; ar[cnt_ar]; cnt_ar++)
		;

	for (i = 0; a_built[i].id; i++)
	{
		if (_strcmp(a_built[i].id, ar[0]) == 0)
		{
			if (!(a_built[i].funct) && !(a_built[i].vfunct))
				return (-1);
			else if (a_built[i].vfunct)
			{
				a_built[i].vfunct();
				return (1);
			}
			switch (a_built[i].id[0] + a_built[i].id[1])
			{
				case 216:
					if (cnt_ar >= 2)
						a_built[i].funct(ar[1], ar[2]);
					break;
				case 227:
					if (cnt_ar >= 2)
						a_built[i].funct(ar[1], ar[2]);
					break;
			}
			return(1);
		}
	}
	return (0);
}

void print_env()
{
	write(STDOUT_FILENO, &"printenv\n", 9);
}
void cd_fun()
{
	write(STDOUT_FILENO, &"cd_fun\n", 7);
}
char **unset_env(char *v_name)
{
	dprintf(STDOUT_FILENO, "unset: %s\n", v_name);
	return (NULL);
}

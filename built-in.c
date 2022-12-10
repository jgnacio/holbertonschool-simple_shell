#include <stdint.h>
#include <unistd.h>
#include "main.h"
#include "strings.h"

void exit_(char *, char *);
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
		{"exit", NULL, NULL ,NULL},
		{"setenv", set_env, NULL, NULL},
		{"unsetenv", unset_env, NULL, NULL},
		{"env", NULL, NULL, print_env},
		{"cd", NULL, cd_fun, NULL},
		{NULL, NULL, NULL, NULL}
	};

	for (cnt_ar = 0; ar[cnt_ar]; cnt_ar++)
		;

	for (i = 0; a_built[i].id; i++)
	{
		if (_strcmp(a_built[i].id, ar[0]) == 0)
		{
			/* this case is for exit built-in */
			if (!(a_built[i].funct) && !(a_built[i].vfunct) && !(a_built[i].ifunct)) 
				return (-1);
			/* this case are for functions that return nothing */
			else if (a_built[i].vfunct)
			{
				a_built[i].vfunct();
				return (1);
			}
			switch (a_built[i].id[0] + a_built[i].id[1])
			{
				case 216: /* this case is for setenv built-in */
					if (cnt_ar >= 2)
						a_built[i].funct(ar[1], ar[2]);
					break;
				case 227: /* this case is for unsetenv built-in */
					if (cnt_ar >= 2)
						a_built[i].funct(ar[1], ar[2]);
					break;
				case 211: /* this case is for env built-in */
					a_built[i].ifunct(environ);
					break;
			}
			return(1);
		}
	}
	return (0);
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

char **set_env(char *v_name, char *v_value)
{
	/*int a_len, index = 0;*/
	/*char **a_env = NULL;*/

	write(STDOUT_FILENO, v_name, _strlen(v_name));
	write(STDOUT_FILENO, &"=", 1);
	write(STDOUT_FILENO, v_value, _strlen(v_value));
	write(STDOUT_FILENO, &"\n", 1);
	return (NULL);
}

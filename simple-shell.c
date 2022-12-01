#include "main.h"
#include "path_concat.c"
#include "add_node_end.c"

/**
 *
 *
 */
int main(void)
{
	char *path = find_env_variable("PATH");
	char **ar_path = NULL;
	int i = 0;

	ar_path = parse_env_variable(path);

	path_verify(ar_path, "ls");

	return (0);
}

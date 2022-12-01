#include "main.h"
/**
 * str_concat - function that concatenates two strings.
 * @s1: first string to concatenate.
 * @s2: second string to concatenate.
 *
 * Return: string concatenate.
 */
char *path_concat(int cnt_str, char *s1, ...)
{
	int len_sn = 0, i = 0, j = 0;
	char *concat_buf = NULL;
	va_list c_str;
	list_t *str_list = NULL, *tmp = NULL;

	va_start(c_str, s1);
	
	
	while (cnt_str >= 0)
	{
		if (s1 == NULL)
		{
			s1 = "";
		}
		tmp = add_node_end(&str_list, s1);
		len_sn += tmp->len;

		printf("%s\n", s1);
		s1 = va_arg(c_str, char *);
		cnt_str--;
	}

	printf("len_FULL = %d\n", len_sn);

	concat_buf = malloc(len_sn + 1);

	if (str_list)
	{
		while (str_list)
		{
			printf("existe\n");
			s1 = str_list->str;
			for (i = 0; s1[i]; i++, j++)
				concat_buf[j] = s1[i];
			printf("strconcat= '%s'\n", concat_buf);
			str_list = str_list->next;
		}
	}
	printf("no existe\n");

	/*
	if (concat_buf)
	{
		for (i = 0; i <= (len_s1 + len_s2); i++)
		{
			if (i < len_s1)
				concat_buf[i] = s1[i];
			else
			{
				concat_buf[i] = s2[j];
				j++;
			}
		}
		return (concat_buf);
	}
	*/
	return (NULL);
}

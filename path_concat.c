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
	int len_sn = 0, len_sn1 = 0, i = 0, j = 0;
	char *concat_buf = NULL;
	va_list c_str;
	list_t str_list;

	va_start(c_str, s1);
	
	while (cnt_str)
	{
		if (s1 == NULL)
		{
			s1 = "";
		}
		printf("%s\n", s1);
		s1 = va_arg(c_str, char *);
		cnt_str--;
	}

	/*
	concat_buf = malloc((len_s1 + len_s2) + 1);

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

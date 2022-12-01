#include "main.h"

/**
 * add_node_end - Function that adds a new node at the end of a list_t list.
 * @head: The pointer of an list.
 * @str: String for the new list.
 *
 * Return: The list of nodes.
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new = NULL;
	list_t *aux = *head;
	int i;

	new = makenode(str);
	if (!*head)
	{
		*head = new;
	}
	else
	{
		for (i = 0; aux->next; i++)
		{
			aux = aux->next;
		}
		aux->next = new;
	}
	return (new);
}

/**
 * makenode - Function that create a new node for an list
 * @str: The string to set in the new node.
 *
 * Return: The new node.
 */
list_t *makenode(const char *str)
{
		list_t *new = NULL;
		int i = 0;
		char *dup;

		new = malloc(sizeof(list_t));
		if (!new)
		{
			free(new);
			return (new);
		}

		for (i = 0; str[i]; i++)
			;
		dup = strdup(str);
		if (!dup)
			free(new);
		else
		{
			new->str = dup;
			new->len = i;
			new->next = NULL;
		}
		return (new);
}

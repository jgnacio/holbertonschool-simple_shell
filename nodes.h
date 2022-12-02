#ifndef NODES_H
#define NODES_H

/**
 * struct list_s - singly linked list
 * @str: string - (malloc'ed string)
 * @len: length of the string
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 */
typedef struct list_s
{
	char *str;
	unsigned int len;
	struct list_s *next;
} list_t;

/* Prototypes */
list_t *add_node_end(list_t **head, char *str);
list_t *makenode(char *str);
void free_list(list_t *head);
#endif

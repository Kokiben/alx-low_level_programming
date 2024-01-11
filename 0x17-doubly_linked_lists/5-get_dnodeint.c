#include "lists.h"

/**
 * get_dnodeint_at_index - Get node at idx
 * @head: Head of double list
 * @index: Index of node
 * Return: node
 */

dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	dlistint_t *curre = head;
	unsigned int a;

	for (a = 0; curre; a++)
	{
		if (a == index)
			return (curre);
		curre = curre->next;
	}
	return (NULL);
}

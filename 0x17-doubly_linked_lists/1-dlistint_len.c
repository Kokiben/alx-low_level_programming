#include "lists.h"

/**
 * dlistint_len -  prints elements of list
 * @h: Head of double list
 * Return: number of element
 */

size_t dlistint_len(const dlistint_t *h)
{
	const dlistint_t *current = h;
	int a;

	for (a = 0; current; a++)
	{
		current = current->next;
	}
	return (a);
}

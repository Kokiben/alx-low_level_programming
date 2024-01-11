#include "lists.h"

/**
 * print_dlistint -  prints elements of list
 * @h: Head of double list
 * Return: number of node
 */

size_t print_dlistint(const dlistint_t *h)
{
	const dlistint_t *current = h;
	int a;

	for (a = 0; current; a++)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
	return (a);
}

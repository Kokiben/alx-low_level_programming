#include "lists.h"

/**
 * sum_dlistint - Sum of data
 * @head: Head of double list
 * Return: Sum
 */

int sum_dlistint(dlistint_t *head)
{
	dlistint_t *current = head;
	int a, s = 0;

	for (a = 0; current; a++)
	{
		s += current->n;
		current = current->next;
	}
	return (s);
}

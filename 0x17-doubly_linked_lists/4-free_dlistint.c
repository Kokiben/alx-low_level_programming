#include "lists.h"

/**
 * free_dlistint -  frees
 * @head: Head of double list
 * Return: void
 */

void free_dlistint(dlistint_t *head)
{
	dlistint_t *nv, *nv2;

	nv = head;
	while (nv)
	{
		nv2 = nv->next;
		free(nv);
		nv = nv2;
	}
}

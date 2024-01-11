#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes
 * deletes the node at index
 * @head: head of double list
 * @index: index where to insert
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *nv, *befo, *deleted;
	unsigned int a = 0;

	if (!head || !*head)
		return (-1);
	nv = *head;
	if (index == 0)
	{
		*head = nv->next;
		(*head)->prev = NULL;
		free(nv);
		return (1);
	}
	while (nv)
	{
		if (a == index)
			deleted = nv;
		if (a == index - 1)
			befo = nv;
		if (a == index + 1)
		{
			befo->next = nv;
			nv->prev = befo;
			free(deleted);
			return (1);
		}
		if (nv->next == NULL && a == index)
		{
			befo->next = NULL;
			free(nv);
			return (1);
		}
		nv = nv->next;
		a++;
	}
	return (-1);
}

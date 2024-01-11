#include "lists.h"

/**
 * add_dnodeint -  adds new node at beginning
 * @head: Head of double list
 * @n: New node
 * Return: Address of new element, or NULL if it failed
 */

dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *w;

	if (!head)
		return (NULL);
	w = malloc(sizeof(dlistint_t));
	if (!w)
		return (NULL);
	w->n = n;
	if (*head)
	{
		w->next = *head;
		(*head)->prev = w;
	}
	else
		w->next = NULL;
	w->prev = NULL;
	*head = w;
	return (w);
}

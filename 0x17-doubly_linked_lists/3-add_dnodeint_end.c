#include "lists.h"

/**
 * add_dnodeint_end - adds new node at end
 * @head: Head of double list
 * @n: New node
 * Return: Address of new element, or NULL if it failed
 */

dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *w;
	dlistint_t *current;

	if (!head)
		return (NULL);
	w = malloc(sizeof(dlistint_t));
	if (!w)
		return (NULL);
	w->n = n;
	w->next = NULL;
	current = *head;
	if (*head)
	{
		while (current && current->next)
			current = current->next;
		current->next = w;
		w->prev = current;
	}
	else
	{
		w->prev = NULL;
		*head = w;
	}
	return (w);
}

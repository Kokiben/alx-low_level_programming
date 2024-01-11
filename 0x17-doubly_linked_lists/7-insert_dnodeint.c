#include "lists.h"

/**
 * add_dnodeint_end - adds new node at end
 * @head: Head of double list
 * @n: New node
 * Return: Address of new element, or NULL if it failed
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n);
/**
 * add_dnodeint -  adds new node at beginning
 * @head: Head of double list
 * @n: New node
 * Return: Address of new element, or NULL if it failed
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n);
/**
 * insert_dnodeint_at_index -  Inserts
 * node at give pstion
 * @h: Head of double list
 * @idx: Index where to insert
 * @n: val to insert
 * Return: Address of new node
 * or NULL if it failed
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *nv, *w, *befo;
	unsigned int a = 0;

	if (!h)
		return (NULL);
	nv = *h;
	w = malloc(sizeof(dlistint_t));
	if (!w)
		return (NULL);
	w->n = n;
	w->next = NULL;
	if (idx == 0)
		return (add_dnodeint(h, n));
	while (nv)
	{
		if (a == idx - 1)
			befo = nv;

		if (a == idx)
		{
			w->next = nv;
			nv->prev = w;
			befo->next = w;
			w->prev = befo;
			return (w);
		}
		if (!nv->next && a + 1 == idx)
			return (add_dnodeint_end(h, n));
		nv = nv->next;
		a++;
	}
	return (NULL);
}

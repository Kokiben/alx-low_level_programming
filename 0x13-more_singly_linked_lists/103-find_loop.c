#include "lists.h"

/**
* find_listint_loop - Finds loop in a linked list.
* @head: head of a list or linked list to search.
*
* Return: The addres of node where the loop start
*/

listint_t *find_listint_loop(listint_t *head)
{

listint_t *d, *c;

if (head == NULL)
{
return (NULL);
}
d = head;
c = d;
while (d && c)
{
d = d->next;
c = c->next->next;

if (d == c)
{
d = c;
while (d != c)
{
d = d->next;
c = c->next;
}
return (d);
}
}
return (NULL);
}

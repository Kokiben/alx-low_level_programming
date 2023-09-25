#include "lists.h"

/**
* insert_nodeint_at_index - inserts the new node in linked list
* at a given position.
* @head: head of the list.
* @idx: index of the list where a new node is added
* @n: int element or data to insert in new node.
*
* Return: address of new node, or NULL
* if it failed
*/

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
unsigned int b;
listint_t *new;
listint_t *h;

h = *head;

if (idx != 0)
{
for (b = 0; b < idx - 1 && h != NULL; b++)
{
h = h->next;
}
}

if (h == NULL && idx != 0)
return (NULL);

new = malloc(sizeof(listint_t));

if (new == NULL)
return (NULL);

new->n = n;
if (idx == 0)
{
new->next = *head;
*head = new;
}
else
{
new->next = h->next;

h->next = new;
}
return (new);
}

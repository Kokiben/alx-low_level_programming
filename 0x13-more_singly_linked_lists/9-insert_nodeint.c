#include "lists.h"

/**
* insert_nodeint_at_index - inserts a new node in linked list
* at a given position.
* @head: head of the list.
* @idx: index of a list where the new node is added
* @n: integer element or data to insert in new node.
*
* Return: address of new node, or NULL
* if it failed
*/

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
unsigned int i;
listint_t *new;
listint_t *a;

a = *head;

if (idx != 0)
{
for (i = 0; i < idx - 1 && a != NULL; i++)
{
a = a->next;
}
}

if (a == NULL && idx != 0)
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
new->next = a->next;

a->next = new;
}
return (new);
}

#include "lists.h"

/**
* pop_listint - deletes the head node of the
* the linked list
* @head: head of a list
*
* Return: a head node's data
*/


int pop_listint(listint_t **head)
{
int node;
listint_t *h;
listint_t *lis;

if (*head == NULL)
return (0);

lis = *head;

node = lis->n;

h = lis->next;

free(lis);

*head = h;

return (node);
}

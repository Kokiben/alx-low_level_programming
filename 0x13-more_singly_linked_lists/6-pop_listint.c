#include "lists.h"

/**
* pop_listint - deletes the head node of
* linked list
* @head: head of a list
*
* Return: the head node's data
*/


int pop_listint(listint_t **head)
{
int node;
listint_t *A;
listint_t *Y;

if (*head == NULL)
return (0);

Y = *head;

node = Y->n;

A = Y->next;

free(Y);

*head = A;

return (node);
}

#include "lists.h"

/**
* reverse_listint - Reverses a linked list.
* @head: head of a list.
*
* Return: pointer to first node.
*/
listint_t *reverse_listint(listint_t **head)
{
listint_t *i;
listint_t *r;

i = NULL;
r = NULL;

while (*head != NULL)
{
r = (*head)->next;
(*head)->next = i;
i = *head;
*head = r;
}

*head = i;
return (*head);
}

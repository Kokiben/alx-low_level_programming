#include "lists.h"

/**
* free_listint - frees a linked the list
* @head: head of list
*
* Return: no return
*/

void free_listint(listint_t *head)
{
listint_t *X;

while ((X = head) != NULL)
{
head = head->next;
free(X);
}
}

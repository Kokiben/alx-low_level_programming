#include "lists.h"

/**
* free_listint2 - frees a linked the list
* @head: head of list
*
* Return: no return
*/


void free_listint2(listint_t **head)
{
listint_t *X;
listint_t *Y;

if (head != NULL)
{
Y = *head;
while ((X = Y) != NULL)
{
Y = Y->next;
free(X);
}
*head = NULL;
}
}

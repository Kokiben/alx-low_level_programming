#include "lists.h"

/**
* free_listint2 - frees a linked a list
* @head: head of the list
*
* Return: no return
*/


void free_listint2(listint_t **head)
{
listint_t *temp;
listint_t *lis;

if (head != NULL)
{
lis = *head;
while ((temp = lis) != NULL)
{
lis = lis->next;
free(temp);
}
*head = NULL;
}
}

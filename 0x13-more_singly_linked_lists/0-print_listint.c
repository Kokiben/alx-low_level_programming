#include "lists.h"

/**
* print_listint - prints all elements of list.
* @h: head of a list for linked list
*
* Return: num of nodes.
*/
size_t print_listint(const listint_t *h)
{
size_t Num = 0;
while (h != NULL)
{
printf("%d\n", h->n);
h = h->next;
Num++;
}
return (Num);
}

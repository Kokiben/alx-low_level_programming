#include "lists.h"

/**
* listint_len - returns of num of the  elements in
* the linked list.
* @h: top of a list for linked list.
*
* Return: num of nodes
*/

size_t listint_len(const listint_t *h)
{
size_t Num = 0;

while (h != NULL)
{
h = h->next;
Num++;
}
return (Num);
}

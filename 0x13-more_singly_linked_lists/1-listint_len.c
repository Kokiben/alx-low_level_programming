#include "lists.h"

/**
* listint_len - returns of the number of elements in
* the linked list.
* @h: head of a list for linked list.
*
* Return: numbers of nodes
*/

size_t listint_len(const listint_t *h)
{
size_t num = 0;

while (h != NULL)
{
h = h->next;
num++;
}
return (num);
}

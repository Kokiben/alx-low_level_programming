#include "lists.h"
#include <stdlib.h>

/**
* list_len - returns of the number of elements in
* the linked list.
* @h: head of a list for linked list.
*
* Return: numbers of elements in h
*/
size_t list_len(const list_t *h)
{
size_t n = 0;

while (h)
{
n++;
h = h->next;
}
return (n);
}

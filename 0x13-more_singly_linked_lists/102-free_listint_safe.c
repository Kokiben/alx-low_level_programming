#include "lists.h"

/**
* free_listint_safe - frees a linked list, even if it has a loop.
* @h: pointer to the head of list.
*
* Return: num of nodes freed.
*/
size_t free_listint_safe(listint_t **h)
{
size_t node_count = 0;
int set;
listint_t *current, *next_node;

if (h == NULL)
return (0);

while (*h != NULL)
{
set = *h - (*h)->next;
if (set > 0)
{
current = *h;
next_node = (*h)->next;
*h = next_node;
free(current);
node_count++;
}
else
{
node_count++;
free(*h);
*h = NULL;
break;
}
}
*h = NULL;
return (node_count);
}

#include "lists.h"

/**
* get_nodeint_at_index - returns the nth node of the linked list
* @head: a head of the list.
* @index: index of the node
*
* Return: if node does not exist, returns NULL.
*/

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
unsigned int b;

for (b = 0; b < index && head != NULL; b++)
{
head = head->next;
}

return (head);
}

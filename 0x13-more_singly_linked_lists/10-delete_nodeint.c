#include "lists.h"

/**
* delete_nodeint_at_index - delet node at a index
* off a linked list
* @head: head of a list.
* @index: index of list where the node is deleted.
*
* Return: 1 (Success) if it Succeeded, -1 (Fail) if it failed
*/

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
unsigned int b;
listint_t *abbr;
listint_t *next;
abbr = *head;


if (index != 0)
{
for (b = 0; b < index - 1 && abbr != NULL; b++)
{
abbr = abbr->next;
}
}

if (abbr == NULL || (abbr->next == NULL && index != 0))
{
return (-1);
}

next = abbr->next;

if (index != 0)
{
abbr->next = next->next;
free(next);
}
else
{
free(abbr);
*head = next;
}
return (1);
}

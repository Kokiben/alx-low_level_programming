#include "lists.h"

/**
* add_nodeint_end - Add a new node at end
* of linked list
* @head: head of a list
* @n: new element.
*
* Return: address of new element NUll if it failed
*/
listint_t *add_nodeint_end(listint_t **head, const int n)
{
listint_t *new;
listint_t *X;

(void)X;

new = malloc(sizeof(listint_t));

if (new == NULL)
return (NULL);

new->n = n;
new->next = NULL;
X = *head;
if (*head == NULL)
{
*head = new;
}
else
{
while (X->next != NULL)
{
X = X->next;
}
X->next = new;
}

return (new);
}

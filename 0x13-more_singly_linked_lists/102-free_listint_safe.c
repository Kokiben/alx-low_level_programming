#include "lists.h"

/**
* free_listp2 - frees a linked list
* @head: pointer to the first node orhead of a list
*
* Return: no return
*/
void free_listp2(listp_t **head)
{
listp_t *temp;
listp_t *bir;

if (head != NULL)
{
bir = *head;
while ((temp = bir) != NULL)
{
bir = bir->next;
free(temp);
}
*head = NULL;
}
}

/**
* free_listint_safe - frees a linked list.
* @h: head of a list.
*
* Return: size of the list that was freed.
*/
size_t free_listint_safe(listint_t **h)
{
size_t numnode = 0;
listp_t *hp, *new, *add;
listint_t *bir;

hp = NULL;
while (*h != NULL)
{
new = malloc(sizeof(listp_t));

if (new == NULL)
exit(98);
new->p = (void *)*h;
new->next = hp;
hp = new;

add = hp;

while (add->next != NULL)
{
add = add->next;
if (*h == add->p)
{
*h = NULL;
free_listp2(&hp);
return (numnode);
}
}

bir = *h;
*h = (*h)->next;
free(bir);
numnode++;
}
*h = NULL;
free_listp2(&hp)
return (numnode);
}

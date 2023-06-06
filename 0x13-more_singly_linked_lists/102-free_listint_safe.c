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
listp_t *lis;
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

/**
* free_listint_safe - frees a linked list.
* @h: head of a list.
*
* Return: size of the list that was freed.
*/
size_t free_listint_safe(listint_t **h)
{
size_t num = 0;
listp_t *hp, *new, *add;
listint_t *lis;

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
return (num);
}
}

lis = *h;
*h = (*h)->next;
free(lis);
num++;
}

*h = NULL;
free_listp2(&hp);
return (num);
}

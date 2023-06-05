#include "lists.h"

/**
* find_listint_loop - finds loop in a linked list.
* @head: head of a list or linked list to search.
*
* Return: the addres of the node where the loop start
*/

listint_t *find_listint_loop(listint_t *head)
{

listint_t *l2;
listint_t *lis;

l2 = head;
lis = head;
while (head && l2 && l2->next)
{
head = head->next;
l2 = l2->next->next;

if (head == l2)
{
head = lis;
lis =  l2;
while (1)
{
l2 = lis;
while (l2->next != head && l2->next != lis)
{
l2 = l2->next;
}
if (l2->next == head)
break;

head = head->next;
}
return (l2->next);
}
}
return (NULL);
}

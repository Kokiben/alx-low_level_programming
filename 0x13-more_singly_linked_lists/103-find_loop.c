#include "lists.h"

/**
* find_listint_loop - finds loop in a linked list.
* @head: head of a list or linked list to search.
*
* Return: the addres of the node where the loop start
*/

listint_t *find_listint_loop(listint_t *head)
{

listint_t *p3;
listint_t *pre;

p3 = head;
pre = head;
while (head && p3 && p3->next)
{
head = head->next;
p3 = p3->next->next;

if (head == p3)
{
head = pre;
pre =  p3;
while (1)
{
p3 = pre;
while (p3->next != head && p3->next != pre)
{
p3 = p3->next;
}
if (p3->next == head)
break;

head = head->next;
}
return (p3->next);
}
}
return (NULL);
}

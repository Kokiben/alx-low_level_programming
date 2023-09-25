#include "lists.h"
#include <stdio.h>

size_t looped_listint_len(const listint_t *head);
size_t print_listint_safe(const listint_t *head);

/**
* looped_listint_len - Counts num of unique nodes
*                      in a looped listint_t linked list.
* @head: a pointer to head of the listint_t to check.
*
* Return: if the list is not looped - 0.
*         otherwise - the num of unique nodes in the list.
*/
size_t looped_listint_len(const listint_t *head)
{
const listint_t *slow, *fast;
size_t nodes = 1;

if (head == NULL || head->next == NULL)
return (0);

/* initialize the slow and fast  pointers */
slow = head->next;
fast = (head->next)->next;
while (fast)
{
if (slow == fast)
{
/* if pointers meet, reset the slow pointer to the head node */
slow = head;

/* iterate through list with both pointers until they meet again */
while (slow != fast)
{
nodes++;
slow = slow->next;
fast = fast->next;
}
slow = slow->next;
while (slow != fast)
{
nodes++;
slow = slow->next;
}

/* return the num of unique nodes in the loop */
return (nodes);
}

/* update the slow and fast pointers */
slow = slow->next;
fast = (fast->next)->next;
}

/* return 0 if list is not looped */
return (0);
}

/**
* print_listint_safe - Prints a listint_t list safely.
* @head: a pointer to the head of the listint_t list.
*
* Return: the num of nodes in list.
*/
size_t print_listint_safe(const listint_t *head)
{
size_t nodes, index = 0;

/* check if list is looped and get the num of unique nodes */
nodes = looped_listint_len(head);

/* if  list is not looped, print each node and increment node count */
if (nodes == 0)
{
for (; head != NULL; nodes++)
{
printf("[%p] %d\n", (void *)head, head->n);
head = head->next;
}
}
else
{
for (index = 0; index < nodes; index++)
{
printf("[%p] %d\n", (void *)head, head->n);
head = head->next;
}

printf("-> [%p] %d\n", (void *)head, head->n);
}

/* return the num of nodes in the list */
return (nodes);
}

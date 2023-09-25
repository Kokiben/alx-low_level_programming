#include "lists.h"

/**
 * sum_listint - returns or calculates sum of all the data
 * of the linked list
 * @head: head of a list
 *
 * Return: Sum of all the data.
 */

int sum_listint(listint_t *head)
{
int sum;
sum = 0;

while (head != NULL)
{
sum += head->n;
head = head->next;
}

return (sum);
}

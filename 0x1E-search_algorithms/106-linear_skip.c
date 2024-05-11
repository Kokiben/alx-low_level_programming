#include "search_algos.h"

/**
 * linear_skip - function searches for a value in a sorted skip list of in
 *
 * @list: ptr to head of skip list to search in
 * @value: Value to search for
 * Return: ptr on first node where value is located
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
skiplist_t *Head;

if (list == NULL)
return (NULL);

Head = list;

do {
list = Head;
Head = Head->express;
printf("Value checked at index ");
printf("[%d] = [%d]\n", (int)Head->index, Head->n);
} while (Head->express && Head->n < value);

if (Head->express == NULL)
{
list = Head;
while (Head->next)
Head = Head->next;
}

printf("Value found between indexes ");
printf("[%d] and [%d]\n", (int)list->index, (int)Head->index);

while (list != Head->next)
{
printf("Value checked at index [%d] = [%d]\n", (int)list->index, list->n);
if (list->n == value)
return (list);
list = list->next;
}

return (NULL);
}

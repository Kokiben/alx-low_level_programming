#include "search_algos.h"
#include <math.h>

/**
 * jump_list - searches for a value in an array of
 * integers using the Jump search algorithm
 *
 * @list: ptr to head of list to search in
 * @size: the number of nodes in list
 * @value: the value to search for
 * Return: pointer to the first node where value
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
size_t index = 0;
size_t L = 0;
size_t Q;
listint_t *jump;

if (list == NULL || size == 0)
return (NULL);

Q = (size_t)sqrt((double)size);

do {
jump = list;
L++;
index = L *Q;

while (list->next && list->index < index)
list = list->next;

if (list->next == NULL && index != list->index)
index = list->index;

printf("Value checked at index [%d] = [%d]\n", (int)index, list->n);

} while (index < size && list->next && list->n < value);

printf("Value found between indexes ");
printf("[%d] and [%d]\n", (int)jump->index, (int)list->index);

for (; jump && jump->index <= list->index; jump = jump->next)
{
printf("Value checked at index [%d] = [%d]\n", (int)jump->index, jump->n);
if (jump->n == value)
return (jump);
}

return (NULL);
}

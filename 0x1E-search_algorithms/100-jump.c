#include "search_algos.h"
#include <math.h>

/**
 * jump_search - function for searches for a value in a sorted array of int
 *
 * @array: ptr to first element of array
 * @size: number of elements in array
 * @value: value to search for
 * Return: first index where value is located
 */
int jump_search(int *array, size_t size, int value)
{
int idx, j, l, jump;

if (array == NULL || size == 0)
return (-1);

j = (int)sqrt((double)size);
l = 0;
jump = idx = 0;

do {
printf("Value checked array[%d] = [%d]\n", idx, array[idx]);

if (array[idx] == value)
return (idx);
l++;
jump = idx;
idx = l * j;
} while (idx < (int)size && array[idx] < value);

printf("Value found between indexes [%d] and [%d]\n", jump, idx);

for (; jump <= idx && jump < (int)size; jump++)
{
printf("Value checked array[%d] = [%d]\n", jump, array[jump]);
if (array[jump] == value)
return (jump);
}

return (-1);
}

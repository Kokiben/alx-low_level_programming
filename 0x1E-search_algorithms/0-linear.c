#include <stdlib.h>
#include <stdio.h>
#include "search_algos.h"

/**
 * linear_search - function
 * @array: ptr to the first element of the array to search
 * @size: the number of elements in array
 * @value: the value to search for
 *
 * Return: Return
 */
int linear_search(int *array, size_t size, int value)
{
size_t s = 0;
for (s = 0; s < size; s++)
{
printf("Value checked array[%ld] = [%d]\n", s, array[s]);
if (array[s] == value)
return (s);
}
return (-1);
}

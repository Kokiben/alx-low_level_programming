#include "search_algos.h"

/**
 * interpolation_search - function for searches value
 * sorted array of int using
 *
 * @array: ptr to first element of array
 * @size: nbr of elements in array
 * @value: Value to search for
 * Return: First index where value is located
 */
int interpolation_search(int *array, size_t size, int value)
{
size_t low = 0;
size_t high = size - 1;
size_t pos;
double P;

if (array == NULL)
return (-1);

while (size)
{
P = (double)(high - low) / (array[high] - array[low]) * (value - array[low]);
pos = (size_t)(low + P);
printf("Value checked array[%d]", (int)pos);

if (pos >= size)
{
printf(" Out of range\n");
break;
}
else
{
printf(" = [%d]\n", array[pos]);
}

if (array[pos] == value)
return ((int)pos);

if (array[pos] < value)
low = pos + 1;
else
high = pos - 1;

if (low == high)
break;
}

return (-1);
}

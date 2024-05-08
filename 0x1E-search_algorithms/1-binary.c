#include "search_algos.h"

/**
 * binary_search -  Searches for a value in a sorted array of int
 * @array: ptr to first element of array to search in
 * @size: The nums of elements in array
 * @value: The value to search for
 *
 * Return: -1
 */

int binary_search(int *array, size_t size, int value)
{
int w, d, gh, i;
w = 0;
gh = size - 1;

if (array == NULL)
{
return (-1);
}


while (w <= gh)
{
d = (w + gh) / 2;

printf("Looking through an array: ");
for (i = w; i <= gh; i++)
printf("%i%s", array[i], i == gh ? "\n" : ", ");

if (array[d] < value)
w = d + 1;
else if (array[d] > value)
gh = d - 1;
else
return (d);
}

return (-1);
}

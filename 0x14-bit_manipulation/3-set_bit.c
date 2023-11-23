#include "main.h"

/**
 * set_bit - Sets bit at index.
 * @n: num to index.
 * @index: Bit to set.
 *
 * Return: 1 if successful, or -1 if an error
 */
int set_bit(unsigned long int *n, unsigned int index)
{
unsigned long int k;

if (index >= (sizeof(n) * 8))
return (-1);

k = 1 << index;
*n |= k;

return (1);
}

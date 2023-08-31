#include "main.h"

/**
* set_bit - Sets value of a bit to 1
* at a given index.
* @n: Input value.
* @index: Index, starting from 0
* of bit you want to set
* Return: 1 If success, or -1 if error.
*/
int set_bit(unsigned long int *n, unsigned int index)
{
unsigned int s;
unsigned long int i;

s = (sizeof(unsigned long int) * 8);
if (index > s)
{
return (-1);
}

i = 1 << index;
*n = (*n | i);
return (1);
}

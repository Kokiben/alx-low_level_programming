#include "main.h"

/**
* clear_bit - Sets value of a bit to 0
* at a given index.
* @n:Input value.
* @index: Index, starting from 0
* of bit you want to set
* Return: 1 If success, or -1 if error.
*/
int clear_bit(unsigned long int *n, unsigned int index)
{
unsigned int s;
unsigned long int i;

/* Which is  64*/
s = (sizeof(unsigned long int) * 8);
if (index > s)
{
return (-1);
}
/* For 8 bit and index two it will be 11111011*/
i = ~(1 << index);
*n = (*n & i);
return (1);
}

#include "main.h"

/**
* flip_bits - Returns num of bits you would need
* to flip to get from one num to another.
* @n: Input value.
* @m: Other value.
* Return: Num of bits.
*/
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
unsigned int i = 0;
unsigned long int b;

b = n ^ m;
i += (b & 1);
b = b >> 1;
while (b > 0)
{
i += (b & 1);
b = b >> 1;
}
return (i);
}

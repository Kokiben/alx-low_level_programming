#include "main.h"

/**
 * flip_bits - returns num of bits to flip from n to m.
 * @n: First num.
 * @m: Second num.
 *
 * Return: number of bits to flip.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
unsigned long int xorV = n ^ m;
unsigned int cont = 0;

while (xorV > 0)
{
cont += xorV & 1;
xorV >>= 1;
}

return (cont);
}

#include "main.h"
#include <stdio.h>

/**
* print_binary - Converts unsigned integer to binary
* @h: Unsigned integer
* Return: Binary
*/
void print_binary(unsigned long int h)
{
unsigned long int i, k;

if (h == 0)
{
_putchar('0');
}
i = h;
k = 1ul << 63;
while (k != 0 && (i & k) == 0)
{
k = (k >> 1);
}
while (k > 0)
{

if ((i & k) == 0)
{
_putchar('0');
}
else
{
_putchar('1');
}
k = (k >> 1);
}
}

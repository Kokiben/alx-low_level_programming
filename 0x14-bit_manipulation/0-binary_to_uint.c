#include "main.h"

/**
* binary_to_uint - converts a binary number to unsigned int
* @b: string containing the binary number
*
* Return: the converted number, or 0 if the string is invalid
*/
unsigned int binary_to_uint(const char *b)
{
unsigned int x = 0;

if (!b)
return (0);

for (; *b; b++)
{
if (*b != '0' && *b != '1')
return (0);
x = (x << 1) | (*b - '0');
}
return (x);
}

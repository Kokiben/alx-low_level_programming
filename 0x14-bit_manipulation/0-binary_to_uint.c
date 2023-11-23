#include "main.h"

/**
 * binary_to_uint - Convert binary numstr to unsigned int.
 * @b: Binary num as a str.
 *
 * Return: unsigned integer style b
 *
 */
unsigned int binary_to_uint(const char *b)
{
unsigned int M = 0;

if (!b)
return (0);

while (*b)
{
if (*b != '0' && *b != '1')
return (0);
M = (M << 1) | (*b - '0');
b++;
}

return (M);
}

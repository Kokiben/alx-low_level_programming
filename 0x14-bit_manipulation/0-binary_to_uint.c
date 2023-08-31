#include "main.h"

/**
* _strlen - Return length of a string.
* @h: Input string.
* Return: length of the input.
*/
unsigned int _strlen(const char *h)
{
if (*h == '\0' || *h == '\n' || *h == 0)
return (0);
h++;
return (1 + _strlen(h));
}
/**
* poweroftwo - Calculate power of 2.
* @m: Power value.
* Return: 2 to power m.
*/
unsigned int poweroftwo(unsigned int m)
{
unsigned int s, l;

s = 1;
l = 2;
if (m == 1)
{
return (1);
}
while (l <= m)
{
s *= 2;
l++;
}
return (s);
}



/**
* binary_to_uint - Converts a binary num to an unsigned integer.
* @n: Input value.
* Return: Converted num, or 0.
*/
unsigned int binary_to_uint(const char *n)
{
unsigned int l, leng, s = 0, f;

if (n == NULL)
{
return (0);
}
leng = _strlen(n);
for (l = 0; l <= leng - 1; l++)
{
f = n[l] - '0';
if (f == 1)
{
/* s += f * poweroftwo((leng - l)); */
s += (f << (leng - l - 1));
}
else if ((f != 0) && (f != 1))
{
return (0);
}
}
return (s);
}

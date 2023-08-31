#include "main.h"

/**
* get_endianness - Checks endianness.
* Return: 0 if big endian, 1 if little endian.
*/
int get_endianness(void)
{
int i, k;
char *s;

/**
* Value of i = 1 if big endian
* |00000000|00000000|00000000|00000001
* so the s will take the first 8 bits which have value of 0
*/
i = 1;
s = (char *)&i;
k = *s + '0';
return (k);
}

#include "main.h"

/**
* get_endianness - Checks endianness.
* Return: 0 If big endian, 1 if little endian.
*/
int get_endianness(void)
{
int n, k;
char *s;

/**
* Value of n = 1 if big endian
* |00000000|00000000|00000000|00000001
* So the s will take the first 8 bits which have value of 0
*/
n = 1;
s = (char *)&n;
k = *s + '0';
return (k);
}

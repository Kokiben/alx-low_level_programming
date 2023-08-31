#include "main.h"

/**
* get_endianness - Checks endianness.
* Return: 0 if big endian, 1 if little endian.
*/
int get_endianness(void)
{

int k = 1;
char *n = (char *)&k;
return (*n);

}

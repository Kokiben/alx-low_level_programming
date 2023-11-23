#include "main.h"

/**
 * get_endianness - function that checks the endianness.
 *
 * Return: 0 if big endian, 1 if little .
 */
int get_endianness(void)
{
unsigned long int M = 1;

return (*(char *)&M);
}

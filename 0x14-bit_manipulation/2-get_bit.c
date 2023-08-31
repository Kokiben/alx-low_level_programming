#include "main.h"

/**
* get_bit - Return value of a bit at a given index.
* @n: Input num.
* @index: index,
* Starting from 0 of the bit you want to get.
* Return: value of the bit at index
* Index or -1 if an error occured.
*/
int get_bit(unsigned long int n, unsigned int index)
{
unsigned int s;

/* 64 or 63*/
s = (sizeof(unsigned long int) * 8);
if (index > s)
{
return (-1);
}
return ((n >> index) & 1);
}

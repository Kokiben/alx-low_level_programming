include "main.h"

/**
 * _isupper - entry pt
 * @c: char
 *
 * Description: checks for uppercase char
 * Return: 1 if c is uppercase 0 otherwise
 */
int _isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	else
		return (0);
}

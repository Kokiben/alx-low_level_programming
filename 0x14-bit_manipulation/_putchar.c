#include "main.h"

/**
* _putchar - Writes char c to stdout.
 * @c: Char to print.
 * Return: On success 1.
 */
int _putchar(char c)
{
return (write(1, &c, 1));
}

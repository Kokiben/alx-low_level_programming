#include "main.h"

/**
* _puts_recursion - function like pûts();
* @s: input
* Return: Always 0 (success)
*/

void _puts_recursion(char *s)

{
if (*s == '\0')
{
_putchar('\n');
return;
}

_putchar(*s);
s++;

_puts_recursion(s);
}

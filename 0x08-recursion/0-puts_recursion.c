#include "main.h"

/**
* _puts_recursion - function like pûts();
* @s: input
* Return: Always 0 (success)
*/

void _puts_recursion(char *s)

{
if (*s)

{
_putchar(*s);
_putchar(s + 1);

}

else
_putchar('\n');

}

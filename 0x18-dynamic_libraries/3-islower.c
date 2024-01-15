#include "main.h"

/**
 * _islower - ddzq
 * @c: Description of parameter x
 *
 * Description: ddzq
 * section header: Section description
 * Return: Description of value
 */
int _islower(int c)
{
	if (c >= 65 && c <=  90)
		return (0);
	else if (c >= 97 && c <= 122)
		return (1);
	else
		return (0);
}

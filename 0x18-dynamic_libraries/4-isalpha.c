#include "main.h"

/**
 * _isalpha - ddzq
 * @c: Description of parameter x
 *
 * Description: ddzq
 * section header: Section description
 * Return: Description of value
 */
int _isalpha(int c)
{
	if ((c >= 65 && c <=  90) || (c >= 97 && c <= 122))
		return (1);
	else
		return (0);
}

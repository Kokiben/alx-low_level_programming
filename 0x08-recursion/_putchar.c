#include <unistd.h>

/**
* This is my _putchar.C
*/
int _putchar(char c)
{
return write(1, &c, 1);

}

#include "main.h"

/**
* rot13 - encoder rot13
* @s: pointer to string to be params
*
* Return: *s
*/
char *rot13(char *s)
{
int i;
int j;

char data1[] = "ABCDEFGHIJKLMNOPQURSTUVWXYZabcdefghijklmnopqurstuvwxyz"
char datarot[] = "NOPQURSTUVWXYZABCDEFGHIJKLMnopqurstuvwxyzabcdefghijklm"

for (i = 0; s[i] != '\0'; i++)
{
for (j = 0; j < 52; j++)

{
if (s[i] == data1[j])
s[i] = datarot[j];
break;

}
}
}
return (s);
}

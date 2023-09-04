#include "main.h"

/**
 * create_file - creates a file.
 * @filename: a pointer to name of file to create.
 * @text_content: a pointer to a string to write to file.
 *
 * Return: if funct fails - -1.
 *         Otherwise - 1.
 */
int create_file(const char *filename, char *text_content)
{
int d, a, leng = 0;

if (filename == NULL)
return (-1);

if (text_content != NULL)
{
for (leng = 0; text_content[leng];)
leng++;
}

d = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
a = write(d, text_content, leng);

if (d == -1 || a == -1)
return (-1);

close(d);

return (1);
}

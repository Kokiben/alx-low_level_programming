#include "main.h"

/**
 * append_text_to_file - appends text at end of a file.
 * @filename: a pointer to name of  file.
 * @text_content: String to add to end of file.
 *
 * Return: if func fails or filename is NULL - -1.
 *         if file does not exist user lacks write permissions - -1.
 *         Otherwise - 1.
 */
int append_text_to_file(const char *filename, char *text_content)
{
int s, a, leng = 0;

if (filename == NULL)
return (-1);

if (text_content != NULL)
{
for (leng = 0; text_content[leng];)
leng++;
}

s = open(filename, O_WRONLY | O_APPEND);
a = write(s, text_content, leng);

if (s == -1 || a == -1)
return (-1);

close(s);

return (1);
}

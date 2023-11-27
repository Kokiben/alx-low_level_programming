#include "main.h"
#include <fcntl.h>
#include <unistd.h>

/**
 * append_text_to_file - appends text to file.
 * @filename: name of file to create .
 * @text_content: text to write.
 *
 * Return: 1 on success, -1 on failure.
 */

int append_text_to_file(const char *filename, char *text_content)
{
size_t txt_leng = 0;
int byte_wrt, fd;

if (filename == NULL)
return (-1);

fd = open(filename, O_WRONLY | O_APPEND);
if (fd == -1)
return (-1);

if (text_content != NULL)
{
while (text_content[txt_leng] != '\0')
txt_leng++;
	}

byte_wrt = write(fd, text_content, txt_leng);

if (byte_wrt == -1)
{
close(fd);
return (-1);
}

close(fd);
return (1);
}


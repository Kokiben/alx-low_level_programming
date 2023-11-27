#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>


/**
 * create_file - Creates a file
 * @filename: name of file to create
 * @text_content: text to write
 *
 * Return: 1 on success, -1 on failure
 */

int create_file(const char *filename, char *text_content)
{
int wrt_leng, leng = 0, fd;


if (filename == NULL)
return (-1);

fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
if (fd == -1)
return (-1);


if (text_content != NULL)
{
while (text_content[leng])
leng++;


wrt_leng = write(fd, text_content, leng);
if (wrt_leng != leng)
{
close(fd);
return (-1);
}
}

close(fd);
return (1);
}

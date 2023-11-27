#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * read_textfile - reads and prints a text file.
 * @filename: name of file to read.
 * @letters: num of letters it should read.
 *
 * Return: num of letters read/printed.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
ssize_t byte_wrt,byte_rd;
char *buf;
int fd;

if (filename == NULL)
return (0);

fd = open(filename, O_RDONLY);
if (fd == -1)
return (0);
buf = malloc(sizeof(char) * letters);

if (buf == NULL)
{
close(fd);
return (0);
}
byte_rd = read(fd, buf, letters);

if (byte_rd == -1)
{
free(buf);
close(fd);
return (0);
}
byte_wrt = write(STDOUT_FILENO, buf, byte_rd);

free(buf);
close(fd);
if (byte_wrt == -1 || byte_wrt != byte_rd)
return (0);
return (byte_wrt);
}

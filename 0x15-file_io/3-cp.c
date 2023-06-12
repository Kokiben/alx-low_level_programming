#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *file);
void close_file(int fd);

/**
* create_buffer - to Allocates 1024 bytes for buffer
* @file: The name of the file buffer is storing chars for
* Return: pointer to the newly-allocated buffer
*/

char *create_buffer(char *file)
{
char *buffer;

buffer = malloc(sizeof(char) * 1024);

if (buffer == NULL)
{
dprintf(STDERR_FILENO,
"Error: Can't write to %s\n", file);
exit(99);
}

return (buffer);
}

/**
* close_file - Closes file descriptors
* @fd: The file descriptor to be closed
* closed.
*/
void close_file(int fd)
{
int cl;

cl = close(fd);

if (cl == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
exit(100);
}
}

/**
* main - Copies the contents of a file to another file.
* @argc: the number of arguments passed to the program
* @argv: the array of arguments passed to the program
* Return: 0 if successful, 97-100 on failure
*
* Description: If the argument count is incorrect - return 97
* If file_from does not exist or cannot be read - return 98
* If file_to cannot be created or written to - return 99
* If file_to or file_from cannot be closed - return 100
*/
int main(int argc, char *argv[])
{
int from, to, bytes_r, bytes_w;
char *buffer;

/* Check for the correct number of arguments */
if (argc != 3)
{
dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
exit(97);
}

buffer = create_buffer(argv[2]);
from = open(argv[1], O_RDONLY);
bytes_r = read(from, buffer, 1024);
to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

do {
if (from == -1 || bytes_r == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
free(buffer);
exit(98);
}

bytes_w = write(to, buffer, bytes_r);
if (to == -1 || bytes_w == -1)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
free(buffer);
exit(99);
}

bytes_r = read(from, buffer, 1024);
to = open(argv[2], O_WRONLY | O_APPEND);

} while (bytes_r > 0);

free(buffer);
close_file(from);
close_file(to);

return (0);
}

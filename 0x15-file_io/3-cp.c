#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *f);
void close_file(int d);

/**
* create_buffer - allocates 1024 bytes for a buf.
* @f: the name of file buf is storing characters for.
*
* Return: a pointer to newly-allocated buf.
*/
char *create_buffer(char *f)
{
char *buf;

buf = malloc(sizeof(char) * 1024);

if (buf == NULL)
{
dprintf(STDERR_FILENO,
"Error: Can't write to %s\n", f);
exit(99);
}

return (buf);
}
/**
 * close_file - closes file descriptors.
 * @d: file descriptor to be closed.
 */
void close_file(int d)
{
int s;

s = close(d);

if (s == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", d);
exit(100);
}
}
/**
 * main - copies contents of a file to another file.
 * @argc: num of arguments supplied to program.
 * @argv: an array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: if argument count is incorrect - exit code 97.
 * if file_from does not exist or cannot be read - exit code 98.
 * if file_to cannot be created or written to - exit code 99.
 * if file_to or file_from cannot be closed - exit code 100.
 */
int main(int argc, char *argv[])
{
int ffm, t, k, l;
char *buf;

if (argc != 3)
{
dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
exit(97);
}

buf = create_buffer(argv[2]);
ffm = open(argv[1], O_RDONLY);
k = read(ffm, buf, 1024);
t = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

do {
if (ffm == -1 || k == -1)
{
dprintf(STDERR_FILENO,
"Error: Can't read from file %s\n", argv[1]);
free(buf);
exit(98);
}

l = write(t, buf, k);
if (t == -1 || l == -1)
{
dprintf(STDERR_FILENO,
"Error: Can't write to %s\n", argv[2]);
free(buf);
exit(99);
}

k = read(ffm, buf, 1024);
t = open(argv[2], O_WRONLY | O_APPEND);

} while (k > 0);

free(buf);
close_file(ffm);
close_file(t);

return (0);
}

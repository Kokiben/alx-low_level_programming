#include "main.h"
#include <stdio.h>

int fil_close(int);
/**
 * main - function copy file
 * @argc: num of arguments
 * @argv: pointer arguments
 * Return: 1 on success, exits on failure
 */
int main(int argc, char *argv[])
{
char buf[1024];
int byte_rd = 0, FILEEND = 1, form = -1, fd = -1, err = 0;

if (argc != 3)
{
dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
exit(97);
}

form = open(argv[1], O_RDONLY);
if (form < 0)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
exit(98);
}

fd = open(argv[2], O_WRONLY | O_TRUNC | O_CREAT, 0664);
if (fd < 0)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
fil_close(form);
exit(99);
}

while (FILEEND)
{
FILEEND = read(form, buf, 1024);
if (FILEEND < 0)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
fil_close(form);
fil_close(fd);
exit(98);
}
else if (FILEEND == 0)
break;
byte_rd += FILEEND;
err = write(fd, buf, FILEEND);
if (err < 0)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
fil_close(form);
fil_close(fd);
exit(99);
}
}
err = fil_close(fd);
if (err < 0)
{
fil_close(form);
exit(100);
}
err = fil_close(form);
if (err < 0)
exit(100);
return (0);
}

/**
 * fil_close - close a file/prints, error when closed file
 * @Err_dptor: close file
 * Return: 1 on success, -1 on failure
 */
int fil_close(int Err_dptor)
{
int err;

err = close(Err_dptor);
if (err < 0)
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", Err_dptor);
return (err);
}

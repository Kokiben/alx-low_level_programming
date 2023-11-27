#include "main.h"

/**
 * read_textfile - reads and prints a text file.
 * @filename: The name of file to read.
 * @letters: num of letters it should read.
 *
 * Return: num of letters read and printed.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	char buf[READ_BUF_SIZE *8];
	ssize_t byte;

if (!filename || !letters)
		return (0);

fd = open(filename, O_RDONLY);
if (fd == -1)
return (0);
byte = read(fd, &buf[0], letters);
byte = write(SDTOUT_FILENO, letters);

close(fd);
return (byte);
}

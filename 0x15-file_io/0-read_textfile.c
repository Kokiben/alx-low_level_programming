#include "main.h"
#include <stdlib.h>

/**
 * read_textfile- read text file print to STDOUT.
 * @filename: Text file being read
 * @letters: Num of letters to be read
 * Return: Write actual number of bytes read and printed
 *        0 when function fails or filename is NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
char *bf;
ssize_t d;
ssize_t a;
ssize_t s;

d = open(filename, O_RDONLY);
if (d == -1)
return (0);
bf = malloc(sizeof(char) * letters);
s = read(d, bf, letters);
a = write(STDOUT_FILENO, bf, s);

free(bf);
close(d);
return (a);
}

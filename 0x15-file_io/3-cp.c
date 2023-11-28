#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define BUFFER_SIZE 1024

/**
 * copie_usage_exit - the number of argument is not the correct one,
 * exit with code 97.
 */
void copie_usage_exit(void)
{
dprintf(2, "Usage: cp file_from file_to\n");
exit(97);
}

/**
 * copie_error_exit - error message.
 * @messag: error message to print.
 * @exit_cod: The exit code to use.
 */
void copie_error_exit(const char *messag, int exit_cod)
{
dprintf(2, "%s\n", messag);
exit(exit_cod);
}


/**
 * close_file_exit - close file descriptors and exit .
 * @fd_from: file descriptor.
 * @fd_to: destination file descriptor.
 * @exit_code: exit code to use.
 */
void close_file_exit(int fd_from, int fd_to, int exit_code)
{
	close(fd_from);
	close(fd_to);
	exit(exit_code);
}

int main(int argc, char *argv[])
{
	int fd_from, fd_to;
	ssize_t byte_rd, byte_wrt;
	char buf[BUFFER_SIZE];

if (argc != 3)
copie_usage_exit();

fd_from = open(argv[1], O_RDONLY);
if (fd_from == -1)
copie_error_exit("Error: Can't read from file", 98);

fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
if (fd_to == -1)
copie_error_exit("Error: Can't write to file", 99);

while ((byte_rd = read(fd_from, buf, BUFFER_SIZE)) > 0)
{
byte_wrt = write(fd_to, buf, byte_rd);
if (byte_wrt == -1)
close_file_exit(fd_from, fd_to, 99);
}

if (byte_rd == -1)
close_file_exit(fd_from, fd_to, 98);

if (close(fd_from) == -1 || close(fd_to) == -1)
copie_error_exit("Error: Can't close fd", 100);

chmod(argv[2], S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);

return (0);
}


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>
/**
 * error - ...
 * @msg:...
 */
void error(char *msg)
{
fprintf(stderr, "%s\n", msg);
exit(98);
}
/**
 * print_elf_header - ...
 * @header: ...
 */
void print_elf_header(Elf64_Ehdr *header)
{
int i;
printf("ELF Header:\n");
printf("  Magic:   ");
for (i = 0; i < EI_NIDENT; i++)
{
printf("%02x%c", header->e_ident[i], i == EI_NIDENT - 1 ? '\n' : ' ');
printf("  Class: %s\n", header->e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" : "ELF64");
printf("  Data: %s\n", header->e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" : "2's complement, big endian");
printf("  Version:  %d (current)\n", header->e_ident[EI_VERSION]);
printf("  OS/ABI: %s\n", header->e_ident[EI_OSABI] == ELFOSABI_SYSV ? "UNIX - System V" : "Unknown");
printf("  ABI Version:  %d\n", header->e_ident[EI_ABIVERSION]);
printf("  Type:  %s\n", header->e_type == ET_NONE ? "NONE (Unknown type)" :
header->e_type == ET_REL ? "REL (Relocatable file)" :
header->e_type == ET_EXEC ? "EXEC (Executable file)" :
header->e_type == ET_DYN ? "DYN (Shared object file)" :
header->e_type == ET_CORE ? "CORE (Core file)" :
"Unknown type");
printf("  Entry point address:               0x%lx\n", header->e_entry);
}
}
/**
 * main - ...
 * @argc: ...
 * @argv: ...
 * Return: ...
 */
int main(int argc, char **argv)
{
int fd;
if (argc != 2)
{
fprintf(stderr, "Usage: %s <ELF binary>\n", argv[0]);
return (EXIT_FAILURE);
}
fd = open(argv[1], O_RDONLY);
if (fd < 0)
{
perror("open");
return (EXIT_FAILURE);
}
return (EXIT_SUCCESS);
}

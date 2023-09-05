#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


/**
* print_Magic - Prints value of magic, class
* and value of data also version.
* @header: Information in header.
*/
void print_Magic(char *header)
{
int a;

printf("  Magic:   ");
for (a = 0; a < 16; a++)
{
printf("%02x", header[a]);

if (a != 15)
printf(" ");
else
printf("\n");
}
printf("  %-35s", "Class:");
if (header[4] == 0)
printf("none\n");
else if (header[4] == 1)
printf("ELF32\n");
else if (header[4] == 2)
printf("ELF64\n");
else
printf("<unknown: %02hx>", header[4]);
printf("  %-35s", "Data:");
if (header[5] == 0)
printf("none\n");
else if (header[5] == 1)
printf("2's complement, little endian\n");
else if (header[5] == 2)
printf("2's complement, big endian\n");
else
printf("<unknown: %02hx>", header[5]);
printf("  %-35s", "Version:");
printf("%d", header[6]);
if (header[6] == EV_CURRENT)
printf(" (current)\n");
else
printf("\n");
}
/**
 * print_osabi - Prints value of OS/ABI.
 * @header: Information in header.
*/
void print_osabi(char *header)
{
printf("  %-35s", "OS/ABI:");
switch (header[7])
{
case 0:
printf("UNIX - System V\n");
break;
case 1:
printf("UNIX - HP-UX\n");
break;
case 2:
printf("UNIX - NetBSD\n");
break;
case 3:
printf("UNIX - Linux\n");
break;
case 6:
printf("UNIX - Solaris\n");
break;
case 7:
printf("UNIX - AIX\n");
break;
case 8:
printf("UNIX - IRIX\n");
break;
case 9:
printf("UNIX - FreeBSD\n");
break;
case 10:
printf("UNIX - TRU64\n");
break;
case 11:
printf("UNIX - Novell Modesto\n");
break;
case 12:
printf("UNIX - OpenBSD\n");
break;
default:
printf("<unknown: %02x>\n", header[7]);
}
printf("  %-35s%d\n", "ABI Version:", header[8]);
}
/**
* print_type - Prints value of type.
* @header: Information in header.
*/
void print_type(char *header)
{
int b;

if (header[5] == 1)
b = 16;
else if (header[5] == 2)
b = 17;
printf("  %-35s", "Type:");
switch (header[b])
{
case 0:
printf("NONE (None)\n");
break;
case 1:
printf("REL (Relocatable file)\n");
break;
case 2:
printf("EXEC (Executable file)\n");
break;
case 3:
printf("DYN (Shared object file)\n");
break;
case 4:
printf("CORE (Core file)\n");
break;
default:
if (b == 16)
{
printf("<unknown>: %02x\n", header[16]);
}
else
{
printf("<unknown>: %02x%02x\n",
header[16], header[17]);
}
}
}

/**
* print_entry - Prints value of entry address.
* @header: Information in header.
*/
void print_entry(char *header)
{
int s, f;

printf("  %-35s0x", "Entry point address:");
if (header[4] == 1 || header[4] == 0)
s = 27;
else
s = 31;
f = s;
if (header[5] != 2)
{
while (header[s] == 0 && s > 24)
s--;
printf("%x", header[s--]);
while (s >= 24)
printf("%02x", (unsigned char) header[s--]);
}
else
{
s = 24;
while (header[s] == 0)
s++;
printf("%x", header[s++]);
while (s <= f)
printf("%02x", (unsigned char) header[s++]);
}
printf("\n");
}
/**
 * main - Entry func.
 * @argc: Argument count
 * @argv: Argument vector
 * Return: 0 on success.
*/
int main(int argc, char *argv[])
{
int elf_filname, elf_header, leng = 64;
char *header;

if (argc != 2)
{
dprintf(STDERR_FILENO, "ERR: Too many args.\n"), exit(98); }
elf_filname = open(argv[1], O_RDONLY);
if (elf_filname == -1)
{
dprintf(STDERR_FILENO, "ERR: Can't open file %s\n",
argv[1]), exit(98); }
header = malloc(sizeof(char) * leng);
if (header == NULL)
{
close(elf_filname);
dprintf(STDERR_FILENO, "ERR: Malloc\n"), exit(98); }
elf_header = read(elf_filname, header, leng);
if (elf_header == -1)
{
free(header);
close(elf_filname);
dprintf(STDERR_FILENO, "ERROR: Can't read from file %s\n",
argv[1]), exit(98); }
if (header[0] != 0x7f || header[1] != 'E'
|| header[2] != 'L' || header[3] != 'F')
{
dprintf(STDERR_FILENO, "ERROR: File %s is not an ELF\n",
argv[1]), exit(98); }

printf("ELF Header:\n");
print_Magic(header);
print_osabi(header);
print_type(header);
print_entry(header);
free(header);
close(elf_filname);
return (0);
}

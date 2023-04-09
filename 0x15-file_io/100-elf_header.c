#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <elf.h>

#define BUF_SIZE 128

void check_elf(unsigned char *magic)
void print_magic(unsigned char *magic);
void print_class(unsigned char class);
void print_data(unsigned char data);
void print_version(unsigned char version);
void print_abiversion(unsigned char abiversion);
void print_osabi(unsigned char osabi);
void print_type(unsigned int type, unsigned char *e_ident);
void print_entry(unsigned long int entry, unsigned char *e_ident);
void close_elf(int elf);

/**
 * check_elf - Check if ELF file
 * Description - If not ELF file, exit the program with a status code of 98
 * @magic: Pointer to an array containing the ELF magic numbers
 *
 */
void check_elf(unsigned char *magic)
{
	int i;

	for (i = 0; i < 4; i++)
	{
		if (magic[i] != 127 &&
		    magic[i] != 'E' &&
		    magic[i] != 'L' &&
		    magic[i] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * print_magic - Prints the magic number from the ELF header
 * @magic: Pointer to an array containing the ELF magic numbers
 *
 * Description: Numbers separated by spaces
 */
void print_magic(unsigned char *magic)
{
	int i;

	printf("  Magic:   ");

	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x", magic[i]);

		if (i == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * print_class - Prints the class(32-bit or 64-bit) from the  ELF header
 * class: A variable of type unsigned char that contains the ELF class
 */
void print_class(unsigned char class)
{
	printf("  Class:                             ");

	switch (class)
	{
	case ELFCLASSNONE:
		printf("none\n");
		break;
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown: %d>\n", class);
	}
}

/**
 * print_data - Prints the byte order (little-endian or big-endian)
 * from the ELF header
 * @data: A byte that specifies the endianness of the data in the ELF class.
 */
void print_data(unsigned char data)
{
	printf("  Data:                              ");

	switch (data)
	{
	case ELFDATANONE:
		printf("none\n");
		break;
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown: %d>\n", data);
	}
}

/**
 * print_version - Prints the ELF header version
 * @version: A variable of type unsigned char that contains the ELF version
 */
void print_version(unsigned char version)
{
	printf("  Version:                           %d",
	       version);

	switch (version)
	{
	case EV_CURRENT:
		printf(" (current)\n");
		break;
	default:
		printf("\n");
		break;
	}
}

/**
 * print_osabi - Prints the operating system and ABI of the ELF header
 * @osabi: A variable of unsigned char type that contains the OS/ABI
 */
void print_osabi(unsigned char osabi)
{
	printf("  OS/ABI:                            ");

	switch (osabi)
	{
	case ELFOSABI_NONE:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_AIX:
		printf("UNIX - AIX\N");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	default:
		printf("<unknown: %d>\n", osabi);
	}
}

/**
 * print_abiversion - Prints the ABI version from the ELF header
 * @abiversion: A variable of unsigned char type that contains
 * the ELF ABI version
 */
void print_abiversion(unsigned char abiversion)
{
	printf("  ABI Version:                       %d\n",
	       abiversion);
}

/**
 * print_type - Print the type of the ELF header
 * @type: An integer that specifies the type of the ELF file
 * @e_ident: Pointer to an array that containing the ELF magic numbers
 * Description: A brief description of the type of the ELF file
 */
void print_type(unsigned int type, unsigned char *e_ident)
{
	printf("  Type:                              ");

	switch (type)
	{
	case ET_NONE:
		printf("NONE (Unknown type)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	default:
		if (e_ident[EI_OSABI] == ELFOSABI_ARM ||
				e_ident[EI_OSABI] == ELFOSABI_ARM_AEABI)
			printf("ARM");
		else
			printf("<unknown>: %d", type);
		break;
	}
}

/**
 * print_entry - Prints the entry point address of the ELF file
 * @entry: A long integer that specifies the entry point address
 * of the ELF file
 * @e_ident: Pointer to an array that contains the ELF class
 * Desc: The entry point address is printed in hexadecimal format
 */
void print_entry(unsigned long int entry, unsigned char *e_ident)
{
	printf("  Entry point address: 0x%lx\n", entry);
}

/**
 * close_elf - Closes the ELF file descriptor
 * @elf: An integer that specifies the file descriptor to be closed
 *
 */
void close_elf(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close fd %d\n");
		exit(98);
	}
}

/**
 * main - Entry point
 * @argc: An integer containing the number of arguments
 * passed to the program
 * @argv: An array of strings containing the arguments
 * passed to the program
 * Return: 0 on success, otherwise 1
 */

int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int o, r;

	o = open(argv[1], O_RDONLY);
	if (o == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		close_elf(o);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	r = read(o, header, sizeof(Elf64_Ehdr));
	if (r == -1)
	{
		free(header);
		close_elf(o);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	check_elf(magic);
	printf("ELF Header:\n");
	print_magic(magic);
	print_class(header.e_ident[EI_CLASS]);
	print_data(header.e_ident[EI_DATA]);
	print_version(header.e_ident[EI_VERSION]);
	print_abiversion(header.e_ident[EI_ABIVERSION]);
	print_osabi(header.e_ident[EI_OSABI]);
	print_type(header.type, header.e_ident);
	print_entry(heade.entry, header.e_ident);

	free(header);
	close_elf(o);
	return (0);
}

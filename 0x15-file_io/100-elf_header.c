#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

void PrintClass(unsigned char *e_ident);
void CheckElf(unsigned char *e_ident);
void PrintMagic(unsigned char *e_ident);
void PrintAbi(unsigned char *e_ident);
void PrintData(unsigned char *e_ident);
void PrintVersion(unsigned char *e_ident);
void PrintType(unsigned int type_elf, unsigned char *e_ident);
void PrintOsabi(unsigned char *e_ident);
void CloseElf(int elf);
void PrintEntry(unsigned long int entry_a, unsigned char *e_ident);

/**
 * CheckElf: Checks if a file is an ELF file.
 * @e_ident: A pointer to an array containing the ELF magic numbers.
 *
 * Description: If the file is not an ELF file - exit code is 98.
 */
void CheckElf(unsigned char *e_ident)
{
	int index;

	for (index = 0; index < 4; index++)
	{
		if (e_ident[index] != 127 &&
			e_ident[index] != 'E' &&
			e_ident[index] != 'L' &&
			e_ident[index] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: This is not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * PrintMagic - Prints the magic numbers of an ELF header.
 * @e_ident: A pointer to an array containing the ELF magic numbers.
 *
 * Description: Magic numbers are separated by spaces.
 */
void PrintMagic(unsigned char *e_ident)
{
	int index;

	printf("  Magic:   ");

	for (index = 0; index < EI_NIDENT; index++)
	{
		printf("%02x", e_ident[index]);

		if (index == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * PrintClass - Prints the class of an ELF header.
 * @e_ident: A pointer to an array containing the ELF class.
 */
void PrintClass(unsigned char *e_ident)
{
	printf("  Class:                             ");

	switch (e_ident[EI_CLASS])
	{
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASSNONE:
		printf("none\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * PrintData - Prints the data of an ELF header.
 * @e_ident: A pointer to an array containing the ELF class.
 */
void PrintData(unsigned char *e_ident)
{
	printf("  Data:                              ");

	switch (e_ident[EI_DATA])
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
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * PrintVersion - Prints the version of an ELF header.
 * @e_ident: A pointer to an array containing the ELF version.
 */
void PrintVersion(unsigned char *e_ident)
{
	printf("  Version:                           %d",
		   e_ident[EI_VERSION]);

	switch (e_ident[EI_VERSION])
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
 * PrintOsabi - Prints the OS/ABI of an ELF header.
 * @e_ident: A pointer to an array containing the ELF version.
 */
void PrintOsabi(unsigned char *e_ident)
{
	printf("  OS/ABI:                            ");

	switch (e_ident[EI_OSABI])
	{
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_NONE:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_OSABI]);
	}
}

/**
 * PrintAbi - Prints the ABI version of an ELF header.
 * @e_ident: A pointer to an array containing the ELF ABI version.
 */
void PrintAbi(unsigned char *e_ident)
{
	printf("  ABI Version:                       %d\n",
		   e_ident[EI_ABIVERSION]);
}

/**
 * PrintType - Prints the type of an ELF header.
 * @type_elf: The ELF type.
 * @e_ident: A pointer to an array containing the ELF class.
 */
void PrintType(unsigned int type_elf, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		type_elf >>= 8;

	printf("  Type:                              ");

	switch (type_elf)
	{
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_NONE:
		printf("NONE (None)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	default:
		printf("<unknown: %x>\n", type_elf);
	}
}

/**
 * PrintEntry - Prints the entry point of an ELF header.
 * @entry_a: The address of the ELF entry point.
 * @e_ident: A pointer to an array containing the ELF class.
 */
void PrintEntry(unsigned long int entry_a, unsigned char *e_ident)
{
	printf("  Entry point address:               ");

	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		entry_a = ((entry_a << 8) & 0xFF00FF00) |
				  ((entry_a >> 8) & 0xFF00FF);
		entry_a = (entry_a << 16) | (entry_a >> 16);
	}

	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)entry_a);

	else
		printf("%#lx\n", entry_a);
}

/**
 * CloseElf - Closes an ELF file.
 * @elf: The file descriptor of the ELF file.
 *
 * Description: If the file cannot be closed - exit code is 98.
 */
void CloseElf(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO,
				"Error: Can't close fd %d\n", elf);
		exit(98);
	}
}

/**
 * main - Displays the information contained in the
 *        ELF header
 * @args: The no. of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the file is not an ELF File or
 *              the function fails - exit code is 98.
 */
int main(int __attribute__((__unused__)) args, char *argv[])
{
	Elf64_Ehdr *header;
	int j, rid;

	j = open(argv[1], O_RDONLY);
	if (j == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't this read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		CloseElf(j);
		dprintf(STDERR_FILENO, "Error: Can't read this file %s\n", argv[1]);
		exit(98);
	}
	rid = read(j, header, sizeof(Elf64_Ehdr));
	if (rid == -1)
	{
		free(header);
		CloseElf(j);
		dprintf(STDERR_FILENO, "Error: `%s`: There is No such file\n", argv[1]);
		exit(98);
	}

	CheckElf(header->e_ident);
	printf("ELF Header:\n");
	PrintMagic(header->e_ident);
	PrintClass(header->e_ident);
	PrintData(header->e_ident);
	PrintVersion(header->e_ident);
	PrintOsabi(header->e_ident);
	PrintAbi(header->e_ident);
	PrintType(header->e_type, header->e_ident);
	PrintEntry(header->e_entry, header->e_ident);

	free(header);
	CloseElf(j);
	return (0);
}

#include "main.h"
#include <stdlib.h>
#include <stdio.h>

char *CreateBuf(char *file);
void Closefile(int wang);

/**
   * CreateBuf - Allocates 1024 bytes for a buf.
   * @file: The name of the file buf is storing chars for.
   * Return: A pointer to the created buf.
   */
char *
CreateBuf(char *file)
{
	char *buf;

	buf = malloc(sizeof(char) * 1024);

	if (buf == NULL)
	{
		dprintf(STDERR_FILENO,
				"Error: Can not write to %s\n", file);
		exit(99);
	}

	return (buf);
}

/**
 * Closefile - Closes file descriptors.
 * @wang: The file descriptor to be closed.
 */
void Closefile(int wang)
{
	int clz;

	clz = close(wang);

	if (clz == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can not close wang %d\n", wang);
		exit(100);
	}
}

/**
 * main - Copies the contents of one file to another.
 * @args: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 * Descript: If the argument count is incorrect: exit code 97.
 * If file_from does not exist or is unable to be read: exit code 98.
 * If file_to cannot be created: exit code 99.
 * If file_to or file_from can not be closed: exit code 100.
 * Return: 0 on success.
 */
int main(int args, char *argv[])
{
	int from, to, rid, ryt;
	char *buf;

	if (args != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buf = CreateBuf(argv[2]);
	from = open(argv[1], O_RDONLY);
	rid = read(from, buf, 1024);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (from == -1 || rid == -1)
		{
			dprintf(STDERR_FILENO,
					"Error: Can not read from file %s\n", argv[1]);
			free(buf);
			exit(98);
		}

		ryt = write(to, buf, rid);
		if (to == -1 || ryt == -1)
		{
			dprintf(STDERR_FILENO,
					"Error: Can not write to %s\n", argv[2]);
			free(buf);
			exit(99);
		}

		rid = read(from, buf, 1024);
		to = open(argv[2], O_WRONLY | O_APPEND);

	} while (rid > 0);

	free(buf);
	Closefile(from);
	Closefile(to);

	return (0);
}


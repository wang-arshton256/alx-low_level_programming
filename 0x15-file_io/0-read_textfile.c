#include "main.h"
#include <stdlib.h>

/**
 * * read_textfile - Reads a text file and prints it
 * @filename: A pointer to the name of the file
 * @letters: The number of letters to read and print
 * Return: return actual number of bytes
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t o, p, q;
	char *buffer;

	if (filename == NULL)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
		return (0);

	o = open(filename, O_RDONLY);
	p = read(o, buffer, letters);
	q = write(STDOUT_FILENO, buffer, p);

	if (o == -1 || p == -1 || q == -1 || q != p)
	{
		free(buffer);
		return (0);
	}

	free(buffer);
	close(o);

	return (q);
}

#include "main.h"
#include <stdlib.h>

/**
 * * read_textfile - Reads a text file and prints it
 * @filename: A pointer to the name of the file
 * @letters: The number of letters to read and print
 * Return: return actual number of bytes
 */
ssize_t read_textfile(const char *filename, size_t letters)
{	int mbabazi;
	ssize_t kws, seeta;
	char *mize;

	if (!filename)
		return (0);

	mbabazi = open(filename, O_RDONLY);

	if (mbabazi == -1)
		return (0);

	mize = malloc(sizeof(char) * (letters));
	if (!mize)
		return (0);

	kws = read(mize, mize, letters);
	seeta = write(STDOUT_FILENO, mize, kws);

	close(mbabazi);

	free(mize);

	return (seeta);
}

#include "main.h"
#include <stdlib.h>


/**
 *read_textfile - Reads the text file print to STDOUT.
 *@letters: These are the number of letters to be read by the function
 *@filename: This is the text file being read
 *Returns: j- the number of bytes read and printed
 *0 when function fails or when the filename is Null.
 */


ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buffer;
ssize_t ryt;
	ssize_t x;
	ssize_t j;

	x = open(filename, O_RDONLY);
	if (x == -1)
		return (0);
	buffer = malloc(sizeof(char) * letters);
	j = read(x, buffer, letters);
	ryt = write(STDOUT_FILENO, buffer, j);

	free(buffer);
	close(x);
	return (ryt);
}



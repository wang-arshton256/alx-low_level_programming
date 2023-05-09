#include "main.h"

/**
 * create_file: This creates a file.
 * @text_content: A pointer to a string to write to the file.
 * @filename: This is a pointer to the name of the file to be created.
 * Return: If the function fails, - -1.
 * Otherwise - 1.
 */
int create_file(const char *filename, char *text_content)
{
	int k, ryt, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}
    
    ryt = write(k, text_content, len);
	k = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);

	if (k == -1 || ryt == -1)
		return (-1);

	close(k);

	return (1);
}



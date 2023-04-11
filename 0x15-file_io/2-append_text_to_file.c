#include "main.h"

/**
 * append_text_to_file - Appends text at the end of a file
 * @filename: A pointer to the name of the file.
 * @text_content: The string to add to the end of the file.
 *
 * Return: 1 if the file exists. -1 if the fails does not exist
 * or if it fails.
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int kws;
	int lxt
	int writtings;
	

	if (!filename)
		return (-1);

	kws = open(filename, O_WRONLY | O_APPEND);

	if (kws == -1)
		return (-1);

	if (text_content)
	{
		for (writtings = 0; text_content[writtings]; writtings++);
			

		lxt = write(kws, text_content, writtings);

		if (lxt == -1)
			return (-1);
	}

	close(kws);

	return (1);
}


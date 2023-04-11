#include "main.h"

/**
 * create_file - creates a file
 * @filename: filename.
 * @text_content: content writed in the file.
 *
 * Return: 1 if it success. -1 if it fails.
 */
int create_file(const char *filename, char *text_content)
{
	int kws;
	int lxt
	int writtings;
	

	if (!filename)
		return (-1);

	kws = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);

	if (kws == -1)
		return (-1);

	if (!text_content)
		text_content = "";

	for (writtings = 0; text_content[writtings]; writtings++)
		;

	lxt = write(kws, text_content, writtings);

	if (lxt == -1)
		return (-1);

	close(kws);

	return (1);
}

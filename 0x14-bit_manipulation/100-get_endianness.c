#include "main.h"

/**
 * get_endianness - checks the endianness
 * Return: always return 0
 */

int get_endianness(void)
{
	unsigned int w;
	char *j;

	w = 1;
	j = (char *) &w;

	return ((int)*j);
}

#include "main.h"

/**
 * get_endianness - Checks the endianness
 *
 * Return: 0 if Big endian, 1 if little endian
 */

int get_endianness(void)
{
	unsigned int x;
	char *c;

	x = 1;
	c = (char *) &x;

	return ((int)*c);
}

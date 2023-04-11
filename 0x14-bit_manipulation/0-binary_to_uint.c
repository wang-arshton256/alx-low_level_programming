#include "main.h"
#include <stddef.h>

/**
 * binary_to_uint - Converts a binary number to unsigned int.
 * @b: a pointer to a string
 * Return: return converted number.
 */

unsigned int binary_to_uint(const char *b)
{unsigned int value = 0;
	 int w = 0;
	if (b == NULL)
	return (0);
	while (b[w] == '0' || b[w] == '1')
{value <<= 1;
	value += b[w] - '0';
	w++;
}
	return (value);
}

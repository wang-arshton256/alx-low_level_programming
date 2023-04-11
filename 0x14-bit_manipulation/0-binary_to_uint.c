#include "main.h"
#include <stddef.h>

/**
 * binary_to_uint - Converts a binary number to unsigned int.
 * @b: a pointer to a string
 * Return: return the converted number
 */


unsigned int binary_to_uint(const char *b)
{
	int wang;
	unsigned int result = 0;

	if (!b)
		return (0);

	for (wang = 0; b[wang]; wang++)
	{
		if (b[wang] < '0' || b[wang] > '1')
			return (0);
		result = 2 * result + (b[wang] - '0');
	}

	return (result);
}


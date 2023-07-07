#include "main.h"

/**
 * binary_to_uint - converts a binary number to an
 * unsigned int.
 * @b: binary.
 *
 * Return: unsigned int.
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int xl;
	int len, base__2;

	if (!b)
		return (0);

	xl = 0;

	for (len = 0; b[len] != '\0'; len++)
		;

	for (len--, base__2 = 1; len >= 0; len--, base__2 *= 2)
	{
		if (b[len] != '0' && b[len] != '1')
		{
			return (0);
		}

		if (b[len] & 1)
		{
			xl += base__2;
		}
	}

	return (xl);
}

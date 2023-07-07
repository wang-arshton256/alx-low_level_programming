#include "main.h"

/**
 * binary-to-uint : COnverts a binary number to unsigned int
 * @b: String Containing The binary number
 *
 * Return: the converted numb
 */
unsigned int binary_to_uint(const char *b)
{
	int w;
	unsigned int deci_val = 0;

	if (!b)
		return (0);

	for (w = 0; b[w]; w++)
	{
		if (b[w] < '0' || b[w] > '1')
			return (0);
		deci_val = 2 * deci_val + (b[w] - '0');
	}

	return (deci_val);
}


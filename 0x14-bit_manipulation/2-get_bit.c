#include "main.h"

/**
 * get_bit - Funtion gets the value of a bit in an index
 * @n: The bit
 * @index: The index to get the value.
 * Return: return value of bit
 */

int get_bit(unsigned long int n, unsigned int index)

{
	unsigned int wang;

	if (n == 0 && index < 64)
		return (0);

	for (wang = 0; wang <= 63; n >>= 1, wang++)
	{
		if (index == wang)
		{
			return (n & 1);
		}
	}

	return (-1);
}

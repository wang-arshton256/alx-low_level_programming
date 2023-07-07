#include "main.h"

/**
 * clear_bit:  Sets the value of a bit to 0.
 * at a given index.
 * @n: Pointer of an unsigned long int.
 * @index: Index of the bit.
 *
 * Return: 1 if it worked, -1 if it didn't.
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned int k;

	if (index > 63)
		return (-1);

	m = 1 << index;

	if (*n & k)
		*n ^= k;

	return (1);
}

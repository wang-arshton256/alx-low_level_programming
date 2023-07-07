#include "main.h"

/**
 * set_bit - Sets the value of a bit to 1.
 * at a given index.
 * @n: Pointer of an unsigned long int.
 * @index: index of the bit.
 *
 * Return: 1 if it worked, -1 if there is an error.
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned int k;

	if (index > 63)
		return (-1);

	k = 1 << index;
	*n = (*n | k);
	return (1);
}

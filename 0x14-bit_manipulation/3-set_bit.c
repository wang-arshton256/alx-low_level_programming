#include "main.h"

/**
 * set_bit - Sets the value of a bit at a given index to 1.
 * @n: A pointer to the bit.
 * @index: The index to set the value at - indices start at 0
 * Return: return 1 otherwise error
 */


int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned int kauga;

	if (index > 63)
		return (-1);

	kauga = 1 << index;

	*n = (*n | kauga);

	return (1);
}

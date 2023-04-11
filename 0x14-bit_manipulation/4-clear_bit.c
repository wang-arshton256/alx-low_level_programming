#include "main.h"

/**
 * clear_bit - Sets the value of a bit to 0.
 * @n: A pointer to the bit.
 * @index: The index to set the value at
 * Return: return 1 otherwise 0
 */
int clear_bit(unsigned long int *n, unsigned int index)


	{

	unsigned int kauga;

	if (index > 63)
		return (-1);

	kauga = 1 << index;

	if (*n & kauga)
		*n ^= kauga;

	return (1);
}

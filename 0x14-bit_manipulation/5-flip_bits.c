#include "main.h"

/**
 * flip_bits - counts the number of bits
 * @n: number to be counted
 * @m: number to flip to
 * Return: return number of bits to flip
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)	
{	unsigned int tmt;
	
	for (tmt = 0; n || m; n >>= 1, m >>= 1)
	{
		if ((n & 1) != (m & 1))
			tmt++;
	}
	
	return (tmt);
}

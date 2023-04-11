#include "main.h"
#include <stddef.h>

/**
 * binary_to_uint - Converts a binary number to unsigned int.
 * @bin: a pointer to a string
 * Return: return converted no.
 */

unsigned int binary_to_uint(const char *bin)
{unsigned int value = 0;
	 int wang = 0;
	if (bin == NULL)
	return (0);
	while (bin[wang] == '0' || bin[wang] == '1')
{value <<= 1;
	value += bin[wang] - '0';
	wang++;
}
	return (value);
}

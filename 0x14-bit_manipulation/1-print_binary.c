#include "main.h"

/**
 * print_binary - prints binary rep of a number
 * @wang: number to be printed
 */
void print_binary(unsigned long int wang)

{
	if (wang > 1)
		print_binary(wang >> 1);

	_putchar((wang & 1) + '0');
}

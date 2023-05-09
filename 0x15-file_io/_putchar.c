#include <unistd.h>

/**
 * _putchar - writes the character c to the stdout
 * @c: The character to print
 *
 * Return:  1 On success.
 * If error, -1 is returned and error no. is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

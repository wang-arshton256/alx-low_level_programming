#include "main.h"
#include <stdio.h>

/**
 * @file: file reading from.
 * @file_storing_to: File storing char.
 * @argv: arguments declarations
 * Return: does not return any value.
 */
void error_file(int reading_from_file, int file_storing_to, char *arg[])
{
	if (reading_from_file == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", arg[1]);
		exit(98);
	}
	if (file_storing_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", arg[2]);
		exit(99);
	}
}

/**
 * main - Checks file content
 * @argc: number of arguments declared.
 * @arg: arguments declarations.
 * Return: returns 0.
 */
int main(int argc, char *arg[])
{
	int reading_from_file, file_storing_to, err_close;
	ssize_t no_chars, kla;
	char buffer[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "%s\n", "Usage: cp reading_from_file file_storing_to");
		exit(97);
	}

	reading_from_file = open(arg[1], O_RDONLY);
	file_storing_to = open(arg[2], O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0664);
	error_file(reading_from_file, file_storing_to, arg);

	no_chars = 1024;
	while (no_chars == 1024)
	{
		no_chars = read(reading_from_file, buffer, 1024);
		if (no_chars == -1)
			error_file(-1, 0, arg);
		kla = write(file_storing_to, buffer, no_chars);
		if (kla == -1)
			error_file(0, -1, arg);
	}

	err_close = close(reading_from_file);
	if (err_close == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", reading_from_file);
		exit(100);
	}

	err_close = close(file_storing_to);
	if (err_close == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", reading_from_file);
		exit(100);
	}
	return (0);
}

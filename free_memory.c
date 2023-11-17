#include "shell.h"

/**
 * free_memory - frees allocated memory.
 * @input: user input
 * @argv: array of pointers to strings
 *
 * Return: void
 */

void free_memory(char *input, char **argv)
{
	if (input != NULL)
		free(input);

	if (argv != NULL)
		free(argv);
}

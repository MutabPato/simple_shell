#include "shell.h"

/**
 * free_memory - frees allocated memory.
 * @input - command line argument
 * @argv - array of ppp
 *
 * Return: void
 */

void free_memory(char *input, char **argv)
{
	int i;

	if (input != NULL)
		free(input);

	if (argv != NULL)
	{
		for (i = 0; argv[i] != NULL; i++)
			free(argv[i]);
	}
	free(argv);
}

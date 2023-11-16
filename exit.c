#include "shell.h"

/**
 * is_exit - causes normal process termination
 * @argv: array of pointers to strings
 * @input: user input
 *
 * Return: nothing.
 */

void is_exit(char **argv, char *input)
{
	if (argv == NULL || argv[0] == NULL || *argv[0] == '\0')
		return;
	if ((strcmp(argv[0], "exit") == 0))
	{
		free_memory(input, argv);
		exit(0);
	}
}

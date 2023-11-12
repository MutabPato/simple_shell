#include "shell.h"

/**
 * is_env - prints the current environment
 * @argv: input
 *
 * Return: nothing.
 */

void is_env(char **argv)
{
	int i;

	if ((strcmp(argv[0], "env") == 0))
	{
		i = 0;
		while (environ[i])
			printf("%s\n", environ[i++]);
	}
}

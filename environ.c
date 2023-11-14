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

	if (argv == NULL || argv[0] == NULL || *argv[0] == '\0')
		return;

	if ((strcmp(argv[0], "env") == 0))
	{
		i = 0;
		while (environ[i])
			printf("%s\n", environ[i++]);
	}
}

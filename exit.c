#include "shell.h"

/**
 * is_exit - causes normal process termination
 * @argv: input
 *
 * Return: nothing.
 */

void is_exit(char **argv)
{
	if ((strcmp(argv[0], "exit") == 0))
	{
		printf("exit\n\n\nDisconnected\n");
		exit(0);
	}
}

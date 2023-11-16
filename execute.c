#include "shell.h"

/**
 * exec_ve - executes the command
 * @argv: array of arguments
 */

void exec_ve(char **argv)
{
	if ((execve(argv[0], argv, NULL) == -1))
	{
		free_memory(NULL, argv);
		exit(-1);
	}
}

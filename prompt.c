#include "shell.h"

/**
 * display_prompt - displays the shell prompt.
 *
 * Return: void
 */

void display_prompt(void)
{
	if (isatty(STDIN_FILENO))
		printf("($)");
	fflush(stdout);
}

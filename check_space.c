#include "shell.h"

/**
 * is_all_spaces - checks if the input consists only of spaces.
 * @input: user input
 * @read: no. of characters read from the input string.
 *
 * Return: true if all chars. in the input string are spaces;
 * false if at least one non-space character is found.
 */

bool is_all_spaces(char *input, ssize_t read)
{
	int i;

	for (i = 0; i < read - 1; i++)
	{
		if (input[i] != ' ')
			return (false);
	}
	return (true);
}

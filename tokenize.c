#include "shell.h"

/**
 * tokenize - tokenizes the input
 * @input: string read from stdin
 *
 * Return: array of argumrnts.
 */

char **tokenize(char *input)
{
	const char delim[] = " ";
	char *token;
	int  i = 0;
	char **argv = NULL;

	argv = (char **)malloc(sizeof(char *) * strlen(input) + 1);
	if (argv == NULL)
		return (NULL);
	token = str_tok(input, delim);
	while (token != NULL)
	{
		argv[i] = strdup(token);
		token = str_tok(NULL, delim);
		i++;
	}
	free(token);
	argv[i] = NULL;

	return (argv);
}

#include "shell.h"

/**
 * tokenize - tokenizes the input
 *
 * @input: string read from stdin
 * Return: array of argumrnts.
 */
char **tokenize(char *input)
{
	const char delim[] = " ";
	char *token;
	int  i = 0;
	char **argv = NULL;

	argv = (char **)malloc(sizeof(char *) * 20);
	if (argv == NULL)
		return (NULL);
	token = strtok(input, delim);
	while (token != NULL)
	{
		argv[i] = strdup(token);
		token = strtok(NULL, delim);
		i++;
	}
	argv[i] = NULL;
	
	is_exit(argv);

	return (argv);

	for (i = 0; i < 20; i++)
	{
		if (argv[i] != NULL)
			free(argv[i]);
	}
}

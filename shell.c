#include "shell.h"

/**
 * main - unix command line interpreter
 *
 * Return: void.
 */

int main(void)
{
	ssize_t read;
	char *input = NULL, **argv = NULL, *path;
	size_t len = 0;
	pid_t pid;

	while (1)
	{
		display_prompt();
		read = getline(&input, &len, stdin);
		if (read > 1)
		{
			input[read - 1] = '\0';
			argv = tokenize(input);
			is_exit(argv);
			is_env(argv);
			path = get_path(argv);
			if (path != NULL)
				argv[0] = path;
			else
				perror("Error: ");
			pid = fork();
			if (pid == -1)
				exit(-1);
			else if (pid == 0)
				exec_ve(argv);
			else
				wait(NULL);

			free_memory(NULL, argv);
		}
		else if (read == -1 || read == 0)
			break;
	}
	free_memory(input, NULL);
	return (0);
}
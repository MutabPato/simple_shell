#include "shell.h"

/**
 * main - unix command line interpreter
 *
 * Return: void.
 */

int main(void)
{
	ssize_t read;
	char *input = NULL, **argv = NULL;
	size_t len = 0;
	pid_t pid;

	while (1)
	{
		printf("($): ");
		read = getline(&input, &len, stdin);
		if (read != -1)
		{
			input[read - 1] = '\0';
			argv = tokenize(input);
			argv[0] = get_path(argv);

			pid = fork();
			if (pid == -1)
				printf("Fork failed\n");

			else if (pid == 0)
				exec_ve(argv);

			else
				wait(NULL);
		}
		else
			printf("Error reading input\n");

	}
	free(input);
	return (0);
}

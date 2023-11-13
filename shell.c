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
		fflush(stdout);
		read = getline(&input, &len, stdin);
		
		if (read == -1)
		{
			printf("Error reading input\n");
			continue;
		}
		if (read == 0)
			continue;
		
		else
		{
			input[read - 1] = '\0';
			argv = tokenize(input);
			is_exit(argv);
			is_env(argv);
			argv[0] = get_path(argv);

			pid = fork();
			if (pid == -1)
				printf("Fork failed\n");

			else if (pid == 0)
				exec_ve(argv);

			else
			{
				wait(NULL);
				return (-1);
			}
		}

	}
	free(input);
	return (0);
}

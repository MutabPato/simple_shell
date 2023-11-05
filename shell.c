#include "shell.h"

/**
 * main - unix command line interpreter
 *
 * Return: void.
 */

int main(void)
{
	char *input = NULL;
	size_t len = 0;
	ssize_t read;
	char *argv[20];
	pid_t pid;
	char *token;
	char *delim = " ";
	int i = 0;

	while (1)
	{
		printf("($) ");
		read = getline(&input, &len, stdin);
		
		if (input == NULL)
			printf("error\n");

		if (read != -1)
		{
			input[strcspn(input, "\n")] = '\0';
			token = strtok(input, delim);

 			while (token != NULL)
 			{
			argv[i] = token;
 			token = strtok(NULL, delim);
			i++;
			}
			argv[i] = NULL;

			pid = fork();
			if (pid == -1)
				printf("error\n");

			if (pid == 0)
			{
				if ((execve(argv[0], argv, NULL) == -1))
					printf("error\n");
			}
			else
				wait(NULL);
		}

		else
			printf("error\n");

	}
	free(input);

	return (0);
}

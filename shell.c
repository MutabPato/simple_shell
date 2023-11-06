#include "shell.h"
/**
 * exec_ve - executes the command
 * @argv: array of arguments
 */

void exec_ve(char *argv[])
{
	if ((execve(argv[0], argv, NULL) == -1))
		printf("No such file or directory\n");
}

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
	char *argv[20];

	token = strtok(input, delim);
	while (token != NULL)
	{
		argv[i] = token;
		token = strtok(NULL, delim);
		i++;
	}
	argv[i] = NULL;
	return (argv);
}
/**
 * main - unix command line interpreter
 *
 * Return: void.
 */

int main(void)
{
	ssize_t read;
	char *input = NULL, *argv[20];
	size_t len = 0;
	pid_t pid;

	while (1)
	{
		printf("($): ");
		read = getline(&input, &len, stdin);
		if (read != 1)
		{
			input[read - 1] = '\0';
			argv[20] = tokenize(input);

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

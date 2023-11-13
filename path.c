#include "shell.h"

/**
 * get_path - gets the full path of the given command.
 *@argv: the commad inputed.
 *
 * Return: return path.
 */

char *get_path(char **argv)
{
	char *paths, *paths_copy, *token, *path_name;
	int argv_len, path_len;
	struct stat st;

	if (stat(argv[0], &st) == 0)
		return (argv[0]);

	else
	{
		paths = getenv("PATH");
		if (paths)
		{
			paths_copy = strdup(paths);
			token = strtok(paths_copy, ":");
			argv_len = strlen(argv[0]);
			while (token)
			{
				path_len = strlen(token);
				path_name = malloc(argv_len + path_len + 2);
				strcpy(path_name, token);
				strcat(path_name, "/");
				strcat(path_name, argv[0]);
				strcat(path_name, "\0");

				if (stat(path_name, &st) == 0)
				{
					free(paths_copy);
					return (path_name);
				}
				else
				{
					free(path_name);
					token = strtok(NULL, ":");
				}

			}
			free(paths_copy);
		}
	}
	return (NULL);
}
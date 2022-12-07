#include "sshell.h"

/**
 * user_console - launches user console for input
 * Return: array of tokens
 */

char **user_console(void)
{
	size_t bufsize = 32;
	int i = 0, input, status;
	char *tok, *buffer = NULL;
	pid_t childcheck;

	while (1)
	{
		i = 0;
		if (isatty(STDIN_FILENO))
			printf("($) ");
		input = getline(&buffer, &bufsize, stdin);
		tok = strtok(buffer, " \n");
		split[i++] = tok;
		if (input == EOF)
		{
			if (isatty(STDIN_FILENO))
				printf("\n");
			free(buffer);
			return (NULL);
		}
		while (tok != NULL && i < 32)
		{
			tok = strtok(NULL, " \n");
			split[i++] = tok;
		}
		split[i - 1] = NULL;
		childcheck = fork();
		if (childcheck == 0)
		{
			execve(split[0], split, NULL);
		}
		wait(&status);
		free(buffer);
		buffer = NULL;
	}
	return (split);
}

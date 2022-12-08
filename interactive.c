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
	pid_t childcheck = 1;

	while (1)
	{
		i = 0;
		if (buffer == NULL)
			printf("($) ");
		input = getline(&buffer, &bufsize, stdin);
		if (EOF)
		{
			if (isatty(STDIN_FILENO) != 0)
			{
				printf("\n");
				free(buffer);
				exit(0);
			}
		}
		tok = strtok(buffer, " \n");
		split[i++] = tok;
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
			exit(0);
		}
		wait(&status);
		free(buffer);
		buffer = NULL;
	}
	return (split);
}

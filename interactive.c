#include "sshell.h"

/**
 * user_console - launches user console for input
 * Return: array of tokens
 */

char **user_console(void)
{
	size_t bufsize = 32;
	int i = 0, input;
	char *tok, *buffer = NULL;

	while (1)
	{
		if (isatty(0))
			printf("($) ");
		input = getline(&buffer, &bufsize, stdin);
		tok = strtok(buffer, " \n");
		split[i++] = tok;
		if (input == EOF)
		{
			if (isatty(0))
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
	}
	return (split);
}

#include "sshell.h"
/**
 * main - Shell, interactive or non interactive
 * @argc: argument count
 * @argv: argument vector
 * Return: 1 if command fails
 */

int main(int argc, char **argv)
{
	size_t bufsize = 32;
	int i = 0, status;
	pid_t childcheck;
	char *tok, *buffer = NULL;

	if (argc == 1 && argv != NULL)
	{
		while (1)
		{
			i = 0;
			printf("($) ");

			getline(&buffer, &bufsize, stdin);
			tok = strtok(buffer, " \n");
			if (tok == NULL)
			{
				printf("failed to read command");
				return (1);
			}
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
			}
			wait(&status);
			free(buffer);
			buffer = NULL;
		}
	}
	return (0);
}

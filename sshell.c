#include "sshell.h"

/**
 *
 *
 *
 *
 */

int main(int argc, char **argv)
{
	char *buffer = NULL;
	size_t bufsize = 32;
	int input;
	pid_t childcheck;
	char *split[32];
	int status, i = 0;
	char *tok;


	if (argc == 1)
		// check for interactive mode
	{
		while (1)
		{
			// enter "infinite" interactive loop
			i = 0;
			printf("($) ");

			// get user commands

			input = getline(&buffer, &bufsize, stdin);


			//printf("passed getline %d\n", input);

			// double check how to hanadle \n

			tok = strtok(buffer, " \n");
			if (tok == NULL)
			{
				printf("failed to read command");
				return (1);
			}
			split[i++] = tok;

			// tokenize input and store it in an array

			while (tok != NULL && i < 32)
			{
				tok = strtok(NULL, " \n");
				split[i++] = tok;

			}

			split[i - 1] = NULL;


			// check if process is parent or child
			childcheck = fork();

			if (childcheck == 0)
			{
				// executes program called by user

				execve(split[0], split, NULL);
			}

			wait(&status);
			free(buffer);
			buffer = NULL;
		}
	}
	return (0);
}

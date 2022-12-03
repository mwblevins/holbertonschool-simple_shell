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
			
			printf("($) ");

			// get user commands

			input = getline(&buffer, &bufsize, stdin);

			// fork process
			printf("passed getline %d\n", input);

			//childcheck = fork();

			// double check how to hanadle \n

			tok = strtok(buffer, " \n");
			printf("pulled the first token %s\n", tok);
			if (tok == NULL)
			{
				printf("failed to read command");
				return (1);
			}
			split[i++] = tok;

			// tokenize input and store it in an array

			while (tok != NULL)
			{
				printf("%s\n", tok);
				tok = strtok(NULL, " \n");
				printf("%s\n", split[i]);
				split[i++] = tok;

			}

			// check if process is parent or child
			childcheck = fork();

			if (childcheck == 0)
				// executes program called by user
			       	execve(split[0], split, NULL);

			wait(&status);
		}
	}
	return (0);
}

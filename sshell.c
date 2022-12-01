#include "sshell.h"

/**
 *
 *
 *
 *
 */

int main(int argc, char *argv)
{
	char *buffer;
	size_t bufsize = 32;
	size_t input;
	pid_t childcheck;
	char split[32];
	int status;
	char *tok;

	if (argc == 1)
	{
		while (1)
		{
			buffer = (char *)malloc(bufsize * sizeof(char));
			printf("($) ");
			input = getline(&buffer, &bufsize, stdin);
			childcheck = (fork);
			tok = strtok(input, " ");
			while (tok != NULL)
			{
				split[i++] = tok;
				tok = strtok(NULL, " ");
			}
			if (childcheck == 0)
			       	execve(input, split, NULL);
			wait(&status);
		}
	}
}

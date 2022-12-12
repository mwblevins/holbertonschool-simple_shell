#include "sshell.h"

/**
 * user_console - launches user console for input
 * Return: array of tokens
 */

char **user_console(char **envp)
{
	int input = 0, status;
	char **temp = NULL;
	pid_t childcheck = 1;


	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("($) ");
		temp = tokenize();
		if (temp == NULL)
			continue;
		temp = pathfinder(split[0]);
		if (split[0] != NULL)
		{
			childcheck = fork();
			if (childcheck == 0)
			{
				printf("string being passed to execve is %s\n", split[0]);
				execve(split[0], split, envp);
				printf("./shell: No such file or directory");
				exit(0);
			}
			wait(&status);
		}
	}
	return (split);
}

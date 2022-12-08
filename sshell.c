#include "sshell.h"
/**
 * main - Shell, interactive or non interactive
 * @argc: argument count
 * @argv: argument vector
 * Return: 1 if command fails
 */

int main(int argc, char **argv)
{
	int i = 0;
	char **args = NULL;

	if (argc == 1)
	{
		user_console();
	}
	if (argc > 1)
	{
		args = malloc(argc * sizeof(char *));
		while (i < (argc - 1))
		{
			args[i] = argv[i + 1];
			i++;
		}

		execve(args[0], args, NULL);
		printf("./shell: No such file or directory\n");
	}
	return (0);
}

#include "sshell.h"
/**
 * main - Shell, interactive or non interactive
 * @argc: argument count
 * @argv: argument vector
 * Return: 1 if command fails
 */

int main(int argc, char **argv)
{
	int status;
	pid_t childcheck;

	if (argc == 1)
	{
		user_console();
	}
	return (0);
}

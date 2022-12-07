#include "sshell.h"
/**
 * main - Shell, interactive or non interactive
 * @argc: argument count
 * @argv: argument vector
 * Return: 1 if command fails
 */

int main(int argc, char **argv)
{

	if (argc == 1 && argv)
	{
		user_console();
	}
	return (0);
}

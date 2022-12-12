#include "sshell.h"

/**
 * pathfinder - finds the correct path for given alias
 * @command: given input to check for path
 * Return: pointer to the string array or NULL if failed
 */

char **pathfinder(char *command)


{
	char *current_path, *fullpath, *temp_path;
	char *path_tok;
	size_t arglen = strlen(command);

	if (strchr(command, '/') != NULL && access(command, F_OK) == 0)
	{
		split[0] = command;
		return (split);
	}

	current_path = getenv("PATH");
	temp_path = strdup(current_path);
	path_tok = strtok(temp_path, ":");
	while (path_tok)
	{
		fullpath = malloc(arglen + strlen(path_tok) + 2);
		sprintf(fullpath, "%s/%s", path_tok, command);
		if (access(fullpath, F_OK) == 0)
		{
			split[0] = fullpath;
			return (split);
		}
		path_tok = strtok(NULL, ":");
		free(fullpath);
	}
	printf("./shell: No such file or directory\n");
	return (NULL);
}

#include "sshell.h"

/**
 *
 *
 */

char *pathfinder(char *command)


{
	char *current_path, *fullpath;
	char *path_tok;
	size_t arglen = strlen(command);

	if (strchr(command, '/') != NULL && access(command, F_OK) == 0)
	{
		return (command);
	}

	current_path = getenv("PATH");
	path_tok = strtok(current_path, ":");
	while (path_tok)
	{
		fullpath = malloc(arglen + strlen(path_tok) + 2);
		sprintf(fullpath, "%s/%s", path_tok, command);
		if (access(fullpath, F_OK) == 0)
		{
			return (fullpath);
		}
		path_tok = strtok(NULL, ":");
		free(fullpath);
	}
	printf("./shell: No such file or directory\n");
	return (NULL);
}

#include "sshell.h"

/**
 *
 *
 */

char **pathfinder(char *command)


{
	char *current_path, *fullpath, *temp_path;
	char *path_tok;
	size_t arglen = strlen(command);

	printf("in pathfinder\n");

	if (strchr(command, '/') != NULL && access(command, F_OK) == 0)
	{
		split[0] = command;
		return (split);
	}

	current_path = getenv("PATH");
	temp_path = strdup(current_path);
	printf("call to getenv is %s", current_path);
	path_tok = strtok(temp_path, ":");
	printf("got the first path token %s\n", path_tok);
	while (path_tok)
	{
		fullpath = malloc(arglen + strlen(path_tok) + 2);
		sprintf(fullpath, "%s/%s", path_tok, command);
		printf("concatneated string is %s\n", fullpath);
		if (access(fullpath, F_OK) == 0)
		{
			split[0] = fullpath;
			printf("new command is %s\n", split[0]);
			return (split);
		}
		path_tok = strtok(NULL, ":");
		free(fullpath);
	}
	printf("./shell: No such file or directory\n");
	return (NULL);
}

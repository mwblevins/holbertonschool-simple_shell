#include "sshell.h"



char **tokenize()
{
	char *tok = NULL, *buffer = NULL;
	int i, input = 0;
	size_t bufsize = 32;

	i = 0;

	input = getline(&buffer, &bufsize, stdin);
	printf("got buffer %s\n", buffer);
	if (input == EOF)
	{
		if (isatty(STDIN_FILENO) != 0)
			printf("\n");
		free (buffer);
		exit(0);
	}
	tok = strtok(buffer, " \n");
	printf("first token pulled %s\n", tok);
	if (tok == NULL)
		return (NULL);
	if (strcmp(tok, "exit") == 0)
	{
		free(tok);
		free(buffer);
		exit(0);
	}
	split[i++] = tok;
	printf("saved first token %s\n", split[i - 1]);
	while (tok != NULL && i < 32)
	{
		tok = strtok(NULL, " \n");
		printf("pulled second token %s\n", tok);
		split[i++] = tok;
		printf("stored second token %s\n", split[1]);
	}
	split[i - 1] = NULL;
	printf("split is %s\n", split[0]);
	return (split);
}

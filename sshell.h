#ifndef SSHELL_H
#define SSHELL_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>
char *fullpath;
char *buffer;
char *split[32];
char **env;
int print_env();
char **tokenize();
char **user_console(char **envp);
char **pathfinder(char *command);
#endif

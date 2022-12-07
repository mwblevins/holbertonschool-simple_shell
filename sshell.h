#ifndef SSHELL_H
#define SSHELL_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>
char *split[32];
char **user_console(void);
int main(int argc, char **argv);
#endif

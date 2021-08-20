#ifndef _SHELL_H
#define _SHELL_H

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stddef.h>
#include <errno.h>

char * my_strtok(char *buffer, const char *delimiter);

#endif
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
#include <signal.h>

/**
 * struct variables - structure for the management of input information
 * @buffer: stores input string
 * @argv: store arg from shell
 * @environ: store env data
 * @command: store inputs whit ";"
 * @commandsAv: store comand identificate
 */

typedef struct variables
{
	char *buffer;
	char **argv;
	char **environ;
	char **command;
	char **commandsAv;
} vars_f;

/**
 * struct funcs - matches command to appropriate builtin function
 * @name: string of function name
 * @f: function pointer to respective command
 */

typedef struct funcs
{
	char *name;
	char (*f)(vars_f *);
} funcs_t;

void path_(vars_f *vars);
void print_error(vars_f *vars, char *msg);
int _strcmp(char *s1, char *s2);
char *_strcat(char *s1, char *s2);
char *_strdup(char *s1);
unsigned int _strlen(char *str);
void _puts(char *str);
char (*get_struc(vars_f *vars)) (vars_f *vars);
char func_exit(vars_f *vars);
char func_env(vars_f *vars);
char **make_env(char **env2);
void free_env(char **env);
void path_exec_dir(vars_f *vars);
int check_for_dir(char *str);
char *f_paht(char **env);
char **tokenizer(char *buffer, char *delimiter);
char **NewRealloc(char **cat, size_t *size);
void path_concat(vars_f *vars, char *str2);

#endif

#include "shell.h"

/**
 * path_exec_dir - function to execute the directory macth whit PATH
 * @vars: structure variable required
 * Return: no return
 */

void path_exec_dir(vars_f *vars)
{
	if (access(vars->commandsAv[0], F_OK) == 0)
	{
		pid_t son = fork();
		int def;

		switch (son)
		{
			case 0:
			execve(vars->commandsAv[0], vars->commandsAv, vars->environ);
			break;

			case -1:
			_puts("Fail child process");
			break;

			default:
			wait(&def);
		}
	}
}

/**
 * check_for_dir - function to finds if the input is a directory
 * @str: first string del inpput command
 * Return: 0
 */

int check_for_dir(char *str)
{
	unsigned int i;

	for (i = 0; str[i]; i++)
	{
		if (str[i] == '/')
			return (1);
	}
	return (0);
}

/**
 * f_paht - function that extracts the information from the PATH
 * @env: data from de env
 * Return: data of Path
 */

char *f_paht(char **env)
{
	char *path = "PATH=";
	size_t iter1, iter2;

	for (iter1 = 0; env[iter1]; iter1++)
	{
		for (iter2 = 0; iter2 < 5; iter2++)
		{
			if (path[iter2] != env[iter1][iter2])
				break;
		}
		if (iter2 == 5)
			break;
	}
	return (env[iter1]);
}

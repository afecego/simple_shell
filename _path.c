#include "shell.h"

/**
 * path_ - function to finds the val of PATH env
 * @vars: structure variable required
 * Return: no return
 */

void path_(vars_f *vars)
{
	int iter, iter2 = 0, compar;
	char *copy, *path, *str1, *str2, **strsend;

	if (check_for_dir(vars->commandsAv[0]))
		path_exec_dir(vars);
	else
	{
		path = f_paht(vars->environ);
		if (path != NULL)
		{
			copy = _strdup(path);
			strsend = tokenizer(copy, "=:");
			while (strsend[iter2] != NULL)
			{
				str1 = _strcat(strsend[iter2], "/");
				str2 = _strcat(str1, vars->commandsAv[0]);

				if (access(str2, F_OK) == 0)
				{
					path_concat(vars, str2);
					break;
				}
				iter2++;
				free(str1);
				free(str2);
			}
		}
		if (path == NULL || strsend[iter2] == NULL)
		{
			print_error(vars, ": command not found\n");
		}
		free(copy);
		free(strsend);
	}
}

/**
 * print_error - function to print error message
 * @vars: structure variable required
 * @caract: defined error message
 * Return: no return
 */

void print_error(vars_f *vars, char *caract)
{
	_puts(vars->argv[0]);
	_puts(": ");
	_puts(vars->commandsAv[0]);
	_puts(caract);
}

/**
 * path_concat - function that execute comand since directory concatenated
 * @vars: structure variable required
 * @str2: directory concatenate
 * Return: no return
 */

void path_concat(vars_f *vars, char *str2)
{
	pid_t son = fork();
	int def;

	switch (son)
	{
		case 0:
		execve(str2, vars->commandsAv, vars->environ);
		break;

		case -1:
		_puts("Fail child process");
		break;

		default:
		wait(&def);
		break;
	}
}

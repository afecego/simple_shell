#include "shell.h"

/**
 * get_struc - matches command to appropriate builtin function
 * @vars: structure variable required
 * Return: result of function
 */

char (*get_struc(vars_f * vars)) (vars_f * vars)
{
	funcs_t funs[] = {
		{"env", func_env},
		{"exit", func_exit},
		{NULL, NULL}
	};
	int iter;

	for (iter = 0; funs[iter].f != NULL; iter++)
	{
		if (_strcmp(funs[iter].name, vars->commandsAv[0]) == 0)
			break;
	}
	if (funs[iter].f != NULL)
		funs[iter].f(vars);
	return (funs[iter].f);
}

/**
 * func_exit - function to exits program
 * @vars: structure variable required
 * Return: no return
 */

char func_exit(vars_f *vars)
{
	free_env(vars->environ);
	free(vars->command);
	free(vars->buffer);
	free(vars->commandsAv);
	exit(0);
}

/**
 * func_env - function to prints environment variable
 * @vars: structure variable required
 * Return: 0
 */

char func_env(vars_f *vars)
{
	unsigned int iter = 0;

	while (vars->environ[iter])
	{
		_puts(vars->environ[iter]);
		_puts("\n");
		iter++;
	}
	return (0);
}

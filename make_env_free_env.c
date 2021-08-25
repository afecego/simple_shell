#include "shell.h"

/**
 * make_env - matches command to appropriate builtin function
 * @env2: data of env for make the malloc
 * Return: NewEnv, memory space
 */

char **make_env(char **env2)
{
	char **NewEnv = NULL;
	int iter, num;

	for (iter = 0; env2[iter] != NULL; iter++)
		num++;

	NewEnv = malloc(sizeof(char *) * (iter + 1));
	if (NewEnv == NULL)
		exit(1);
	for (iter = 0; env2[iter] != NULL; iter++)
		NewEnv[iter] = _strdup(env2[iter]);
	NewEnv[iter] = NULL;
	return (NewEnv);
}

/**
 * free_env - function to free all allocated memory
 * @env: data from de env to be free
 * Return: no return
 */

void free_env(char **env)
{
	int iter = 0;

	for (; env[iter]; iter++)
		free(env[iter]);

	free(env);
}

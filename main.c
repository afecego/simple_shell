#include "shell.h"

/**
 * main - shell: prompt user for input. Interpret input as commands
 * @argc: arg count
 * @argv: arg vector
 * @environment: enviroment variables
 * Return: 0
 */

int main(int argc __attribute__((unused)), char **argv, char **environment)
{
	char *prompt = "$ ";
	size_t len_buffer = 0;
	unsigned int pipeline = 0, iter;
	vars_f vars = {NULL, NULL, NULL, NULL, NULL};

	vars.argv = argv;
	vars.environ = make_env(environment);
	if (!isatty(STDIN_FILENO))
		pipeline = 1;
	if (pipeline == 0)
		_puts(prompt);
	while (getline(&(vars.buffer), &len_buffer, stdin) != -1)
	{
		vars.command = tokenizer(vars.buffer, ";");
		for (iter = 0; vars.command[iter] != NULL; iter++)
		{
			vars.commandsAv = tokenizer(vars.command[iter], "\n ");
			if (vars.commandsAv[0])
				if (get_struc(&vars) == NULL)
					path_(&vars);
			free(vars.commandsAv);
		}
		free(vars.buffer);
		free(vars.command);
		if (pipeline == 0)
			_puts(prompt);
		vars.buffer = NULL;
	}

	if (pipeline == 0)
		_puts("\n");
	free_env(vars.environ);
	free(vars.buffer);
	exit(0);
}

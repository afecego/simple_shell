#include "shell.h"

/**
 * tokenizer - separates words by a defined delimiter
 * @buffer: ptr input whit the characters chain
 * @delimiter: delimiter for separate
 * Return: tokens, strings separetes
 */

char **tokenizer(char *buffer, char *delimiter)
{
	char **tokens = NULL;
	size_t i = 0, mcount = 10;

	if (buffer == NULL)
		return (NULL);
	tokens = malloc(sizeof(char *) * mcount);
	if (tokens == NULL)
		return (NULL);
	if (*buffer == ' ' && *(buffer + 1) == '\0')
		return (NULL);
	while ((tokens[i] = strtok(buffer, delimiter)) != NULL)
	{
		i++;
		if (i >= mcount)
		{
			tokens = NewRealloc(tokens, &mcount);
			if (tokens == NULL)
				return (NULL);
			mcount += 10;
		}
		buffer = NULL;
	}
	return (tokens);
}

/**
 * NewRealloc - function to assign a new memory spaces for a token
 * @cat: new token to allocate memory space
 * @size: size en bytes of the token
 * Return: new malloc
 */

char **NewRealloc(char **cat, size_t *size)
{
	char **New;
	unsigned int iter;

	New = malloc(sizeof(char *) * ((*size) + 10));
	if (New == NULL)
	{
		free(cat);
		return (NULL);
	}

	for (iter = 0; iter < (*size); iter++)
		New[iter] = cat[iter];
	free(cat);
	return (New);
}

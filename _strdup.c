#include "shell.h"

/**
 * _strdup - Duplicates a string in a new variable
 *@s1: String to duplicates
 *Return: A new variable with the duplicate string
 */
char *_strdup(char *s1)
{
int i = 0;
char *dupl = malloc(sizeof(char) * (_strlen(s1) + 1));
if (dupl == NULL)
{
return (NULL);
}
while (s1[i] != '\0')
{
dupl[i] = s1[i];
i++;
}
dupl[i] = '\0';
return (dupl);
free(dupl);
}

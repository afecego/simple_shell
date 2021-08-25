#include "shell.h"

int _strcmp(char *s1, char *s2)
{
    int iter;

	for (iter = 0; s1[iter] != '\0' && s2[iter] != '\0'; iter++)
	{
		if (s1[iter] != s2[iter])
			return (s1[iter] - s2[iter]);
	}
	return (0);
}

char * _strcat(char *s1, char *s2)
{
    char *concat;
    int i = 0, j = 0;

    concat = malloc(sizeof(char) * ((_strlen(s1) + _strlen(s2)) + 1));
    if (concat == NULL)
    {
        return (0);
    }

    while (s1[i] != '\0')
    {
        concat[i] = s1[i];
        i++;
    }
    while (s2[j] != '\0')
    {
        concat[i] = s2[j];
        i++;
        j++;
    }
    concat[i] = '\0';
    return (concat);
}

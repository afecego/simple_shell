#include "shell.h"

unsigned int _strlen(char *str)
{
	int i = 0;

	while(str[i])
	    i++;
	return (i);
}

void _puts(char *str)
{
	int num = 0;

	num = _strlen(str);
	
	write(STDOUT_FILENO, str, num);
}

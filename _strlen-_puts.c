#include "shell.h"

/**
 * _strlen - Counts the lenght of a string
 *@str: String that the function counts
 *Return: Number of characters of the string
 */
unsigned int _strlen(char *str)
{
int i = 0;
while (str[i])
i++;
return (i);
}

/**
 * _puts - Display a string
 *@str: String to display
 *Return: Nothing
 */
int _puts(char *str)
{
int num = 0;
num = _strlen(str);
write(STDOUT_FILENO, str, num);
}

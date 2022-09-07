#include "shell.h"

/**
 * _strlen - function to find the length of a string
 * @s: the input string
 * Return: the length of the string
 */

int _strlen(char *s)
{
	int i = 0;

	while (s[i])
		i++;

	return (i);
}

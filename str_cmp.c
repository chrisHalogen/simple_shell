#include "shell.h"

/**
 * _strcmp - function to compare 2 strings
 * @s1: the first string
 * @s2: the other string
 * Return: 0 or difference between the 2 strings
 */

int _strcmp(char *s1, char *s2)
{
	int count;

	for (count = 0; s1[count] != '\0' || s2[count] != '\0'; count++)
	{
		if (s1[count] != s2[count])
		{
			return (s1[count] - s2[count]);
		}
	}

	return (0);
}

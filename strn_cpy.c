#include "shell.h"

/**
 * _strncpy - copy a string to another
 * @dest: the destination string
 * @src: the source string
 * Return: the pointer to the dest
 */

char *_strncpy(char *dest, const char *src)
{
	char *ptr = dest;

	if (dest == NULL)
	{
		return (NULL);
	}

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}

	*dest = '\0';

	return (ptr);
}

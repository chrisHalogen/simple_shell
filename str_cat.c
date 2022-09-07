#include "shell.h"

/**
 * _strcat - function to concatenate strings
 * @dest: the destination string
 * @src: the source string
 * Return: the pointer to the destination
 */

char *_strcat(char *dest, char *src)
{
	int count = -1, n;

	for (n = 0; dest[n] != '\0'; n++)
		;

	do {
		count++;
		dest[n] = src[count];
		n++;
	} while (src[count] != '\0');

	return (dest);
}

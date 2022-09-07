#include "shell.h"

/**
 * _cut_string - truncates a string from a certain position
 * @dest: the string to be modified
 * @pos: the position in the string where you'll start truncating from
 * Return: 0 or 1
 */

char *_cut_string(char *dest, int pos)
{
	do {
		pos++;
		dest[pos] = '\0';
	} while (dest[pos + 1] != '\0');

	return (dest);
}

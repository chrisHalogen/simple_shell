#include "shell.h"

/**
 * is_path - function to check if user's first cmd is a path
 * @path: the path to the file
 * Return: 0 if is not path or 1 if is path
 */

int is_path(char *path)
{
	int count = 0;

	while (path[count])
	{
		if (path[count] == '/')
			return (1);
		count++;
	}

	return (0);
}

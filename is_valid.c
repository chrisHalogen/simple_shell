#include "shell.h"

/**
 * is_valid_file - function to check if a file is valid
 * @path: the path to the file
 * Return: 0 if file cannot be found or 1 if file exists
 */

int is_valid_file(char *path)
{
	FILE *checker = fopen(path, "r");

	if (checker)
	{
		fclose(checker);
		return (1);
	}
	else
	{
		return (0);
	}
}

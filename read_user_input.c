#include "shell.h"

/**
 * read_user_input - function to accept user inputs and also check
 * eol or ctrl + d input
 * @str: buffer for the input string
 * Return: 0 if there's need for further execution and 1 if there's not
 */

int read_user_input(char *str)
{
	char *buffer = NULL;
	size_t char_count = 0;
	ssize_t read_count = 0;

	_printf("\n$ ");
	read_count = getline(&buffer, &char_count, stdin);

	if (read_count == -1)
	{
		exit(1);
	}

	if (_strlen(buffer) != 0)
	{
		_cut_string(buffer, _strlen(buffer) - 2);
		_strncpy(str, buffer);
		return (0);
	}
	else
	{
		return (1);
	}
}

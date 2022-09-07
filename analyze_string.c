#include "shell.h"

/**
 * analyze_string - analyzes the command entered by the user and initiates
 * execution of inbuilt commands
 * @str: the pointer to the string entered by the user
 * @args: the memory reserved for the tokenized command
 * @args_pipe: the memory reserved for the piped tokenized command
 * Return: an execution flag 0, 1 or 2
 */
int analyze_string(char *str, char **args, char **args_pipe)
{
	char *input_CMD_piped[2];
	int piped = 0;

	piped = parsePipe(str, input_CMD_piped);

	if (piped)
	{
		parseSpace(input_CMD_piped[0], args);
		parseSpace(input_CMD_piped[1], args_pipe);
	}
	else
	{
		parseSpace(str, args);
	}

	if (inbuilt_cmd_handler(args))
		return (0);
	else
		return (1 + piped);
}

/**
 * parsePipe - tokenizes a command containing a pipe
 * @str: the pointer to the string entered by the user
 * @input_CMD_piped: the memory reserved for the piped tokenized command
 * Return: 0 or 1
 */
int parsePipe(char *str, char **input_CMD_piped)
{
	int count;

	for (count = 0; count < 2; count++)
	{
		input_CMD_piped[count] = _strsep(&str, "|");
		if (input_CMD_piped[count] == NULL)
			break;
	}

	if (input_CMD_piped[1] == NULL)
		return (0);
	return (1);
}

/**
 * parseSpace - tokenizes commands without the pipe
 * @str: the pointer to the string entered by the user
 * @parsed: the memory reserved for the tokenized command
 * Return: void
 */
void parseSpace(char *str, char **parsed)
{
	int i;

	for (i = 0; i < MAXLIST; i++)
	{
		parsed[i] = _strsep(&str, " ");

		if (parsed[i] == NULL)
			break;

		if (_strlen(parsed[i]) == 0)
			i--;
	}
}

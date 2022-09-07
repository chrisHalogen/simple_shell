#include "shell.h"

/**
 * inbuilt_cmd_handler - function to handle shell inbuilt commands
 * @cmd_to_execute: the command to be executed
 * Return: 0 if there's need for further execution and 1 if there's not
 */

int inbuilt_cmd_handler(char **cmd_to_execute)
{
	int inbuilt_cmd_count = 4, i, inbuilt_cmd_switch = 0;
	char *inbuilt_cmd_array[4];
	char *username;

	inbuilt_cmd_array[0] = "exit";
	inbuilt_cmd_array[1] = "cd";
	inbuilt_cmd_array[2] = "help";
	inbuilt_cmd_array[3] = "hello";

	for (i = 0; i < inbuilt_cmd_count; i++)
	{
		if (_strcmp(cmd_to_execute[0], inbuilt_cmd_array[i]) == 0)
		{
			inbuilt_cmd_switch = i + 1;
			break;
		}
	}
	switch (inbuilt_cmd_switch)
	{
		case 1:
			_printf("\nGoodbye\n");
			exit(0);
		case 2:
			chdir(cmd_to_execute[1]);
			return (1);
		case 3:
			openHelp();
			return (1);
		case 4:
			username = getenv("USER");
			printf("\nHello %s.\nUse help to know more..\n", username);
			return (1);
		default:
			break;
	}
	return (0);
}

/**
 * openHelp - helps the user navigate the console
 * Return: void
 */

void openHelp(void)
{
	_printf("\n***WELCOME TO MY SHELL HELP***");
	_printf("\n-Use the shell at your own risk...");
	_printf("\nList of Commands supported:");
	_printf("\n>cd");
	_printf("\n>ls");
	_printf("\n>exit");
	_printf("\n>all other general commands available in UNIX shell");
	_printf("\n>improper space handling");
}

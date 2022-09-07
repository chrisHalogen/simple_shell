#include "shell.h"

/**
 * main- entry point of the linux shell
 * Return: 0
 */

int main(void)
{
	char input_CMD[MAXCOM], *args[MAXLIST];
	char *args_piped[MAXLIST];
	int exec_indicator = 0;

	while (1)
	{
		read_user_input(input_CMD);

		exec_indicator = analyze_string(input_CMD, args, args_piped);

		if (exec_indicator == 1)
			exec_cmds_without_pipe(args);

	}

	return (0);
}

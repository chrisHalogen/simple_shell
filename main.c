#include "shell.h"

/**
 * main- entry point of the linux shell
 * @argc: the number of commandline args
 * @argv: the command line arguments
 * Return: 0
 */

int main(int argc, char **argv)
{
	char input_CMD[MAXCOM], *args[MAXLIST];
	char *args_piped[MAXLIST];
	int exec_indicator = 0;
	int iteration = 0 + argc;

	while (1)
	{
		read_user_input(input_CMD);

		exec_indicator = analyze_string(input_CMD, args, args_piped);

		if (exec_indicator == 1)
			exec_cmds_without_pipe(args, argv[0]);

		iteration++;
	}

	return (0);
}

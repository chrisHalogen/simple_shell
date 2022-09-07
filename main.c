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
		{
			if (is_path(args[0]) == 0)
			{
				char path_url[30] = "/usr/bin/";

				_strcat(path_url, args[0]);
				if (is_valid_file(path_url))
					exec_cmd(args, argv[0], path_url);
				else
					perror(argv[0]);
			}
			else
			{
				if (is_valid_file(args[0]))
					exec_path_cmd(args, argv[0]);
				else
					perror(argv[0]);
			}
		}
	iteration++;
	}
	return (0);
}

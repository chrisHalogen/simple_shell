#include "shell.h"

/**
 * exec_cmds_without_pipe - executes linux commands without a pipe
 * @cmd_to_execute: the command to be executed
 * @filename: the name of executable
 * Return: void
 */

void exec_cmds_without_pipe(char **cmd_to_execute, const char *filename)
{
	/* char path_url[30] = "/usr/bin/"; */
	/* int i = 0; */

	pid_t pid = fork();

	if (pid == -1)
	{
		perror(filename);
		return;
	}
	else if (pid == 0)
	{
		/* _strcat(path_url, cmd_to_execute[0]); */

		if (execve(cmd_to_execute[0], cmd_to_execute, environ) < 0)
		{
			perror(filename);
		}

		exit(0);

	}
	else
	{
		wait(NULL);
		return;
	}
}

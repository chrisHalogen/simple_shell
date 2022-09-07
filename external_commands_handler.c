#include "shell.h"

/**
 * exec_cmds_without_pipe - executes linux commands without a pipe
 * @cmd_to_execute: the command to be executed
 * Return: void
 */

void exec_cmds_without_pipe(char **cmd_to_execute)
{
	char path_url[30] = "/usr/bin/";
	int i = 0;

	pid_t pid = fork();

	if (pid == -1)
	{
		perror("\nFailed forking child..");
		return;
	}
	else if (pid == 0)
	{
		while (cmd_to_execute[0][i])
		{
			if (cmd_to_execute[0][i] == '/')
			{
				if (execve(cmd_to_execute[0], cmd_to_execute, environ) < 0)
				{
					perror("\nCould not execute command..");
				}

				exit(0);
			}
		i++;
		}

		_strcat(path_url, cmd_to_execute[0]);

		if (execve(path_url, cmd_to_execute, environ) < 0)
		{
			perror("\nCould not execute command..");
		}

		exit(0);
	}
	else
	{
		wait(NULL);
		return;
	}
}

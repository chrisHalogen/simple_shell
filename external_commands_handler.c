#include "shell.h"

/**
 * exec_cmd - executes linux commands without a pipe
 * @cmd: the command to be executed
 * @file: the name of executable
 * @path: the path to execute
 * Return: void
 */

void exec_cmd(char **cmd, const char *file, char *path)
{
	/* char path[30] = "/usr/bin/"; */
	/* int i = 0; */
	pid_t pid = fork();
	char **environ;

	/* _printf("\nFork Called\n"); */
	if (pid == -1)
	{
		perror(file);
		return;
	}
	else if (pid == 0)
	{
		/* _strcat(path, cmd[0]); */

		if (execve(path, cmd, environ) < 0)
		{
			perror(file);
		}
		exit(0);
	}
	else
	{
		wait(NULL);
		return;
	}
}


/**
 * exec_path_cmd - executes linux commands without a pipe
 * @cmd: the command to be executed
 * @file: the name of executable
 * Return: void
 */

void exec_path_cmd(char **cmd, const char *file)
{
	pid_t pid = fork();
	char **environ;

	/* _printf("\nFork Called\n"); */
	if (pid == -1)
	{
		perror(file);
		return;
	}
	else if (pid == 0)
	{
		if (execve(cmd[0], cmd, environ) < 0)
		{
			perror(file);
		}
		exit(0);
	}
	else
	{
		wait(NULL);
		return;
	}
}

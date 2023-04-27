#include "simple_shell.h"
/**
 * echo_builtin - Function that prints arguments to the standard output.
 * @args: Array of arguments.
 * Return: Always returns 1, to continue executing.
 */
int echo_builtin(char **args)
{
	int i = 1;
	char pid[20];
	int pid_len;

	while (args[i] != NULL)
	{
		if (_strcmp(args[i], "$$") == 0)
		{
			pid_len = sprintf(pid, "%d", getpid()); /*Converts the PID to a string*/
			write(STDOUT_FILENO, pid, pid_len); /*Writes the PID to std out*/
		}
		else
		{	/*Writes the args to standard output*/
			write(STDOUT_FILENO, args[i], strlen(args[i]));
		}

		if (args[i + 1] != NULL)
		{
			write(STDOUT_FILENO, " ", 1); /*Writes a space between args*/
		}

		i++;
	}

	write(STDOUT_FILENO, "\n", 1); /*Writes a newline character*/
	return (1);
}

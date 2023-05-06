#include "simple_shell.h"
/**
 *execute - Function that executes a command.
 *@args: Array of arguments.
 *Return: 1 if successful, 0 otherwise.
 */
int execute(char **args)
{
	char **args1 = args;
	char **args2 = NULL;
	int i;

	if (args[0] == NULL)
	{
		return (1);/*if empty just return & prompt again*/
	}
	for (i = 0; args[i] != NULL; i++)  /* Look for pipe symbol */
	{
		if (_strcmp(args[i], "|") == 0)
		{
			args[i] = NULL;  /* Set null terminator */
			args2 = &args[i + 1];  /* Get second command */
			break;
		}
	}
	if (args2 != NULL)
	{
		return (piping(args1, args2));  /* Call piping function */
	}
	else if (_strcmp(args[0], "cd") == 0)
	{
		return (cd_builtin(args));/*change dir cmd*/
	}
	else if (_strcmp(args[0], "echo") == 0)
	{
		return (echo_builtin(args));/*handle echo func*/
	}
	else if (strcmp(args[0], "env") == 0)
	{
		return (env_builtin(args));
	}
	else
	{
		return (launch(args));/*run cmd as external process*/
	}
}

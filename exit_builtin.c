#include "simple_shell.h"
/**
 *exit_builtin - Built-in function that exits the shell
 *@args: Arguments passed to the function
 *Return: 0 if successful, or 1 if there is an error
 */

int exit_builtin(char **args)
{
	if (args[1] != NULL)
	{
		int exit_code = atoi(args[1]);

		exit(exit_code);
	}
	else
	{
		exit(EXIT_SUCCESS);
	}
}

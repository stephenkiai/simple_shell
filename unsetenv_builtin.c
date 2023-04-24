#include "simple_shell.h"
/**
 * unsetenv_builtin - function to unset enviroment variable
 * @args: array of arguments passed to shell
 * Author Steve and Tway
 * Return: 0 on success, 1 on failure
 */

int unsetenv_builtin(char **args)
{
	/*check if argument is null */
	if (args[1] == NULL)
	{
		fprintf(stderr, "unsetenv: missing argument\n");
		return (1);
	}
	/*unset environment variable*/
	if (unsetenv(args[1]) != 0)
	{
		/* print erro message if unsetenv fails*/
		perror("unsetenv");
		return (1);
	}
	/*returm 0 on success*/
	return (0);
}

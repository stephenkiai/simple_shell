#include "simple_shell.h"
/**
 *exit_status - Built-in function that exits the shell
 *@args: Arguments passed to the function
 *Return: 0 if successful, or 1 if there is an error
 */

int exit_status(char **args)
{
	int exit_code = 0;

	if (args[1] != NULL)
	{
		/*Convert the second argument to an integer*/
		exit_code = atoi(args[1]);

		/*If the conversion fail, print error mssg & return error code*/
		if (exit_code == 0 && args[1][0] != '0')
		{
			fprintf(stderr, "hsh: exit: %s: numeric argument required\n", args[1]);
			return (2);
		}
	}

	/*Exit the shell with the specified exit code*/
	exit(exit_code);
	return (0);
}

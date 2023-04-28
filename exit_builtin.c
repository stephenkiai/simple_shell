#include "simple_shell.h"
#include <limits.h>
/**
 * exit_builtin - Built-in function that exits the shell
 * @args: Arguments passed to the function
 * Return: 0 if successful, or 1 if there is an error
 */
int exit_builtin(char **args)
{
	char *endptr;
	long exit_code;
	int i;

	if (args[1] != NULL)
	{
		/* Check for non-numeric characters in status code*/
		for (i = 0; args[1][i] != '\0'; i++)
		{
			if (!isdigit(args[1][i]))
			{
				fprintf(stderr, "Error: Invalid exit code\n");
				return (1);
			}
		}
		exit_code = strtol(args[1], &endptr, 10);

		if (*endptr != '\0' || exit_code > INT_MAX || exit_code < INT_MIN)
		{
			fprintf(stderr, "Error: Invalid exit code\n");
			return (1);
		}
		exit((int) exit_code);
	}
	else
	{
		exit(0);
	}
	/* Print error message if too many arguments are provided*/
	if (args[2] != NULL)
	{
		fprintf(stderr, "Error: Too many arguments\n");
		return (1);
	}
	return (0);
}

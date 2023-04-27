#include "simple_shell.h"
/**
 * logical - Function that handles the && and || operators.
 * @args: Array of arguments.
 * Return: 1 if successful, 0 otherwise.
 */
int logical(char **args)
{
	int status;
	int i = 0;
	int logical_operator = AND; /*initialize to AND operator*/

	while (args[i] != NULL)
	{
		if (_strcmp(args[i], "&&") == 0)
		{
			logical_operator = AND;
		}
		else if (_strcmp(args[i], "||") == 0)
		{
			logical_operator = OR;
		}
		else
		{ /*execute command*/
			char **cmd_args = parse_line(args[i]);
			if (cmd_args[0] != NULL)
			{
				if (_strcmp(cmd_args[0], "exit") == 0)
				{
					status = exit_builtin(cmd_args);
				}
				else
				{
					status = launch(cmd_args);
				}
			}
			free(cmd_args);
			if (logical_operator == AND && status != 0)
			{ /*if AND operator and the command fails, stop executing*/
				break;
			}
			else if (logical_operator == OR && status == 0)
			{ /*if OR operator and the command succeeds, stop executing*/
				break;
			}
		}
		i++;
	}
	return (status);
}

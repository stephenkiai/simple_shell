#include "simple_shell.h"
/**
 * main - main shell
 * line: stores the command entered by user
 * args: stores the parsed command
 * @argc: argument count
 * @argv: argument vector
 * status: stores the status of executed command
 * This program is a simple shell program that can be used to execute commands.
 * It can be used in two modes: interactive mode and file input mode.
 * interactive mode, user is prompted to enter a command, which is parsed exec
 * file input mode, the program reads commands from a file and executes them.
 * Return: Success
 */

int main(int argc, char **argv)
{
	char *line;
	char **args;
	int status;

	/* Check if file input mode is enabled*/
	if (argc > 1)
	{
		file_input(argv[1]);  /* Call file_input() with filename*/
		return (EXIT_SUCCESS);  /* Exit prgm after exec the file cmd */
	}

	/* Otherwise, enter the interactive shell mode*/
	do {
		/* display the prompt*/
		prompt();
		/*read the command from the user */
		line = read_line();
		/* parse the command */
		args = parse_line(line);
		/* execute the command */
		status = execute(args);
		/* free the memory allocated for the command*/
		free(line);
		free(args);
	} while (status);

	return (EXIT_SUCCESS);
}

#include "simple_shell.h"
/**
 * file_input - reads a file and execute the commands
 * @filename: The name of the file to read
 * Author Steve and Tway
 * Return: 0 on success, 1 on failure
 */

int file_input(char *filename)
{
	FILE *fp = fopen(filename, "r");
	char *line = NULL;
	size_t buffer_size = 0;
	int status = 0;

	if (fp == NULL)
	{
		perror("file_input");
		return (1);
	}

	while (my_getline(&line, &buffer_size, fp) != -1)
	{
		char **args = parse_line(line);

		if (args[0] != NULL)
		{
			if (_strcmp(args[0], "exit") == 0)
			{
				status = exit_builtin(args);

			}
			else
			{
				status = execute(args);
			}
		}
		free(args);
		if (status != 0)
		{
			break;
		}
	}
	free(line);
	fclose(fp);
	return (status);
}

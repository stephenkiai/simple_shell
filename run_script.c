#include "simple_shell.h"
/**
 * run_script - run a script from a given file
 * @filename: the name of the file to be read
 * Author Tway and Steve
 * Return: 0 on sucess, 1 on failure
 */

int run_script(char *filename)
{
	FILE *fp = fopen(filename, "r");
	char *line = NULL;
	size_t buffer_size = 0;

	if (fp == NULL)
	{
		perror("run_script");
		return (1);
	}

	while (my_getline(&line, &buffer_size, fp) != -1)
	{
		char **args = parse_line(line);

		if (args[0] != NULL)
		{
			if (strcmp(args[0], "exit") == 0)
			{
				exit_builtin(args);
			}
			else
			{
				execute(args);
			}
		}
		free(args);
	}
	free(line);
	fclose(fp);
	return (0);
}

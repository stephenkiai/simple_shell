#include "simple_shell.h"
/**
 * read_line - Reads line from stdin
 * This function reads a line from stdin and stores it in a buffer.
 * Author Tway ans Steve
 * Return:  Pointer to the line read from stdin
 */
char *read_line(void)
{
	char *line = NULL;
	size_t buffer_size = 0;

	/* get a line from stdin */
	if (my_getline(&line, &buffer_size, stdin) == -1)
	{
		/*check if EOF was reached */
		if (feof(stdin))
		{
			/* exit the program */
			exit(EXIT_SUCCESS);
		}
		else
		{
			panic("read_line failed");
		}
	}
	/* return the line read from  stdin*/
	return (line);
}

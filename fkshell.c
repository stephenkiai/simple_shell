#include "fkshell.h"
/**
 *
 *
 *
 */
int main()
{
	char command[CMD_IN_SIZE];/*stores the command typed by the user*/

	/*display a prompt and wait the user to type a command*/
	while (1)
	{
		write(STDOUT_FILENO, "fkshell$ ", 9);
		if (fgets(command, CMD_IN_SIZE, stdin) == NULL)
		{
			/*handle the EOF condition*/
			/*if (feof(stdin))*/
			if (errno == 0)
			{
				write(STDOUT_FILENO, "\n", 1);
				exit(EXIT_SUCCESS);
			}
		}
		else
		{
			perror("fgets");
			exit(EXIT_FAILURE);
		}
		command[strlen(command) - 1] = '\0';
		return (0);
}
}

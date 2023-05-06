#include "simple_shell.h"
/**
 *panic - prints error msg, & exits prgm with failure status
 *@message: error message to be printed
 *
 */

void panic(char *message)
{
	perror(message);
	exit(EXIT_FAILURE);
}

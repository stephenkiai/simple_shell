#include "simple_shell.h"
/**
 * getpid_string - Return the string representation of the process ID.
 *
 * Return: The string representation of the process ID.
 */
char *getpid_string(void)
{
	pid_t pid = getpid();
	char *pid_str;

	pid_str = malloc(20); /* Enough to hold any 32-bit integer. */
	if (pid_str == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	sprintf(pid_str, "%d", pid);
	return (pid_str);
}

#include "simple_shell.h"
/**
 * env_builtin - Executes the "env" command.
 * @args: Null-terminated array of command-line arguments.
 *
 * Return: 1 on success, or 0 on failure.
 */
int env_builtin(char **args)
{
	extern char **environ;
    	char **env = environ;

    	if (args[1] == NULL)
    	{
        	/* Print out all environment variables */
        	while (*env != NULL)
        	{
             	size_t len = strlen(*env);
            	write(STDOUT_FILENO, *env, len);
            	write(STDOUT_FILENO, "\n", 1);
            	env++;
        	}
    	}

   	 return 1;
}


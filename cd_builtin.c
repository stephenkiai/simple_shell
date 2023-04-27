#include "simple_shell.h"

/**
 * cd_builtin - change current working directory
 * @args: the arguments passed to shell
 * Authors Tway and Steve
 * Return: 1 on success, 0 on failure
 */
int cd_builtin(char **args)
{
    	char *new_dir = getcwd(NULL, 0);
    	char *prev_dir = getenv("OLDPWD");

    	if (args[1] == NULL)
    	{
        	if (chdir(getenv("HOME")) != 0)
        	{
           	 	perror("cd");
        	}
    	}
    	else if (_strcmp(args[1], "-") == 0)
    	{
        	if (prev_dir == NULL)
        	{
            		write(STDERR_FILENO, "cd: OLDPWD not set\n", 19);
        	}
        	else
        	{
            		if (chdir(prev_dir) != 0)
            	{
                	perror("cd");
            	}
            	write(STDOUT_FILENO, prev_dir, _strlen(prev_dir));
            	write(STDOUT_FILENO, "\n", 1);
        	}
    	}
    	else
    	{
        	if (chdir(args[1]) != 0)
        {
            	perror("cd");
        }
    	}
   	if (new_dir == NULL)
    	{
        	panic("getcwd failed");
    	}

    	setenv("OLDPWD", getenv("PWD"), 1);
    	setenv("PWD", new_dir, 1);

    	free(new_dir);

    	return (1);
}


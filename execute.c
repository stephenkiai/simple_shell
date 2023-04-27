#include "simple_shell.h"
/**
 *execute - Function that executes a command.
 *@args: Array of arguments.
 *Return: 1 if successful, 0 otherwise.
 */
int execute(char **args)
{
	if (args[0] == NULL)
	{
		return (1);/*if empty just return & prompt again*/
	}
		if (_strcmp(args[0], "cd") == 0)
	{
		return (cd_builtin(args));/*change dir cmd*/
	}
	else if (_strcmp(args[0], "echo") == 0)
	{
		return (echo_builtin(args));/*handle echo func*/
	}
	else if (_strcmp(args[0], "exit") == 0)
	{
		return (exit_builtin(args));/*exit cmd*/
	}
	else if (_strcmp(args[0], "setenv") == 0)
	{
		return (setenv_builtin(args));/*set env var cmd*/
	}
	else if (_strcmp(args[0], "unsetenv") == 0)
	{
		return (unsetenv_builtin(args));/*unset env var cmd*/
	}
	else if (_strcmp(args[0], "alias") == 0)
	{
		return (alias_builtin(args));/*alias cmd*/
	}
	else if (_strcmp(args[0], "run_script") == 0)
	{
		return (run_script(args[1]));/*run script cmd*/
	}
	else if (_strcmp(args[0], "&&") == 0)
	{
		return (logical(args));/*handle logical operators*/
	}
	else
	{
		return (launch(args));/*run cmd as external process*/
	}
}

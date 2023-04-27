#include "simple_shell.h"
/**
 * _strlen - Calculate the length of a string
 * @s: the string to calculate the length of
 * Return: The length of the string
 */
size_t _strlen(const char *s)
{
	size_t len = 0;

	while (s && *s)
	{
		len++;
		s++;
	}

	return (len);
}

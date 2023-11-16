#include "main.h"

/**
 *_strlen_recursion - returns the length of a string
 *@s: the string to be printed
 *Return: Always 0 on success
 */
int _strlen_recursion(char *s)
{
	int lens = 0;

	if (*s)
	{
		lens++;
		lens += _strlen_recursion(s + 1);
	}
	return (lens);
}

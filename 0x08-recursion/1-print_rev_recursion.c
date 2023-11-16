#include "main.h"

/**
 * _print_rev_recursion - prints the string in reverse
 * @s: - the string parameter
 * Return: Always 0 if successful
*/
void _print_rev_recursion(char *s)
{
	if (*s == '\0')
		return;
	s++;
	_print_rev_recursion(s);
	s--;
	_putchar(*s);
}

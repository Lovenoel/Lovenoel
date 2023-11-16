#include <unistd.h>

/**
 *_putchar - writes the character c to stdout
 *@c: the character to print
 *Return: 1 0n success and -1 on error or failure
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

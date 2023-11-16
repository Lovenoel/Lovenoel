#include <unistd.h>

/**
 * _putchar - prints the character c to the stdout
 * @c: the character
 * Return: 0 on success and -1 on incase of an error
 * and errno is set appropriately
*/
int _putchar(char c)
{
    return (write(1, &c, 1));
}
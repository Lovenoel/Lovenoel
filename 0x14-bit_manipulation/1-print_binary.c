#include "main.h"

/**
 * print_binary - prints the binary representation of a number
 *@n: the number to be printed in binary representation
 *
 *Return: 0 on success
 */
void print_binary(unsigned long int n)
{
	int i, count = 0;
	unsigned long int now;

	for (i = 63; i >= 0; i--)
	{
		now = n >> i;
		if (now & 1)
		{
			_putchar('1');
			count++;
		}
		else if (count)
			_putchar('0');
	}
	if (!count)
		_putchar('0');
}

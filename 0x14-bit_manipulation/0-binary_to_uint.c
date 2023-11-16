#include "main.h"

/**
 * binary_to_uint - converts a binary number to an unsigned int
 * @b: string having the binary number
 *
 *Return: converted number or 0 if
 * - there is one or more chars in the string b that is not 0 or 1
 * - b is Null
 */
unsigned int binary_to_uint(const char *b)
{
	int i;
	unsigned int decimal_value = 0;

	if (!b)
		return (0);
	for (i = 0; b[i]; i++)
	{
		if (b[i] < '0' || b[i] > '1')
			return (0);
		decimal_value = 2 * decimal_value + (b[i] - '0');
	}
	return (decimal_value);
}

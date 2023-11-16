#include "main.h"

/**
 * flip_bits - returns the number of bits you
 * would need to flip to get from one number to another.
 *@n: the first number
 *@m: the second number
 *
 * Return: number of bits to be changed
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int i, counts = 0;
	unsigned long int now;
	unsigned long int excluded = n ^ m;

	for (i = 63; i >= 0; i--)
	{
		now = excluded >> i;
		if (now & 1)
			counts++;
	}
	return (counts);
}

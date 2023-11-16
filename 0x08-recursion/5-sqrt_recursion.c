#include "main.h"

/**
 *_sqrt_recursion - returns the natural square root of a number
 *@n: the number parameter
 *Return: -1 if n does not have natural square root
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	return (_sqrt_recursion(n));
}

/**
 *actual__sqrt_recursion - recurses to find the natural square root
 *of a number
 *@n: the number to calculate the square root of
 *@i: the iterator
 *Return: 0 on success and -1 on failure
 */
int actual_sqrt_recursion(int n, int i)
{
	if (i * i > n)
		return (-1);
	if (i * i == n)
		return (i);
	return (actual_sqrt_recursion(n, i + 1));
}

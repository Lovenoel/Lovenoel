#include "main.h"

/**
 * _strspn - gets the length of a prefix substring
 * @s: String to search
 * @accept: String containing acceptable characters
 * Return: the number of bytes
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int len = 0;
	int found;

	while (*s)
	{
		found = 0;
		for (char *b = accept; *b; b++)
		{
			if (*s == *b)
			{
				found = 1;
				break;
			}
		}
		if (!found)
		{
			break;
		}
		len++;
		s++;
	}
	return (len);
}

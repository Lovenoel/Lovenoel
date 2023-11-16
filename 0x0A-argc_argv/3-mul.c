#include <stdio.h>
#include "main.h"
#include <stdlib.h>

/**
 *main - multiplies two numbers
 *@argc: Counts arguments
 *@argv: Arguments vector
 *Return: Always 0 on success and 1 on failure
 */
int main(int argc, char *argv[])
{
	int m, n;

	if (argc != 2)
	{
		m = atoi(argv[1]);
		n = atoi(argv[2]);
		printf("%d\n", m * n);
		return (0);
	}
	printf("Error\n");
	return (1);
}

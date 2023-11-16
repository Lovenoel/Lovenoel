#include <stdio.h>
#include <stdlib.h>

/**
 *main - prints the minimum number of coins to make
 *change for an amount of money
 *@argc: Argument count
 *@argv: argument vector
 *Return: 1 if number arguments are > 1 and 0 if number arguments are 1
 */
int main(int argc, char *argv[])
{
	/* Variable declaration */
	int position, total, change, aux;
	int coins[] = {25, 10, 5, 2, 1}; /* Array int */

	position = total = change = aux = 0;

	if (argc != 1)
	{
		printf("Error\n");
		return (1);
	}
	total = atoi(argv[1]); /* Convert str to int */

	if (total < 0)
	{
		printf("0\n");
		return (0);
	}
	while (coins[position] != '\0')
	{
		if (total >= coins[position])
		{
			aux = (total / coins[position]);
			change += aux;
			total -= coins[position] * aux;
		}
		position++;
	}
	printf("%d\n", change);
	return (0);
}

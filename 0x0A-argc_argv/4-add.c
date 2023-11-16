#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "main.h"
/**
 *check_num - check if the string has digits
 *@str: array atr
 *Return: Always 0 (success)
 */
int check_num(char *str)
{
	unsigned int count;

	count = 0;
	while (count < strlen(str)) /* count string */
	{
		if (!isdigit(str[count])) /* check if the string has digits */
		{
			return (0);
		}
		count++;
	}
	return (1);
}

/**
 *main - adds positive numbers
 *@argc: Argument count
 *@argv: Argument vector
 *Return: Always 0 on succes
 */
int main(int argc, char *argv[])
{
	int count;
	int str_to_int;
	int sum = 0;

	count = 1;
	while (count < argc) /* go through the whole array */
	{
		if (check_num(argv[count]))
		{
			str_to_int = atoi(argv[count]); /* atoi --> convert string to int */
			sum += str_to_int;
		}
		else
		{
			printf("Error\n");
			return (1);
		}
		count++;
	}
	printf("%d\n", sum); /* prints the sum */
	return (0);
}

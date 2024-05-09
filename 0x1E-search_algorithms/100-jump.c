#include <stdio.h>
#include <math.h>

/**
 * jump_search - Search for a value in a sorted array using Jump search
 * algorithm
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 * @value: Value to search for
 * Return: Index of the first occurrence of value, or -1 if not found
 */
int jump_search(int *array, size_t size, int value)
{
	size_t i, step, prev, next;

	if (array == NULL)
		return (-1);

	step = sqrt(size);
	prev = 0;

	while (array[prev] < value)
	{
		next = prev + step;
		if (next >= size)
			next = size - 1;

		printf("Value checked array[%lu] = [%d]\n", next, array[next]);
		if (array[next] >= value || next == size - 1)
		{
			printf("Value found between indexes [%lu] and [%lu]\n", prev, next);
			break;
		}

		prev += step;
	}

	for (i = prev; i <= size && i < prev + step; i++)
	{
		printf("Value checked array[%lu] = [%d]\n", i, array[i]);
		if (array[i] == value)
			return (i);
	}

	return (-1);
}

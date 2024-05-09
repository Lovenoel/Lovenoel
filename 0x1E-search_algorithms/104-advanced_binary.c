#include <stdio.h>

/**
 * advanced_binary_recursive - Recursive helper function for advanced_binary
 * @array: Pointer to the first element of the array
 * @low: Starting index of the subarray
 * @high: Ending index of the subarray
 * @value: Value to search for
 * Return: Index of the first occurrence of value, or -1 if not found
 */
int advanced_binary_recursive(int *array, size_t low, size_t high, int value)
{
	if (low <= high)
	{
		size_t mid = low + (high - low) / 2;

		printf("Searching in array: ");
		for (size_t i = low; i <= high; i++)
		{
			printf("%d", array[i]);
			if (i < high)
                		printf(", ");
		}
		printf("\n");

		if (array[mid] == value)
		{
			if (mid == 0 || array[mid - 1] != value)
				return mid;
			return advanced_binary_recursive(array, low, mid, value);
		}
		else if (array[mid] < value)
		{
			return advanced_binary_recursive(array, mid + 1, high, value);
		}
		else
		{
			return advanced_binary_recursive(array, low, mid - 1, value);
		}
	}

	return -1;
}

/**
 * advanced_binary - Search for a value in a sorted array using Advanced Binary search algorithm
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 * @value: Value to search for
 * Return: Index of the first occurrence of value, or -1 if not found
 */
int advanced_binary(int *array, size_t size, int value)
{	if (array == NULL)
		return -1
	return advanced_binary_recursive(array, 0, size - 1, value);
}

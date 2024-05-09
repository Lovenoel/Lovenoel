#include <stdio.h>

/**
 * exponential_search - Search for a value in a sorted array using Exponential search algorithm
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 * @value: Value to search for
 * Return: Index of the first occurrence of value, or -1 if not found
 */
int exponential_search(int *array, size_t size, int value)
{
    if (array == NULL)
        return -1;

    size_t bound = 1;

    while (bound < size && array[bound] < value)
    {
        printf("Value checked array[%lu] = [%d]\n", bound, array[bound]);
        bound *= 2;
    }

    size_t left = bound / 2;
    size_t right = bound < size ? bound : size - 1;

    printf("Value found between indexes [%lu] and [%lu]\n", left, right);

    for (size_t i = left; i <= right; i++)
    {
        printf("Value checked array[%lu] = [%d]\n", i, array[i]);
        if (array[i] == value)
            return i;
    }

    return -1;
}

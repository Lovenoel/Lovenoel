#include <stdio.h>
#include <math.h>

/**
 * jump_search - Search for a value in a sorted array using Jump search algorithm
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 * @value: Value to search for
 * Return: Index of the first occurrence of value, or -1 if not found
 */
int jump_search(int *array, size_t size, int value)
{
    if (array == NULL)
        return -1;

    size_t step = sqrt(size);
    size_t prev = 0;

    while (array[prev] < value)
    {
        size_t next = prev + step;
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

    for (size_t i = prev; i <= size && i < prev + step; i++)
    {
        printf("Value checked array[%lu] = [%d]\n", i, array[i]);
        if (array[i] == value)
            return i;
    }

    return -1;
}

#include <stdio.h>

/**
 * interpolation_search - Search for a value in a sorted array using Interpolation search algorithm
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 * @value: Value to search for
 * Return: Index of the first occurrence of value, or -1 if not found
 */
int interpolation_search(int *array, size_t size, int value)
{
    if (array == NULL)
        return -1;

    size_t low = 0;
    size_t high = size - 1;

    while (low <= high && value >= array[low] && value <= array[high])
    {
        if (low == high)
        {
            if (array[low] == value)
                return low;
            return -1;
        }

        size_t pos = low + (((double)(high - low) / (array[high] - array[low])) * (value - array[low]));

        printf("Value checked array[%lu] = [%d]\n", pos, array[pos]);

        if (array[pos] == value)
            return pos;
        else if (array[pos] < value)
            low = pos + 1;
        else
            high = pos - 1;
    }

    return -1;
}

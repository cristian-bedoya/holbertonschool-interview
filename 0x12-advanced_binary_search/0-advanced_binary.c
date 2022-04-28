#include "search_algos.h"
/**
 * search - Recursively searches for a given value in an array
 * @array: pointer to the first element of the array search in
 * @value: the value to search for
 * @l: leftmost index used as boundary
 * @r: rightmost index used as boundary
 *
 * Return: The index where the value was located for the first
 * time, or -1
 */
int search(int *array, int l, int r, int value)
{
	int i, mid;

	mid = l + (r - l) / 2;
	if (l == r)
	{
		if (value < array[l] || value > array[r])
		{
			printf("Searching in array: %d\n", array[mid]);
			return (-1);
		}
		return (l);
	}
	printf("Searching in array:");
	for (i = l; i <= r; i++)
	{
		if (i != r)
			printf(" %d,", array[i]);
		else
			printf(" %d\n", array[i]);
	}

	if (array[mid] < value)
		return (search(array, mid + 1, r, value));
	else
		return (search(array, l, mid, value));
}

/**
 * advanced_binary - Searches for a value in a sorted array of integers.
 * @array: pointer to the first element of hte array to search in
 * @size: number of elements in array
 * @value: the value to search for
 *
 * Return: The index where the value was located for the first time, or -1
*/
int advanced_binary(int *array, size_t size, int value)
{
	if (!array)
		return (-1);
	return (search(array, 0, size - 1, value));
}

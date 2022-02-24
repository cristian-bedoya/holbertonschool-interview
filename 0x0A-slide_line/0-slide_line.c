#include "slide_line.h"

/**
 * swap - swaps two integers
 * @a: pointer to an int
 * @b: pointer to an int
 */
void swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}

/**
 * slide_left - slides an array of integers to the left,
 * skipping all the zeros in between.
 * @line: pointer to an array of integers.
 * @size: size of line array
 */
void slide_left(int *line, size_t size)
{
	size_t i, p = 0;

	for (i = 0; i < size && p < size; i++)
	{
		while (line[p] == 0 && p < size && p + 1 < size)
			p++;
		if (line[i] == 0)
			swap(&line[p], &line[i]);
		p++;
	}
}

/**
 * slide_right - slides an array of integers to the right,
 * skipping all the zeros in between.
 * @line: pointer to an array of integers.
 * @size: size of line array
 */
void slide_right(int *line, size_t size)
{
	size_t i, p = size - 1;

	for (i = size - 1; (int) i >= 0 && (int) p >= 0; i--)
	{
		while (line[p] == 0 && (int) p > 0)
			p--;
		if (line[i] == 0)
			swap(&line[p], &line[i]);
		p--;
	}
}

/**
 * slide_line - slides and merges an array of integers
 * @line: points to an array of integers
 * @size: number of elements of array
 * @direction: SLIDE_LEFT, SLIDE_RIGHT
 * Return: 1 upon success, or 0 upon failure.
 */
int slide_line(int *line, size_t size, int direction)
{
	size_t i = 0;

	if (direction == SLIDE_LEFT)
	{
		slide_left(line, size);
		for (i = 0; i < size; i++)
		{
			if (line[i] == line[i + 1])
			{
				line[i] = line[i] + line[i + 1];
				line[i + 1] = 0;
			}
		}
		slide_left(line, size);
		return (1);
	} else if (direction == SLIDE_RIGHT)
	{
		slide_right(line, size);
		for (i = size - 1; (int) i >= 0; i--)
		{
			if (line[i] == line[i - 1])
			{
				line[i] = line[i] + line[i - 1];
				line[i - 1] = 0;
			}
		}
		slide_right(line, size);
		return (1);
	}
	return (0);
}

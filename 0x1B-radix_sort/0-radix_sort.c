#include "sort.h"
/**
 * csort2 - function docs
 *
 * @array: array
 * @buff: buff
 * @size: size
 * @lsd: lsd
 *
 * Return: void
 */
void csort2(int *array, int **buff, int size, int lsd)
{
	int vector[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int vector2[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int i, j, csize = 10, num;

	for (i = 0; i < size; i++)
	{
		num = array[i];
		for (j = 0; j < lsd; j++)
			if (j > 0)
				num = num / 10;
		num = num % 10;
		buff[num][vector[num]] = array[i];
		vector[num] += 1;
	}

	for (i = 0, j = 0; i < csize; i++)
	{
		while (vector[i] > 0)
		{
			array[j] = buff[i][vector2[i]];
			vector2[i] += 1, vector[i] -= 1;
			j++;
		}
	}

	print_array(array, size);
}
/**
 * csort - function docs
 *
 * @array: array
 * @size: size
 * @lsd: lsd
 *
 * Return: void
 */
void csort(int *array, int size, int lsd)
{
	int i, j, num, csize = 10, **buff;
	int vec[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	for (i = 0; i < size; i++)
	{
		num = array[i];
		for (j = 0; j < lsd; j++)
			if (j > 0)
				num = num / 10;
		num = num % 10;
		vec[num] += 1;
	}

	if (vec[0] == size)
		return;

	buff = malloc(sizeof(int *) * 10);
	if (!buff)
		return;

	for (i = 0; i < csize; i++)
		if (vec[i] != 0)
			buff[i] = malloc(sizeof(int) * vec[i]);

	csort2(array, buff, size, lsd);

	csort(array, size, lsd + 1);

	for (i = 0; i < csize; i++)
		if (vec[i] > 0)
			free(buff[i]);
	free(buff);
}
/**
 * radix_sort - function docs
 *
 * @array: array
 * @size: size
 *
 * Return: void
 */
void radix_sort(int *array, size_t size)
{
	if (size < 2)
		return;
	csort(array, size, 1);
}

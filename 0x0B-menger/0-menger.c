#include "menger.h"
/**
 * addSpace - Checks whether cell of grid needs to be a space
 * @i: row index
 * @j: col index
 * Return: 1 if cell is a space, 0 if it isn't.
 */
int addSpace(int i, int j)
{
	while (j && i)
	{
		if (i % 3 == 1 && j % 3 == 1)
			return (1);
		i = i / 3, j = j / 3;
	}
	return (0);
}

/**
 * menger - draws a 2D Menger Sponge
 * @level: level of the Menger Sponge to draw
 */
void menger(int level)
{
	int i, j;
	int dim = pow(3, level);

	for (i = 0; i < dim; i++)
	{
		for (j = 0; j < dim; j++)
		{
			if (addSpace(i, j))
				printf(" ");
			else
				printf("#");
		}
		puts("");
	}
}

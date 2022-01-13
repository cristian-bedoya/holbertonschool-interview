#include "sandpiles.h"
/**
 * print_grid - Print a grid.
 * @grid: Grid, is a matrix.
 * Return: Nothing.
 */
void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}
/**
 * sandpiles_sum_and_check - Get sum and check stability.
 * @grid1: Grid, a matrix, use here to store the result of sum.
 * @grid2: Grid, a matrix, use later for toppling.
 * Return: Status, 0 if is stable or 1 if it is not stable.
 */
int sandpiles_sum_and_check(int grid1[3][3], int grid2[3][3])
{
	int i, j, status = 0;

	for (i = 0; i <= 2; i++)
	{
		for (j = 0; j <= 2; j++)
		{
			grid1[i][j] += grid2[i][j], grid2[i][j] = 0;
			if (grid1[i][j] >= 4)
				status = 1;
		}
	}
	return (status);
}
/**
 * sandpiles_toppling - topples the grid untill it becomes stable.
 * @grid1: the grid to topple.
 * @grid2: the empty grid using for storing.
 * Return: Nothing.
 */
void sandpiles_toppling(int grid1[3][3], int grid2[3][3])
{
	int i, j, status = 1;

	while (status == 1)
	{
		printf("=\n");
		print_grid(grid1);
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (grid1[i][j] >= 4)
				{
					grid1[i][j] -= 4;
					i - 1 >= 0 ? grid2[i - 1][j] += 1 : 0;
					i + 1 < 3 ? grid2[i + 1][j] += 1 : 0;
					j - 1 >= 0 ? grid2[i][j - 1] += 1 : 0;
					j + 1 < 3 ? grid2[i][j + 1] += 1 : 0;
				}
			}
		}
		status = sandpiles_sum_and_check(grid1, grid2);
	}
}
/**
 * sandpiles_sum - function that computes the sum of two sandpiles.
 * @grid1: sandpile, a matrix, first grid.
 * @grid2: sandpile, a matrix, second grid.
 * Return: Nothing.
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	if (sandpiles_sum_and_check(grid1, grid2))
		sandpiles_toppling(grid1, grid2);
}

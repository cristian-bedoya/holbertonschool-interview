#include "holberton.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * print_num - prints an array of integers like a number
 * @nums3: array of integers
 * @size: size of the array of integers
 */
void print_num(int *nums3, int size)
{
	int i = 0;

	if (!nums3 && !size)
	{
		printf("0\n");
		exit(0);
	}
	while (nums3[i] == 0)
		i++;
	for (; i < size; i++)
	{
		printf("%d", nums3[i]);
	}
	printf("\n");
}

/**
 * multiply - multiplies two large numbers
 * @nums1: string representation of large int
 * @nums2: string representation of large int
 * Return: 1 on success, 0 on failure
 */
int multiply(char *nums1, char *nums2)
{
	int i, j;
	int len1, len2, sum, n1, n2 = 0;
	int *nums3;

	len1 = strlen(nums1);
	len2 = strlen(nums2);

	nums3 = calloc(len1 + len2, sizeof(len1 + len2));
	if (!nums3)
		return (0);

	for (i = len1 - 1; i >= 0; i--)
	{
		n1 = nums1[i] - '0';
		for (j = len2 - 1; j >= 0; j--)
		{
			n2 = nums2[j] - '0';
			sum = (n1 * n2) + nums3[i + j + 1];
			nums3[i + j] += sum / 10;
			nums3[i + j + 1] = sum % 10;
		}
	}
	print_num(nums3, len1 + len2);
	free(nums3);
	return (1);
}

/**
 * main - Entry point: multiplies two positive numbers
 * @argc: number of arguments passed
 * @argv: arguments passed (integers)
 * Return: 0 in success, 1 on failure
 */
int main(int argc, char **argv)
{
	int i, j = 0;

	if (argc != 3)
	{
		printf("Error\n");
		exit(98);
	}
	for (i = 1; argv[i]; i++)
		for (j = 0; argv[i][j]; j++)
			if (argv[i][j] < '0' || argv[i][j] > '9')
			{
				printf("Error\n");
				exit(98);

			}

	if (*argv[1] == '0' || *argv[2] == '0')
		print_num(NULL, 0);
	if (!multiply(argv[1], argv[2]))
		return (1);
	return (0);
}

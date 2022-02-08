#include "palindrome.h"

/**
 * is_palindrome - the palindrome given
 * unsigned integer is a palindrome.
 * @n: check the number
 * Return: 1  or 0
 */
int is_palindrome(unsigned long n)
{
	int array_buf[40];
	int number_lenght, j;
	unsigned long int number = n;

	for (number_lenght = 0; number != 0; number_lenght++)
	{
		array_buf[number_lenght] = number % 10;
		number = number / 10;
	}

	for (j = 0; j < number_lenght / 2; j++)
	{
		if (array_buf[number_lenght - j - 1] != array_buf[j])
			return (0);
	}
	return (1);
}

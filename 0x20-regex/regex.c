#include "regex.h"
/**
* regex_match - checks whether a given pattern
* @str: string
* @pattern: pattern
* Return: 1 success
*/
int regex_match(char const *str, char const *pattern)
{
	int d = 0;
	int r = 0;

	if (!str || !pattern)
		return (0);

	d = *str && (*str == *pattern || *pattern == '.');
	r = *(pattern + 1) == '*';

	if (!*str && !r)
		return (*pattern ? 0 : 1);
	else if (d && r)
		return (regex_match(str + 1, pattern) || regex_match(str, pattern + 2));
	else if (d && !r)
		return (regex_match(str + 1, pattern + 1));
	else if (r)
		return (regex_match(str, pattern + 2));
	return (0);
}

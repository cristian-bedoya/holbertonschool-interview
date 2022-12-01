# 0x1E. Wild Compare

## Task
### [0. Wild Compare](./0-wildcmp.c)
Write a function that compares two strings and returns 1 if the strings can be considered identical, otherwise return 0.

  - ` Prototype: int wildcmp(char *s1, char *s2);`
  - ` s2` can contain the special character`*`.
  -  The special char` *` can replace any string (including an empty string)


```
alexa@ubuntu:~/0x1E-wild_cmp$ cat 0-main.c
#include "holberton.h"
#include <stdio.h>

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
    int r;

    r = wildcmp("main.c", "*.c");
    printf("%d\n", r);
    r = wildcmp("main.c", "m*a*i*n*.*c*");
    printf("%d\n", r);
    r = wildcmp("main.c", "main.c");
    printf("%d\n", r);
    r = wildcmp("main.c", "m*c");
    printf("%d\n", r);
    r = wildcmp("main.c", "ma********************************c");
    printf("%d\n", r);
    r = wildcmp("main.c", "*");
    printf("%d\n", r);
    r = wildcmp("main.c", "***");
    printf("%d\n", r);
    r = wildcmp("main.c", "m.*c");
    printf("%d\n", r);
    r = wildcmp("main.c", "**.*c");
    printf("%d\n", r);
    r = wildcmp("main-main.c", "ma*in.c");
    printf("%d\n", r);
    r = wildcmp("main", "main*d");
    printf("%d\n", r);
    r = wildcmp("abc", "*b");
    printf("%d\n", r);
    return (0);
}
alexa@ubuntu:~/0x1E-wild_cmp$ gcc -Wall -pedantic -Werror -Wextra 0-main.c 0-wildcmp.c -o 0-wildcmp
alexa@ubuntu:~/0x1E-wild_cmp$ ./0-wildcmp 
1
1
1
1
1
1
1
0
1
1
0
0
alexa@ubuntu:~/0x1E-wild_cmp$ 
```

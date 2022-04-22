#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void call_heap(int *array, size_t n, char *s)
{
    puts(s);
    print_array(array, n);
    printf("\n");
    heap_sort(array, n);
    printf("\n");
    print_array(array, n);
}

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int array0[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    int array1[] = {12, 11, 13, 5, 6, 7};
    int array2[] = {2, 8, 5, 3, 9, 1};

    call_heap(array0, sizeof(array0) / sizeof(array0[0]), "array0");
    call_heap(NULL, 0, "NULL array");
    call_heap(array1, sizeof(array1) / sizeof(array1[0]), "array1");
    call_heap(array2, sizeof(array2) / sizeof(array2[0]), "array2");
    return (0);
}

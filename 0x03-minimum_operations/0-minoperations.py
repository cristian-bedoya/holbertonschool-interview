#!/usr/bin/python3
"""
write a method that calculates the fewest number
of operations needed to result in exactly n H characters
in the file
"""


def count_process(number):
    """ Return list"""
    counter = 1
    list = []
    value = number
    while value != 1:
        counter += 1
        if value % counter == 0:
            while (value % counter == 0 and value != 1):
                value /= counter
                list.append(counter)

    return list


def minOperations(n):
    """ Return sum of process until n H """
    if n < 2 or type(n) is not int:
        return 0
    values = count_process(n)
    return sum(values)

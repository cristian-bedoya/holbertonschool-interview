#!/usr/bin/python3
"""Solution for rain problem
"""


def rain(walls):
    """
    Given a list of non-negative integers representing walls of width 1,
    calculate how much water will be retained after it rains
    Args:
        walls: a list of non-negative integers
    Returns:
        Integer indicating total amount of rainwater retained
    """
    i = maxleft = maxright = water = 0
    j = len(walls) - 1

    while i < j:
        if walls[i] < walls[j]:
            if walls[i] < maxleft:
                water += maxleft - walls[i]
            maxleft = max(maxleft, walls[i])
            i += 1
        else:
            if walls[j] < maxright:
                water += maxright - walls[j]
            maxright = max(maxright, walls[j])
            j -= 1

    return water

#!/usr/bin/python3
"""Write a method that determines if all the boxes can be opened.
    """


def canUnlockAll(boxes):
    """Determine if all the boxes can be unlocked."""
    j = boxes[0]
    for index in range(1, len(boxes)):
        if index in j:
            j += boxes[index]
    for index in range(1, len(boxes)):
        if index in j:
            j += boxes[index]
    list(set(j))
    b = 1
    for index in range(1, len(boxes)-1):
        if index not in j:
            b = 0
    if b == 1:
        return True
    else:
        return False

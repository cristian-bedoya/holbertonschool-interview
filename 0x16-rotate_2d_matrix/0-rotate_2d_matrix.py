#!/usr/bin/python3
"""Rotate 2D Matrix"""


def swap(matrix, i, j, e=None):
    """Swaps the values of an matrix
    """
    if not e:
        matrix[i][j] = matrix[i][j] * matrix[j][i]
        matrix[j][i] = matrix[i][j] // matrix[j][i]
        matrix[i][j] = matrix[i][j] // matrix[j][i]
    else:
        matrix[i][j] = matrix[i][j] * matrix[i][e]
        matrix[i][e] = matrix[i][j] // matrix[i][e]
        matrix[i][j] = matrix[i][j] // matrix[i][e]


def rotate_2d_matrix(matrix):
    """Rotates a matrix in place 90 degrees
    Args:
        matrix: 2d list of integers to rotate
    """
    for i in range(len(matrix)):
        for j in range(i + 1, len(matrix[i])):
            swap(matrix, i, j)

    for i in range(len(matrix)):
        s = 0
        e = len(matrix) - 1
        while s < e:
            swap(matrix, i, s, e)
            s += 1
            e -= 1

# 0x16. Rotate 2D Matrix

## Task
### [0. Rotate 2D Matrix ](./0-rotate_2d_matrix.py)
 0. Rotate 2D Matrix mandatory

Given an n x n 2D matrix, rotate it 90 degrees.

  -  Do not return anything. The matrix must be edited in-place.
  -  You can assume the matrix will have 2 dimensions and will not be empty.
```
jessevhedden$ cat main_0.py
#!/usr/bin/python3
"""
Test 0x16 - Rotate 2D Matrix
"""
rotate_2d_matrix = __import__('0-rotate_2d_matrix').rotate_2d_m
atrix

if __name__ == "__main__":
    matrix = [[1, 2, 3],
              [4, 5, 6],
              [7, 8, 9]]

    rotate_2d_matrix(matrix)
    print(matrix)

jessevhedden$
jessevhedden$ ./main_0.py
[[7, 4, 1],
[8, 5, 2],
[9, 6, 3]]
jessevhedden$
```
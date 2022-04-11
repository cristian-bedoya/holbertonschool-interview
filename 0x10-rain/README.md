# 0x10. Rain

## Task
### [0. Rain](./0-rain.py)
Given a list of non-negative integers representing walls of width 1, calculate how much water will be retained after it rains.
  -  Prototype: def rain(walls)
  -  walls is a list of non-negative integers.
  -  Return: Integer indicating total amount of rainwater retained.
  -  Assume that the ends of the list (before index 0 and after index walls[-1]) are not walls, meaning they will not retain water.
  -  If the list is empty return 0.
```
jesse@ubuntu:~/0x10$ cat 0_main.py
#!/usr/bin/python3
"""
0_main
"""
rain = __import__('0-rain').rain

if __name__ == "__main__":
    walls = [0, 1, 0, 2, 0, 3, 0, 4]
    print(rain(walls))

jesse@ubuntu:~/0x10$ 
jesse@ubuntu:~/0x10$ ./0_main.py
6
jesse@ubuntu:~/0x10$ 
```

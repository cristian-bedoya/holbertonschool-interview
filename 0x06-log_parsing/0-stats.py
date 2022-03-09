#!/usr/bin/python3
"""module docs"""
import sys


def handleTen(statCount, fileSize):
    print("File size: {}".format(fileSize))
    for key in sorted(statCount.keys()):
        if statCount[key] == 0:
            continue
        print("{}: {}".format(key, statCount[key]))


def log_parsing():
    """function docs"""
    c = size = 0
    counter = {"200": 0, "301": 0, "400": 0, "401": 0, "403": 0,
               "404": 0, "405": 0, "500": 0}

    try:
        for line in sys.stdin:
            c += 1
            split = line.split(" ")
            try:
                status = split[-2]
                size += int(split[-1])
                if status in counter:
                    counter[status] += 1
            except Exception:
                pass
            if c % 10 == 0:
                handleTen(counter, size)
        else:
            handleTen(counter, size)
    except (KeyboardInterrupt, SystemExit):
        handleTen(counter, size)
        raise


if __name__ == "__main__":
    log_parsing()

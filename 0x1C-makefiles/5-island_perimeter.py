#!/usr/bin/python3
"""Define a function for looking up island_perimeter"""


def island_perimeter(grid):
    """Returns the perimeter of the island"""
    d = 0
    lengt = len(grid) - 1
    widt = len(grid[0]) - 1

    for k, l in enumerate(grid):
        for m, e in enumerate(l):
            if e == 1:
                if k == 0 or grid[k - 1][m] != 1:
                    d += 1
                if m == 0 or grid[k][m - 1] != 1:
                    d += 1
                if m == widt or grid[k][m + 1] != 1:
                    d += 1
                if k == lengt or grid[k + 1][m] != 1:
                    d += 1
    return d

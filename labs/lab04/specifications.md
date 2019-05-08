# Maze Generator


## Problem
This purpose of this lab (# 4) is to generate a maze using an algorithm that
uses stacks.

## The Algorithm
A maze generation algorithm that utilizes stacks is the
[randomized depth-first search](https://en.wikipedia.org/wiki/Maze_generation_algorithm#Randomized_Depth-First_Search)
algorithm. 

### Pseudocode

The following is taken from the Wikipedia page linked to above:

1. Start with a grid that has no edges (all walls)
2. Make the initial cell the current cell
3. Push the current cell to the stack and mark it as visited
4. While the stack is not empty
    1. If the current cell has unvisited neighbors
        1. Choose one of these neighbors randomly
        2. Remove the wall (add an edge) between the current cell and the
           chosen neighbor
        3. Push the neighbor to the stack and mark it as visited
        4. make the neighbor the current cell
    2. Else
        1. Pop a cell from the stack and make it the current cell (i.e.,
           backtrack)

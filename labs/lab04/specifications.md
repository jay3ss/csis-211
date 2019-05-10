# Maze Generator


## Problem
This purpose of this lab (# 4) is to generate a maze using an algorithm that
uses stacks.

## Design

### Class-Responsibility-Collaboration (CRC) Cards

#### Cell Class

- Responsibilities
    - Knows state of cell (e.g., visited, unvisited)
    - Knows position

- Collaborators
    - State

#### Grid Class

- Responsibilities
    - Update a cell's state
    - Change the number of rows and columns
    - Change the state of the cells
    - Get the number of columns
    - Get the number of rows
    - Get the cell at an arbitrary position within the grid

- Collaborators
    - Cell
    - State

#### Maze Class

- Responsibilities
    - Know position of starting cell
    - Know position of ending cell
    - Know current position within maze
    - Change the state of the cells
    - Get the grid

- Collaborators
    - Cell
    - Grid
    - Stack
    - State

#### Stack Class

- Responsibilities
    - Push objects to stack
    - Pop objects from stack
    - Peek at the object at top of stack

- Collaborators
    - The class of objects that the stack can contain


### The Algorithm
A maze generation algorithm that utilizes stacks is the
[randomized depth-first search](https://en.wikipedia.org/wiki/Maze_generation_algorithm#Randomized_Depth-First_Search)
algorithm.

#### Pseudocode

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

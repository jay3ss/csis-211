#include <iostream>
#include "Grid.h"
#include "Maze.h"

using namespace std;

int main()
{
    // Maze maze(3, 3);
    Maze maze(37, 42);

    Grid grid = maze.getGrid();

    cout << "The grid is\n\n";

    cout << grid;
}

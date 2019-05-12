#include <iostream>
#include "Grid.h"
#include "Maze.h"

using namespace std;

int main()
{
    // Maze maze(3, 3);
    Maze maze(42, 37);

    Grid grid = maze.getGrid();
    cout << "The maze is\n\n";

    cout << maze << "\n\n";

    maze.setStart(3, 5);
    maze.setEnd(39, 22);

    const int *start = maze.getStart();
    const int *end = maze.getEnd();

    cout << "Starting coordinate is (" << start[0] << ", " << start[1] << ")\n";
    cout << "Ending coordinate is (" << end[0] << ", " << end[1] << ")\n\n";

    // Grid grid = maze.getGrid();
    grid = maze.getGrid();
    Cell c = grid.getCellAt(start[0], start[1]);

    cout << "Now the maze looks like\n\n" << maze << endl;
}

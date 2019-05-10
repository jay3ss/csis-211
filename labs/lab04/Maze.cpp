#include "Maze.h"

// Constructor
Maze::Maze(int c = 0,int r = 0) : numCols(c), numRows(r)
{
    grid = Grid(c, r);
}

// Destructor
Maze::~Maze()
{

}

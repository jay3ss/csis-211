#include "Maze.h"

// Constructor
Maze::Maze(int c, int r, bool randStart)
{
    grid = Grid(c, r);
    if (randStart)
    {
        randomStart();
    }
}

// Destructor
Maze::~Maze()
{

}

void Maze::initGrid()
{

}

void Maze::randomStart()
{

}

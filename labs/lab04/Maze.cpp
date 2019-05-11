#include "Maze.h"

// Constructor
Maze::Maze(int c, int r, bool randStart)
{
    grid = Grid(c, r);
    if (randStart)
    {
        randomStart();
    }
    initGrid();
}

// Destructor
Maze::~Maze()
{

}

void Maze::initGrid()
{
    std::vector<std::vector<Cell>> gVector = grid.vector();

    for (int i = 0; i < grid.getNumRows(); i++)
    {
        for (int j = 0; j < grid.getNumCols(); j++)
        {
            if (j == 0 || i == 0 || j == (grid.getNumCols() - 1) || i == (grid.getNumRows() - 1))
            {
                Cell c = gVector[j][i];
                c = cell::State::OCCUPIED;
                grid.setCell(c);
            }
        }
    }
}

void Maze::randomStart()
{

}

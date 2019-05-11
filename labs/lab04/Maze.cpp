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

bool Maze::isWall(Cell c)
{
    return c.getState() == cell::State::OCCUPIED;
}

bool Maze::isOuterWall(int x, int y)
{
    // if (isNorthWall(y) || isEastWall(x)
    //  || isSouthWall(y) || isWestWall(x))
    // {
    //     return true;
    // }

    // return false;

    return (isNorthWall(y) || isEastWall(x) || isSouthWall(y) || isWestWall(x));
}

bool Maze::isNorthWall(int y)
{
    return y == 0;
}

bool Maze::isSouthWall(int y)
{
    return y == (grid.getNumRows() - 1);
}

bool Maze::isEastWall(int x)
{
    return x == (grid.getNumCols() - 1);
}

bool Maze::isWestWall(int x)
{
    return x == 0;
}

void Maze::initGrid()
{
    std::vector<std::vector<Cell>> gVector = grid.vector();

    for (int i = 0; i < grid.getNumRows(); i++)
    {
        for (int j = 0; j < grid.getNumCols(); j++)
        {
            if (isOuterWall(j, i))
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

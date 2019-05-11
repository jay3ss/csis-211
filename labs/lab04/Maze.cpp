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
    int numCols = grid.getNumCols();
    int numRows = grid.getNumRows();

    // Make the north wall occupied
    for (int i = 0; i < numCols; i++)
    {
        Cell c = gVector[i][0];
        c.setState(cell::State::OCCUPIED);
        grid.setCell(c);
    }

    // Make the south wall occupied
    for (int i = 0; i < grid.getNumCols(); i++)
    {
        Cell c = gVector[i][numRows - 1];
        c.setState(cell::State::OCCUPIED);
        grid.setCell(c);
    }

    // Make the east wall occupied
    for (int i = 0; i < numRows; i++)
    {
        Cell c = gVector[numCols - 1][i];
        c.setState(cell::State::OCCUPIED);
        grid.setCell(c);
    }

    // Make the west wall occupied
    for (int i = 0; i < numRows; i++)
    {
        Cell c = gVector[0][i];
        c.setState(cell::State::OCCUPIED);
        grid.setCell(c);
    }
}

void Maze::randomStart()
{

}

#include "Maze.h"

// Constructor
Maze::Maze(int c, int r, bool randStart)
{
    grid = Grid(c, r);
    initGrid();
    seedRandGen();

    if (randStart)
    {
        randomStart();
    }
}

// Destructor
Maze::~Maze()
{

}

// Fill the contents of the passed in array with the neighbors of cell in the
// following order: [north, east, south, west]
void Maze::getCellNeighbors(Cell c, Cell cells[])
{
    int x = c.getXPosition();
    int y = c.getXPosition();
    // Get neighbors to the north, east, south, and west of cell (c)
    cells[0] = grid.getCellAt(x + 1, y);    // North neighbor
    cells[1] = grid.getCellAt(x, y + 1);    // East neighbor
    cells[2] = grid.getCellAt(x - 1, y);    // South neighbor
    cells[3] = grid.getCellAt(x, y - 1);    // West neighbor
}

void Maze::setStart(const int x, const int y)
{
    start[0] = x;
    start[1] = y;

    Cell c = grid.getCellAt(x, y);
    c.setState(cell::State::START);
    grid.setCell(c);
}

void Maze::setEnd(const int x, const int y)
{
    end[0] = x;
    end[1] = y;

    Cell c = grid.getCellAt(x, y);
    c.setState(cell::State::END);
    grid.setCell(c);
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

bool Maze::isStart(int x, int y)
{
    return (x == start[0] && y == start[1]);
}

bool Maze::isEnd(int x, int y)
{
    return (x == end[0] && y == end[1]);
}

void Maze::initGrid()
{
    std::vector<std::vector<Cell>> gVector = grid.vector();
    int numCols = grid.getNumCols();
    int numRows = grid.getNumRows();

    // Make the north and south walls occupied
    for (int i = 0; i < numCols; i++)
    {
        Cell cNorth = gVector[i][0];
        cNorth.setState(cell::State::OCCUPIED);
        grid.setCell(cNorth);

        Cell cSouth = gVector[i][numRows - 1];
        cSouth.setState(cell::State::OCCUPIED);
        grid.setCell(cSouth);
    }

    // Make the east and west walls occupied
    for (int i = 0; i < numRows; i++)
    {
        Cell cEast = gVector[numCols - 1][i];
        cEast.setState(cell::State::OCCUPIED);
        grid.setCell(cEast);

        Cell cWest = gVector[0][i];
        cWest.setState(cell::State::OCCUPIED);
        grid.setCell(cWest);
    }
}

// Initialize random number engine
void Maze::seedRandGen()
{
    std::mt19937 randNumGen(seed());
    std::uniform_int_distribution<int> uniIntDist(0, 3);
}

void Maze::randomStart()
{
    std::mt19937 randNumGen(seed());
    // numCols - 2 so that the start point isn't in the east or west walls
    std::uniform_int_distribution<int> xDist(1, grid.getNumCols() - 2);
    // numRows - 2 so that the start point isn't in the north or south walls
    std::uniform_int_distribution<int> yDist(1, grid.getNumRows() - 2);
    setStart(xDist(randNumGen), yDist(randNumGen));
    setEnd(xDist(randNumGen), yDist(randNumGen));
}

Cell Maze::getRandomNeighbor(Cell c)
{
    int x = c.getXPosition();
    int y = c.getYPosition();

    maze::Direction directions[] = {
        maze::Direction::NORTH,
        maze::Direction::EAST,
        maze::Direction::SOUTH,
        maze::Direction::WEST
    };

    std::mt19937 randNumGen(seed());
    std::uniform_int_distribution<int> uniIntDist(0, 3);
    int randomInt = uniIntDist(randNumGen);
    std::cout << "Random int is " << randomInt << std::endl;
    maze::Direction randomDirection = directions[randomInt];

    Cell randomNeighbor;
    switch (randomDirection)
    {
    case maze::Direction::NORTH:
        randomNeighbor = grid.getCellAt(x, y - 1);
        break;
    case maze::Direction::EAST:
        randomNeighbor = grid.getCellAt(x + 1, y);
        break;
    case maze::Direction::SOUTH:
        randomNeighbor = grid.getCellAt(x, y + 1);
        break;
    // maze::Direction::WEST
    default:
        randomNeighbor = grid.getCellAt(x - 1, y);
        break;
    }

    return randomNeighbor;
}

// Overloaded operators
std::ostream &operator<<(std::ostream &strm, const Maze &obj)
{
    strm << obj.grid;
    return strm;
}

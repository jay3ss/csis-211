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

// A maze generation algorithm that utilizes stacks is the randomized depth-first search algorithm.
// Pseudocode
//
// The following is taken from the Wikipedia page linked to above:
//
//     1. Start with a grid that has no edges (all walls)
//     2. Make the initial cell the current cell
//     3. Push the current cell to the stack and mark it as visited
//     4. While the stack is not empty
//         a. If the current cell has unvisited neighbors
//             1. Choose one of these neighbors randomly
//             2. Remove the wall (add an edge) between the current cell and the chosen neighbor
//             3. Push the neighbor to the stack and mark it as visited
//             4. make the neighbor the current cell
//         b. Else
//             1. Pop a cell from the stack and make it the current cell (i.e., backtrack)
// Notes:
// - a visited cell is a cell whose state is not UNVISITED (not counting
//   START and END)
// - an occupied cell is a cell whose state is either OCCUPIED or NONE
void Maze::generate()
{
    // // Start at the starting point and set its state to UNOCCUPIED
    // Cell currCell = getStart();
    // currCell.setState(cell::State::UNOCCUPIED); // Mark as visited

    // stack.push(currCell);

    // std::vector<maze::Direction> directions = {
    //     maze::Direction::NORTH,
    //     maze::Direction::EAST,
    //     maze::Direction::SOUTH,
    //     maze::Direction::WEST
    // };


    // // Randomly shuffle the vector
    // std::random_shuffle(directions.begin(), directions.end());
    // maze::Direction direction;

    // int count = 0;
    // while (!stack.isEmpty())
    // {

    //     if (count != directions.size())
    //     {
    //         direction = directions[count];
    //         count++;
    //     }
    //     else
    //     {
    //         count = 0;
    //     }


    //     // if (hasUnvisitedNeighbors(c))
    //     // {
    //     //
    //     // }
    // }
    Cell startCell = getStart();
    // Mark the cell as visited & push it to the stack
    startCell.setState(cell::State::UNOCCUPIED);

    Cell topCell = stack.peek();
    while (!stack.isEmpty())
    {
        Cell nextCell = getRandomNeighbor(topCell);

        if (!nextCell.isUnvisited())
        {
            stack.pop();
        }
        else
        {
            stack.push(nextCell);
            nextCell.setState(getRandomState());
        }

        if (!stack.isEmpty())
        {
            topCell = stack.peek();
        }
    }
}

// Checks if there are any unvisited neighboring cells. Returns true if there
// are any unvisited neighboring cells, false otherwise
bool Maze::hasUnvisitedNeighbors(Cell c)
{
    int xPos = c.getXPosition();
    int yPos = c.getYPosition();
    // Check the neighbors one-by-one
    // Check the neighbor to the north
    Cell neighbor = getCellAt(xPos, yPos + 1);

    if (neighbor.isUnvisited())
    {
        return true;
    }

    // Check the neighbor to the east
    neighbor = getCellAt(xPos + 1, yPos);

    if (neighbor.isUnvisited())
    {
        return true;
    }

    // Check the neighbor to the south
    neighbor = getCellAt(xPos, yPos - 1);

    if (neighbor.isUnvisited())
    {
        return true;
    }

    // Check the neighbor to the west
    neighbor = getCellAt(xPos - 1, yPos);

    if (neighbor.isUnvisited())
    {
        return true;
    }

    return false;
}

cell::State Maze::getRandomState() const
{

    std::vector<cell::State> states = {
        cell::State::OCCUPIED, cell::State::UNOCCUPIED
    };

    std::random_shuffle(states.begin(), states.end());

    return states[0];

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

int Maze::generateRandomNumber(int min, int max)
{
    return (rand() % (max - min + 1)) + min;
}

// Seed random number engine
void Maze::seedRandGen()
{
    std::srand(SEED);
}

void Maze::randomStart()
{
    // Take care not to place the start/end point outside of the grid or on
    // the wall by using the following formulae:
    //
    // numCols - 2 so that the start point isn't in the east or west walls
    // numRows - 2 so that the start point isn't in the north or south walls
    int randX = generateRandomNumber(1, grid.getNumCols() - 2);
    int randY = generateRandomNumber(1, grid.getNumRows() - 2);
    setStart(randX, randY);

    randX = generateRandomNumber(1, grid.getNumCols() - 2);
    randY = generateRandomNumber(1, grid.getNumRows() - 2);
    setEnd(randX, randY);
}

Cell Maze::getRandomNeighbor(Cell c)
{
    int x = c.getXPosition();
    int y = c.getYPosition();

    std::vector<maze::Direction> directions = {
        maze::Direction::NORTH,
        maze::Direction::EAST,
        maze::Direction::SOUTH,
        maze::Direction::WEST
    };


    // int randomInt = generateRandomNumber(0, 3);
    // maze::Direction randomDirection = directions[randomInt];

    std::random_shuffle(directions.begin(), directions.end());

    // Cycle through the directions vector until an unvisited cell is found
    // If an unvisited cell is found, return it. If an unvisited cell cannot
    // be found, then return the last cell
    maze::Direction randomDirection;
    Cell randomNeighbor;
    for (int i = 0; i < directions.size(); i++)
    {
        randomDirection = directions[i];
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

        if (randomNeighbor.isUnoccupied())
        {
            return randomNeighbor;
        }
    }

    return randomNeighbor;
}

// Overloaded operators
std::ostream &operator<<(std::ostream &strm, const Maze &obj)
{
    strm << obj.grid;
    return strm;
}


// For debugging
// char stateToChar(cell::State state)
// {
//     char c;
//     switch (state)
//     {
//     case cell::State::OCCUPIED:
//         c = '#';
//         break;
//     default:
//         c = ' ';
//         break;
//     }
//     return c;
// }

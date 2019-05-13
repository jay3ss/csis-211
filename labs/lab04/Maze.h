#ifndef _MAZE_H
#define _MAZE_H

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <random>
#include <vector>
#include "Cell.h"
#include "Grid.h"
#include "LinkedStack.h"

namespace maze
{
    enum class Direction { NORTH, EAST, SOUTH, WEST };
}

class Maze
{
public:
    // Constructor
    Maze(int c = 1, int r = 1, bool randStart = true);

    // Destructor
    ~Maze() {}

    // Accessors
    Grid getGrid() { return grid; }

    Cell getStart() { return grid.getCellAt(start[0], start[1]); }
    Cell getEnd() { return grid.getCellAt(end[0], end[1]); }
    Cell getCellAt(int x, int y) { return grid.getCellAt(x, y); }
    void getCellNeighbors(Cell c, Cell cells[]);
    int getSeed() const { return SEED; }

    // Maze generation-related functions
    void generate();
    bool hasUnvisitedNeighbors(Cell c);
    cell::State getRandomState() const;

    // Wall-/cell-related functions
    bool isWall(Cell c);
    bool isOuterWall(int x, int y);
    bool isNorthWall(int y);
    bool isSouthWall(int y);
    bool isEastWall(int x);
    bool isWestWall(int x);
    bool isStart(int x, int y);
    bool isEnd(int x, int y);


    // Mutators
    void setStart(const int x, const int y);
    void setEnd(const int x, const int y);
    void setCell(Cell cell);

    // Function to get a random neighbor, if possible
    Cell getRandomNeighbor(Cell c);
    // Overloaded operators
    friend std::ostream &operator<<(std::ostream &strm, const Maze &obj);
private:
    LinkedStack<Cell> stack;
    Grid grid;
    int start[2];
    int end[2];

    // Initialize grid with outer cells as occupied (walls)
    void initGrid();

    // Random number generation
    int generateRandomNumber(int min, int max);
    void seedRandGen();
    void randomStart();

    // Seed for the random number generator
    const unsigned SEED = std::time(0);
};

#endif // _MAZE_H

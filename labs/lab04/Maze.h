#ifndef _MAZE_H
#define _MAZE_H

#include <random>
#include <vector>
#include "Cell.h"
#include "Grid.h"

class Maze
{
public:
    // Constructor
    Maze(int c = 1, int r = 1, bool randStart = false);

    // Destructor
    ~Maze();

    // Accessors
    Grid getGrid() { return grid; }

    const int *getStart() const { return start; }
    const int *getEnd() const { return end; }
    Cell getCellAt(int x, int y) { return grid.getCellAt(x, y); }
    void getCellNeighbors(Cell c, Cell cells[]);

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

    // Overloaded operators
    friend std::ostream &operator<<(std::ostream &strm, const Maze &obj);
private:
    Grid grid;
    int start[2];
    int end[2];

    // Initialize grid with outer cells as occupied (walls)
    void initGrid();
    void seedRandGen();
    void randomStart();

    std::random_device seed; // to initialize (seed) the engine
    std::mt19937 randNumGen;
    std::uniform_int_distribution<int> uniIntDist;
};

#endif // _MAZE_H

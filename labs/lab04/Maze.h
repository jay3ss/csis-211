#ifndef _MAZE_H
#define _MAZE_H

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

    bool isWall(Cell c);
    bool isOuterWall(int x, int y);
    bool isNorthWall(int y);
    bool isSouthWall(int y);
    bool isEastWall(int x);
    bool isWestWall(int x);


    // Mutators
    void setStart(const int x, const int y);
    void setEnd(const int x, const int y) { end [0] = x; end[1]; }

private:
    Grid grid;
    int start[2];
    int end[2];

    // Initialize grid with outer cells as occupied (walls)
    void initGrid();
    void randomStart();
};

#endif // _MAZE_H

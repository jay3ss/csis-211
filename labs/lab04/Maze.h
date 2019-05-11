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

    // Mutators

private:
    Grid grid;

    void randomStart();
};

#endif // _MAZE_H

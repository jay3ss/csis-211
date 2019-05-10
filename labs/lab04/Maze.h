#ifndef _MAZE_H
#define _MAZE_H

#include <vector>
#include "Cell.h"
#include "Grid.h"

class Maze
{
public:
    // Constructor
    Maze(int c = 1, int r = 1)
        { grid = Grid(c, r); }

    // Destructor
    ~Maze();
private:
    Grid grid;
};

#endif // _MAZE_H

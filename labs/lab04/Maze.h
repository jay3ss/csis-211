#ifndef _MAZE_H
#define _MAZE_H

#include <vector>
#include "Cell.h"
#include "Grid.h"

class Maze
{
public:
    // Constructor
    Maze(int, int);

    // Destructor
    ~Maze();
private:
    int numCols;
    int numRows;

    Grid grid;
};

#endif // _MAZE_H

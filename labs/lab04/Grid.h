#ifndef _GRID_H
#define _GRID_H

#include <iostream>
#include <vector>
#include "Cell.h"

class Grid
{
public:
    // Constructor
    Grid(int c = 1, int r = 1) : numCols(c), numRows(r)
        { init(); }

    // Destructor
    ~Grid() {}

    // Accessors
    int getNumCols() const { return numCols; }
    int getNumRows() const { return numRows; }
    Cell getCellAt(int x, int y);

    std::vector<std::vector<Cell>> vector() const { return cells; }

    bool isOutOfBounds(int x, int y);

    // Mutators
    void resize(int, int);
    void setCell(Cell c);

    // Overloaded operators
    friend std::ostream &operator<<(std::ostream &strm, const Grid &obj);
private:
    int numCols;
    int numRows;

    std::vector<std::vector<Cell>> cells;

    void init();
};

#endif // _GRID_H
